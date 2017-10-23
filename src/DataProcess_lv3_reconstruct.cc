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
    if(epi_0V.size()==1 && epi_HV.size()==1){
      
        reconstruct_1_1hit();
	
    }else if(epi_0V.size()==1 && epi_HV.size()==2){
      
        reconstruct_1_2hit();
	
    }else if(epi_0V.size()==2 && epi_HV.size()==1){
      
        reconstruct_2_1hit();
	
    }else if(epi_0V.size()==2 && epi_HV.size()==2){
      
        reconstruct_2_2hit();
	
    }else{
      
        reconstruct_multihit();
	
    }
}//
void DataProcess_lv3_reconstruct::reconstruct_1_1hit(){
    if(isConsistent(epi_0V[0],epi_HV[0])){
      
        double epi = calc_reconstructed_epi(epi_0V[0],epi_HV[0]);
	
        if(delta_x_0V[0] > 0){
	  
            set_signal(pos_x_0V[0],delta_x_0V[0],pos_y_HV[0],delta_y_HV[0],pos_z_HV[0],delta_z_HV[0],epi);
	    
        }else{
	  
	    set_signal(pos_x_HV[0],delta_x_HV[0],pos_y_0V[0],delta_y_0V[0],pos_z_HV[0],delta_z_HV[0],epi);
	    
        }
    }
}
void DataProcess_lv3_reconstruct::reconstruct_2_1hit(){
    double epi_0V_total = epi_0V[0]+epi_0V[1];
    double epi_HV_total = epi_HV[0];
  
    if(delta_x_0V[0] > 0){
      
        if(isConsistent(epi_0V_total,epi_HV_total)){
	  
            set_signal(pos_x_0V[0],delta_x_0V[0],pos_y_HV[0],delta_y_HV[0],pos_z_HV[0],delta_z_HV[0],epi_0V[0]);
            set_signal(pos_x_0V[1],delta_x_0V[1],pos_y_HV[0],delta_y_HV[0],pos_z_HV[0],delta_z_HV[0],epi_0V[1]);
	    
        }
    }else{
      
        if(isConsistent(epi_0V_total,epi_HV_total)){
	  
            set_signal(pos_x_HV[0],delta_x_HV[0],pos_y_0V[0],delta_y_0V[0],pos_z_HV[0],delta_z_HV[0],epi_0V[0]);
            set_signal(pos_x_HV[1],delta_x_HV[1],pos_y_0V[0],delta_y_0V[0],pos_z_HV[0],delta_z_HV[0],epi_0V[1]);
	    
        }
    }
}
void DataProcess_lv3_reconstruct::reconstruct_1_2hit(){
    double epi_0V_total = epi_0V[0];
    double epi_HV_total = epi_HV[0]+epi_HV[1];
  
    if(delta_x_0V[0] > 0){
      
        if(isConsistent(epi_0V_total,epi_HV_total)){
	  
            set_signal(pos_x_0V[0],delta_x_0V[0],pos_y_HV[0],delta_y_HV[0],pos_z_HV[0],delta_z_HV[0],epi_HV[0]);
            set_signal(pos_x_0V[0],delta_x_0V[0],pos_y_HV[1],delta_y_HV[1],pos_z_HV[0],delta_z_HV[0],epi_HV[1]);
	    
        }
    }else{
      
        if(isConsistent(epi_0V_total,epi_HV_total)){
	  
            set_signal(pos_x_HV[0],delta_x_HV[0],pos_y_0V[0],delta_y_0V[0],pos_z_HV[0],delta_z_HV[0],epi_HV[0]);
            set_signal(pos_x_HV[0],delta_x_HV[0],pos_y_0V[1],delta_y_0V[1],pos_z_HV[0],delta_z_HV[0],epi_HV[1]);
	    
        }
    }
}
void DataProcess_lv3_reconstruct::reconstruct_2_2hit(){
    double epi_0V_total = epi_0V[0]+epi_0V[1];
    double epi_HV_total = epi_HV[0]+epi_HV[1];
  
    if(delta_x_0V[0] > 0){
        if(isConsistent(epi_0V[0],epi_HV[0])==true && isConsistent(epi_0V[1],epi_HV[1])==true && isConsistent(epi_0V[0],epi_HV[1])==false && isConsistent(epi_0V[1],epi_HV[0])==false){

	    double epi = calc_reconstructed_epi(epi_0V[0],epi_HV[0]);
	    set_signal(pos_x_0V[0],delta_x_0V[0],pos_y_HV[0],delta_y_HV[0],pos_z_HV[0],delta_z_HV[0],epi);

	    epi = calc_reconstructed_epi(epi_0V[1],epi_HV[1]);
	    set_signal(pos_x_0V[1],delta_x_0V[1],pos_y_HV[1],delta_y_HV[1],pos_z_HV[1],delta_z_HV[1],epi);            

        }else if(isConsistent(epi_0V[0],epi_HV[0])==false && isConsistent(epi_0V[1],epi_HV[1])==false && isConsistent(epi_0V[0],epi_HV[1])==true && isConsistent(epi_0V[1],epi_HV[0])==true){

	    double epi = calc_reconstructed_epi(epi_0V[0],epi_HV[1]);
	    set_signal(pos_x_0V[0],delta_x_0V[0],pos_y_HV[1],delta_y_HV[1],pos_z_HV[1],delta_z_HV[1],epi);

	    epi = calc_reconstructed_epi(epi_0V[1],epi_HV[0]);
	    set_signal(pos_x_0V[1],delta_x_0V[1],pos_y_HV[0],delta_y_HV[0],pos_z_HV[0],delta_z_HV[0],epi);            

        }else if(isConsistent(epi_0V[0],epi_HV_total)==true && isConsistent(epi_0V[1],epi_HV_total)==false){
	  
	    delete_one_signal_0V(1);
	    reconstruct_1_2hit();
	    
        }else if(isConsistent(epi_0V[0],epi_HV_total)==false && isConsistent(epi_0V[1],epi_HV_total)==true){
	  
	    delete_one_signal_0V(0);
	    reconstruct_1_2hit();
	    
        }else if(isConsistent(epi_0V_total,epi_HV[0])==true && isConsistent(epi_0V_total,epi_HV[1])==false){
	  
	    delete_one_signal_HV(1);
	    reconstruct_2_1hit();
	    
        }else if(isConsistent(epi_0V_total,epi_HV[0])==false && isConsistent(epi_0V_total,epi_HV[1])==true){
	  
	    delete_one_signal_HV(0);
	    reconstruct_2_1hit();
	    
        }
    }else{
        if(isConsistent(epi_0V[0],epi_HV[0])==true && isConsistent(epi_0V[1],epi_HV[1])==true && isConsistent(epi_0V[0],epi_HV[1])==false && isConsistent(epi_0V[1],epi_HV[0])==false){

	    double epi = calc_reconstructed_epi(epi_0V[0],epi_HV[0]);
	    set_signal(pos_x_HV[0],delta_x_HV[0],pos_y_0V[0],delta_y_0V[0],pos_z_HV[0],delta_z_HV[0],epi);

	    epi = calc_reconstructed_epi(epi_0V[1],epi_HV[1]);
	    set_signal(pos_x_HV[1],delta_x_HV[1],pos_y_0V[1],delta_y_0V[1],pos_z_HV[1],delta_z_HV[1],epi);            

        }else if(isConsistent(epi_0V[0],epi_HV[0])==false && isConsistent(epi_0V[1],epi_HV[1])==false && isConsistent(epi_0V[0],epi_HV[1])==true && isConsistent(epi_0V[1],epi_HV[0])==true){
	  
	    double epi = calc_reconstructed_epi(epi_0V[0],epi_HV[1]);
	    set_signal(pos_x_HV[1],delta_x_HV[1],pos_y_0V[0],delta_y_0V[0],pos_z_HV[1],delta_z_HV[1],epi);

	    epi = calc_reconstructed_epi(epi_0V[1],epi_HV[0]);
	    set_signal(pos_x_HV[0],delta_x_HV[0],pos_y_0V[1],delta_y_0V[1],pos_z_HV[0],delta_z_HV[0],epi);            

        }else if(isConsistent(epi_0V[0],epi_HV_total)==true && isConsistent(epi_0V[1],epi_HV_total)==false){
	  
	    delete_one_signal_0V(1);
	    reconstruct_1_2hit();
	    
        }else if(isConsistent(epi_0V[0],epi_HV_total)==false && isConsistent(epi_0V[1],epi_HV_total)==true){
	  
	    delete_one_signal_0V(0);
	    reconstruct_1_2hit();
	    
        }else if(isConsistent(epi_0V_total,epi_HV[0])==true && isConsistent(epi_0V_total,epi_HV[1])==false){
	  
	    delete_one_signal_HV(1);
	    reconstruct_2_1hit();
	    
        }else if(isConsistent(epi_0V_total,epi_HV[0])==false && isConsistent(epi_0V_total,epi_HV[1])==true){
	  
	    delete_one_signal_HV(0);
	    reconstruct_2_1hit();
	    
        }
    }
}
void DataProcess_lv3_reconstruct::reconstruct_multihit(){
    sort(order_epi_0V.begin(),order_epi_0V.end(),DataProcess_lv3_reconstruct::sort_epi_descend);
    sort(order_epi_HV.begin(),order_epi_HV.end(),DataProcess_lv3_reconstruct::sort_epi_descend);
    
    for(int i0V=0;i0V<epi_0V.size();i0V++){
      
      	int j0V = order_epi_0V[i0V].first;
	
        for(int iHV=0;iHV<epi_HV.size();iHV++){
	  
    	    int jHV = order_epi_HV[iHV].first;
	    
    	    if(isConsistent(epi_0V[j0V],epi_HV[jHV]) && fill_0V[j0V]==0 && fill_HV[jHV]==0){
	      
	        double epi = calc_reconstructed_epi(epi_0V[j0V],epi_HV[jHV]);
	      
	        if(delta_x_0V[j0V] > 0){
		  
  		    set_signal(pos_x_0V[j0V],delta_x_0V[j0V],pos_y_HV[jHV],delta_y_HV[jHV],pos_z_HV[jHV],delta_z_HV[jHV],epi);
		    
	        }else{
		    set_signal(pos_x_HV[jHV],delta_x_HV[jHV],pos_y_0V[j0V],delta_y_0V[j0V],pos_z_HV[jHV],delta_z_HV[jHV],epi);
		    
                }

                fill_0V[j0V] = 1;
		fill_HV[jHV] = 1;	
            }
        }//for iHV
    }//fpr i0V
}
  
bool DataProcess_lv3_reconstruct::isConsistent(const double e0V,const double eHV){
    bool isconsis = false;
    double deltae = fabs(e0V-eHV);
    bool isin15percent = false;
    double erecon = (double)calc_reconstructed_epi(e0V,eHV);
    if(deltae<=erecon*0.15)isin15percent = true;
    
    bool isin3sigma = false;
    double sigma = 1.0;//keV

    
    //if muon exp
    double sigma0V = 1.9*0.001*e0V + 0.639;
    double sigmaHV = 1.15*0.001*eHV + 0.734;
    sigma = sigma0V*sigmaHV/sqrt(sigma0V*sigma0V+sigmaHV*sigmaHV);
    if(deltae<=sigma*3)isin3sigma = true;
    if(isin3sigma && isin15percent)isconsis = true;
    //
    
    //if(deltae<=sigma*3)isin3sigma = true;
    //if(isin3sigma || isin15percent)isconsis = true;

    return isconsis;
}

bool DataProcess_lv3_reconstruct::sort_epi_descend(const std::pair<int, double> &left, const std::pair<int, double> &right){
    return left.second > right.second;
}

double DataProcess_lv3_reconstruct::calc_reconstructed_epi(const double e0V, const double eHV){//you can change this method
    double epi_new = eHV;

    
    //if muon exp
    double sigma0V = 1.9*0.001*e0V + 0.639;
    double sigmaHV = 1.15*0.001*eHV + 0.734;
    epi_new = (e0V*sigma0V*sigma0V+eHV*sigmaHV*sigmaHV)/(sigma0V*sigma0V+sigmaHV*sigmaHV);
    //
    
    
    return epi_new;
}//
void DataProcess_lv3_reconstruct::delete_one_signal_0V(int i){
    pos_x_0V.erase(pos_x_0V.begin()+i);
    pos_y_0V.erase(pos_y_0V.begin()+i);
    pos_z_0V.erase(pos_z_0V.begin()+i);
    delta_x_0V.erase(delta_x_0V.begin()+i);
    delta_y_0V.erase(delta_y_0V.begin()+i);
    delta_z_0V.erase(delta_z_0V.begin()+i);
    epi_0V.erase(epi_0V.begin()+i);
    //order_epi_0V.erase(order_epi_0V.begin()+i);
}
void DataProcess_lv3_reconstruct::delete_one_signal_HV(int i){
    pos_x_HV.erase(pos_x_HV.begin()+i);
    pos_y_HV.erase(pos_y_HV.begin()+i);
    pos_z_HV.erase(pos_z_HV.begin()+i);
    delta_x_HV.erase(delta_x_HV.begin()+i);
    delta_y_HV.erase(delta_y_HV.begin()+i);
    delta_z_HV.erase(delta_z_HV.begin()+i);
    epi_HV.erase(epi_HV.begin()+i);
    //order_epi_HV.erase(order_epi_HV.begin()+i);
}
void DataProcess_lv3_reconstruct::set_signal(double pos_x, double delta_x,double pos_y, double delta_y, double pos_z, double delta_z, double epi){
    reconstructed_pos_x = pos_x;
    reconstructed_delta_x = delta_x;
    reconstructed_pos_y = pos_y;
    reconstructed_delta_y = delta_y;
    reconstructed_pos_z = pos_z;
    reconstructed_delta_z = delta_z;
    reconstructed_epi = epi;
    set_reconstructed_signal();
}
  
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
