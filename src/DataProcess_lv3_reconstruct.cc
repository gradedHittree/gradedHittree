#include "DataProcess_lv3_reconstruct.hh"

using namespace anl;

namespace hittree_gen 
{

DataProcess_lv3_reconstruct::DataProcess_lv3_reconstruct()
{
}

void DataProcess_lv3_reconstruct::doProcessing(){
    eventData_lv3->ResetData();
    nhit = 0;

    while(eventData_lv2->get_nsignal() != 0){
        initialize();

        nsignal = eventData_lv2->get_nsignal();

        for(int isignal = 0; isignal < nsignal; ++isignal){
            if(isignal == 0){
                fill_signal_into_vector(isignal);
            }else if(detid == eventData_lv2->get_detid(isignal)){
                fill_signal_into_vector(isignal);
            }
        }

        reconstruct();
        delete_signal();
    }
}

void DataProcess_lv3_reconstruct::reconstruct(){//you can change this method
    sort(order_epi_0V.begin(),order_epi_0V.end(),DataProcess_lv3_reconstruct::sort_epi_descend);
    sort(order_epi_HV.begin(),order_epi_HV.end(),DataProcess_lv3_reconstruct::sort_epi_descend);
    
    for(int i0V=0;i0V<epi_0V.size();i0V++){
      	int j0V = order_epi_0V[i0V].first;
        for(int iHV=0;iHV<epi_HV.size();iHV++){
    	    int jHV = order_epi_HV[iHV].first;
    	    if(isConsistent(epi_0V[j0V],epi_HV[jHV]) && fill_0V[j0V]==0 && fill_HV[jHV]==0){
	        if(delta_x_0V[j0V] > 0){
                    reconstructed_pos_x = pos_x_0V[j0V];
                    reconstructed_delta_x = delta_x_0V[j0V];
                    reconstructed_pos_y = pos_y_HV[jHV];
                    reconstructed_delta_y = delta_y_HV[jHV];
                    reconstructed_pos_z = pos_z_HV[jHV];
		    reconstructed_delta_z = delta_z_HV[jHV];
                }else{
                    reconstructed_pos_x = pos_x_HV[jHV];
                    reconstructed_delta_x = delta_x_HV[jHV];
                    reconstructed_pos_y = pos_y_0V[j0V];
                    reconstructed_delta_y = delta_y_0V[j0V];
                    reconstructed_pos_z = pos_z_HV[jHV];
		    reconstructed_delta_z = delta_z_HV[jHV];
                }
		reconstructed_epi = calc_reconstructed_epi(epi_0V[j0V],epi_HV[jHV]);
                set_reconstructed_signal();

                fill_0V[j0V] = 1;
		fill_HV[jHV] = 1;	
            }
        }//for iHV
    }//fpr i0V
}//

bool DataProcess_lv3_reconstruct::isConsistent(const double e0V,const double eHV){
    bool isconsis = false;
    if(fabs(e0V-eHV)<=3.0 || fabs(e0V-eHV)<=eHV*0.15)isconsis = true;
  
    return isconsis;
}

bool DataProcess_lv3_reconstruct::sort_epi_descend(const std::pair<int, double> &left, const std::pair<int, double> &right){
    return left.second > right.second;
}

double DataProcess_lv3_reconstruct::calc_reconstructed_epi(const double e0V, const double eHV){//you can change this method
    double epi_new = eHV;
    return epi_new;
}//
  
void DataProcess_lv3_reconstruct::fill_signal_into_vector(int i){
    filled_signal_index.push_back(i);

    if(eventData_lv2->get_detector_HV(i) == 0){
        pos_x_0V.push_back(eventData_lv2->get_pos_x(i));
        pos_y_0V.push_back(eventData_lv2->get_pos_y(i));
        pos_z_0V.push_back(eventData_lv2->get_pos_z(i));
        delta_x_0V.push_back(eventData_lv2->get_delta_x(i));
        delta_y_0V.push_back(eventData_lv2->get_delta_y(i));
        delta_z_0V.push_back(eventData_lv2->get_delta_z(i));
        epi_0V.push_back(eventData_lv2->get_epi(i));

	fill_0V.push_back(0);
	order_epi_0V.push_back(std::pair<int, double>(order_epi_0V.size(),eventData_lv2->get_epi(i)));
    }else{
        pos_x_HV.push_back(eventData_lv2->get_pos_x(i));
        pos_y_HV.push_back(eventData_lv2->get_pos_y(i));
        pos_z_HV.push_back(eventData_lv2->get_pos_z(i));
        delta_x_HV.push_back(eventData_lv2->get_delta_x(i));
        delta_y_HV.push_back(eventData_lv2->get_delta_y(i));
        delta_z_HV.push_back(eventData_lv2->get_delta_z(i));
        epi_HV.push_back(eventData_lv2->get_epi(i));

	fill_HV.push_back(0);
	order_epi_HV.push_back(std::pair<int, double>(order_epi_HV.size(),eventData_lv2->get_epi(i)));
    }
}

void DataProcess_lv3_reconstruct::initialize(){
    filled_signal_index.clear();

    detid =  eventData_lv2->get_detid(0);
    detector_material = eventData_lv2->get_detector_material(0);

    pos_x_0V.clear();
    pos_y_0V.clear();
    pos_z_0V.clear();
    delta_x_0V.clear();
    delta_y_0V.clear();
    delta_z_0V.clear();
    epi_0V.clear();
    
    pos_x_HV.clear();
    pos_y_HV.clear();
    pos_z_HV.clear();
    delta_x_HV.clear();
    delta_y_HV.clear();
    delta_z_HV.clear();
    epi_HV.clear();

    fill_0V.clear();
    fill_HV.clear();
    order_epi_0V.clear();
    order_epi_HV.clear();
    
    reconstructed_pos_x = 0;
    reconstructed_pos_y = 0;
    reconstructed_pos_z = 0;
    reconstructed_delta_x = 0;
    reconstructed_delta_y = 0;
    reconstructed_delta_z = 0;
    reconstructed_epi = 0;
}

void DataProcess_lv3_reconstruct::set_reconstructed_signal(){
    nhit++;

    eventData_lv3->set_nhit(nhit);
    eventData_lv3->set_detid(detid);
    eventData_lv3->set_detector_material(detector_material);
    eventData_lv3->set_pos_x(reconstructed_pos_x);
    eventData_lv3->set_pos_y(reconstructed_pos_y);
    eventData_lv3->set_pos_z(reconstructed_pos_z);
    eventData_lv3->set_delta_x(reconstructed_delta_x);
    eventData_lv3->set_delta_y(reconstructed_delta_y);
    eventData_lv3->set_delta_z(reconstructed_delta_z);
    eventData_lv3->set_epi(reconstructed_epi);
}

void DataProcess_lv3_reconstruct::delete_signal(){
    for(auto itr = filled_signal_index.rbegin(); itr != filled_signal_index.rend(); ++itr){
        eventData_lv2->deleteSignal(*itr);
    }
}

} /* namespace hittree_gen*/
