#include "DataProcess_lv2_merge.hh"

using namespace anl;

namespace hittree_gen 
{

DataProcess_lv2_merge::DataProcess_lv2_merge()
    :th_si_0V(0),
     th_si_HV(0),
     th_cdte_0V(0),
     th_cdte_HV(0)
{
  hist_distx_epi = new TH1D("hist_distx_epi", "hist_distx_epi;pos_x;epi", 1000, -0.005, -9.995);//1bin = 0.01mm
  hist_disty_epi = new TH1D("hist_disty_epi", "hist_disty_epi;pos_y;epi", 1000, -0.005, -9.995);
  hist_distz_epi = new TH1D("hist_distz_epi", "hist_distz_epi;pos_z;epi", 1000, -0.005, -9.995);
}

ANLStatus DataProcess_lv2_merge::mod_startup()
{
  register_parameter(&th_si_0V, "Threshold_Si_0V");
  register_parameter(&th_si_HV, "Threshold_Si_HV");
  register_parameter(&th_cdte_0V, "Threshold_CdTe_0V");
  register_parameter(&th_cdte_HV, "Threshold_CdTe_HV");

  DataProcess_lv2_base::mod_startup();
}

void DataProcess_lv2_merge::doProcessing(){
    eventData_lv2->ResetData();
    nsignal_lv2 = 0;

    extract_signal_over_threshold();

    while(eventData_lv1->get_nsignal() > 0){
        initialize();

        nsignal = eventData_lv1->get_nsignal();

        for(int isignal = 0; isignal < nsignal; ++isignal){

	    if(isignal == 0){

	      fill_signal_into_vector(isignal);

            }else if(isAdjacent(isignal)){

	      fill_signal_into_vector(isignal);

	    }
	    //std::cout << isignal << "/" << nsignal << std::endl;
        }
        merge();
        set_merged_signal();
        delete_signal();

    }
    //std::cout << "end of entry" << std::endl;
}

// Users should write this function !!! 
void DataProcess_lv2_merge::merge(){
    n_merged_signal = (int)detch.size();
    //n_merged_signal = (int)hist_distx_epi->GetEntries();
    //std::cout << hist_distx_epi->GetEntries() << std::endl;
    merged_epi = (double)hist_distx_epi->Integral();
    merged_pos_x = (double)hist_distx_epi->GetMean();
    merged_pos_y = (double)hist_disty_epi->GetMean();
    merged_pos_z = (double)hist_distz_epi->GetMean();
    merged_delta_x = delta_x[0];
    merged_delta_y = delta_y[0];
    merged_delta_z = delta_z[0];

    if(hist_distx_epi->GetEntries()!=1)merged_delta_x = (double)hist_distx_epi->GetRMS();
    if(hist_disty_epi->GetEntries()!=1)merged_delta_y = (double)hist_disty_epi->GetRMS();
    if(hist_distz_epi->GetEntries()!=1)merged_delta_z = (double)hist_distz_epi->GetRMS();

}
// 

void DataProcess_lv2_merge::extract_signal_over_threshold(){
    int n = eventData_lv1->get_nsignal();
    for(int i = n-1; i >= 0; --i){        
        double _epi = eventData_lv1->get_epi(i);
	double _ethre = eventData_lv1->get_ethre(i);
        if(_ethre>0 && _epi<_ethre)eventData_lv1->deleteSignal(i);
    }
}

bool DataProcess_lv2_merge::isAdjacent(int i){
    if( detid ==  eventData_lv1->get_detid(i)
    &&  detector_material == eventData_lv1->get_detector_material(i)
    &&  detector_HV == eventData_lv1->get_detector_HV(i)
    ){
        int _detch = eventData_lv1->get_detch(i);
        for(auto itr = detch.begin(); itr != detch.end(); ++itr){
            if(*itr == _detch + 1 || *itr == _detch -1){
                return true;
            }
        }
        return false;
    }
    return false;
}

void DataProcess_lv2_merge::fill_signal_into_vector(int i){
    filled_signal_index.push_back(i);
    
    detch.push_back(eventData_lv1->get_detch(i));
    pos_x.push_back(eventData_lv1->get_pos_x(i));
    pos_y.push_back(eventData_lv1->get_pos_y(i));
    pos_z.push_back(eventData_lv1->get_pos_z(i));
    delta_x.push_back(eventData_lv1->get_delta_x(i));
    delta_y.push_back(eventData_lv1->get_delta_y(i));
    delta_z.push_back(eventData_lv1->get_delta_z(i));
    epi.push_back(eventData_lv1->get_epi(i));
    
    double temp_pos_x = eventData_lv1->get_pos_x(i);
    double temp_pos_y = eventData_lv1->get_pos_y(i);
    double temp_pos_z = eventData_lv1->get_pos_z(i);
    if(i==0){
      hist_distx_epi->SetBins(1000,temp_pos_x-5.-0.005,temp_pos_x+5.-0.005);//1bin = 0.01mm
      hist_disty_epi->SetBins(1000,temp_pos_y-5.-0.005,temp_pos_y+5.-0.005);
      hist_distz_epi->SetBins(1000,temp_pos_z-5.-0.005,temp_pos_z+5.-0.005);
    }
    //int binx = hist_distx_epi->FindBin(temp_pos_x);
    //int biny = hist_disty_epi->FindBin(temp_pos_y);
    //int binz = hist_distz_epi->FindBin(temp_pos_z);
    hist_distx_epi->Fill(temp_pos_x,eventData_lv1->get_epi(i));
    hist_disty_epi->Fill(temp_pos_y,eventData_lv1->get_epi(i));
    hist_distz_epi->Fill(temp_pos_z,eventData_lv1->get_epi(i));

    detid =  eventData_lv1->get_detid(i);
    remapch = eventData_lv1->get_remapch(i);
    detector_material = eventData_lv1->get_detector_material(i);
    detector_HV = eventData_lv1->get_detector_HV(i);
}

void DataProcess_lv2_merge::initialize(){
    filled_signal_index.clear();

    detch.clear();

    pos_x.clear();
    pos_y.clear();
    pos_z.clear();

    delta_x.clear();
    delta_y.clear();
    delta_z.clear();

    epi.clear();

    hist_distx_epi->Reset();
    hist_disty_epi->Reset();
    hist_distz_epi->Reset();
    
    merged_pos_x = 0;
    merged_pos_y = 0;
    merged_pos_z = 0;
    merged_delta_x = 0;
    merged_delta_y = 0;
    merged_delta_z = 0;
    merged_epi = 0;

    detid =  eventData_lv1->get_detid(0);
    remapch = eventData_lv1->get_remapch(0);
    detector_material = eventData_lv1->get_detector_material(0);
    detector_HV = eventData_lv1->get_detector_HV(0);
}

void DataProcess_lv2_merge::set_merged_signal(){
    nsignal_lv2++;

    eventData_lv2->set_nsignal(nsignal_lv2);
    eventData_lv2->set_detid(detid);
    eventData_lv2->set_detector_material(detector_material);
    eventData_lv2->set_detector_HV(detector_HV);
    eventData_lv2->set_n_merged_signal(n_merged_signal);
    eventData_lv2->set_pos_x(merged_pos_x);
    eventData_lv2->set_pos_y(merged_pos_y);
    eventData_lv2->set_pos_z(merged_pos_z);
    eventData_lv2->set_delta_x(merged_delta_x);
    eventData_lv2->set_delta_y(merged_delta_y);
    eventData_lv2->set_delta_z(merged_delta_z);
    eventData_lv2->set_epi(merged_epi);

    //if(n_merged_signal>0)std::cout << "@DataProcess_lv2_merge : " << n_merged_signal << std::endl;
    //if(n_merged_signal>0)std::cout << "@DataProcess_lv2_merge : " << eventData_lv2->get_n_merged_signal(nsignal_lv2-1) << std::endl;
}

void DataProcess_lv2_merge::delete_signal(){
    for(auto itr = filled_signal_index.rbegin(); itr != filled_signal_index.rend(); ++itr){
        eventData_lv1->deleteSignal(*itr);
    }
}

} /* namespace hittree_gen*/
