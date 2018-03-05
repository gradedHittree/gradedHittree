#include "DataProcess_lv1.hh"
#include "TSpline.h"

using namespace anl;

namespace hittree_gen 
{

DataProcess_lv1::DataProcess_lv1()
  : random_mode(1),
  readDetectorDatabase_(nullptr),
  eventDataBuffer_(nullptr)
{
}

ANLStatus DataProcess_lv1::mod_startup()
{
  register_parameter(&random_mode, "random_mode");
  return AS_OK;
}

ANLStatus DataProcess_lv1::mod_init()
{
  GetANLModule("ReadDetectorDatabase", &readDetectorDatabase_);
  GetANLModule("EventDataBuffer", &eventDataBuffer_);

  eventData_common = eventDataBuffer_->getEventData_common();
  eventData_lv0 = eventDataBuffer_->getEventData_lv0();
  eventData_lv1 = eventDataBuffer_->getEventData_lv1();

  eventData_common->eventID = 0;

  return AS_OK;
}

ANLStatus DataProcess_lv1::mod_ana()
{
  eventData_lv1->ResetData();
  eventData_common->eventID += 1;

  int nsignal_lv1 = 0;

  for(int isignal = 0; isignal < eventData_lv0->get_nsignal(); ++isignal){
        int asicid = eventData_lv0->get_asicid(isignal);
        int asicch = eventData_lv0->get_asicch(isignal);
        int adc = eventData_lv0->get_adc(isignal);

        std::pair<int, int> p_asicid_and_asicch = std::make_pair(asicid, asicch);

        if(readDetectorDatabase_->isBlankch(p_asicid_and_asicch)){
            continue;
        }
        if(readDetectorDatabase_->isBadch(p_asicid_and_asicch)){
            continue;
        }

        int detid = readDetectorDatabase_->get_detid(p_asicid_and_asicch);
        int detch = readDetectorDatabase_->get_detch(p_asicid_and_asicch);
        int remapch = readDetectorDatabase_->get_remapch(p_asicid_and_asicch);
        int detector_material = readDetectorDatabase_->get_detector_material(p_asicid_and_asicch);
        int detector_HV = readDetectorDatabase_->get_detector_HV(p_asicid_and_asicch);
        double pos_x = readDetectorDatabase_->get_pos_x(p_asicid_and_asicch);
        double pos_y = readDetectorDatabase_->get_pos_y(p_asicid_and_asicch);
        double pos_z = readDetectorDatabase_->get_pos_z(p_asicid_and_asicch);
        double delta_x = readDetectorDatabase_->get_delta_x(p_asicid_and_asicch);
        double delta_y = readDetectorDatabase_->get_delta_y(p_asicid_and_asicch);
        double delta_z = readDetectorDatabase_->get_delta_z(p_asicid_and_asicch);
	    double ethre = readDetectorDatabase_->get_ethre(p_asicid_and_asicch);
        double epi = getEPI(p_asicid_and_asicch, adc);
        
        int idet = -1;
        for(int _idet = 0; _idet < eventData_lv1->ndetector_lv1; ++_idet){
            if(eventData_lv1->detid_lv1[_idet] == detid){
                idet = _idet;
            }
        }
        if(idet == -1){ //new detector
            idet = eventData_lv1->ndetector_lv1; 
            eventData_lv1->ndetector_lv1 += 1;
            eventData_lv1->detid_lv1[idet] = detid;
            eventData_lv1->material_lv1[idet] = detector_material;
            eventData_lv1->pos_z_lv1[idet] = pos_z;
            eventData_lv1->delta_z_lv1[idet] = delta_z;
        }

        if(delta_x < 0){
            int isig = eventData_lv1->nsignal_y_lv1[idet];
            eventData_lv1->nsignal_y_lv1[idet] +=1;
            eventData_lv1->detch_y_lv1[idet][isig] = detch;
            eventData_lv1->epi_y_lv1[idet][isig] = epi;
            eventData_lv1->pos_y_lv1[idet][isig] = pos_y;
            eventData_lv1->delta_y_lv1[idet][isig] = delta_y;
            eventData_lv1->ethre_y_lv1[idet][isig] = ethre;
        }else if(delta_y < 0){
            int isig = eventData_lv1->nsignal_x_lv1[idet];
            eventData_lv1->nsignal_x_lv1[idet] +=1;
            eventData_lv1->detch_x_lv1[idet][isig] = detch;
            eventData_lv1->epi_x_lv1[idet][isig] = epi;
            eventData_lv1->pos_x_lv1[idet][isig] = pos_x;
            eventData_lv1->delta_x_lv1[idet][isig] = delta_x;
            eventData_lv1->ethre_x_lv1[idet][isig] = ethre;
        }else{
            return AS_QUIT_ERR;
        }

        ++nsignal_lv1;
  }

  return AS_OK;
}

double DataProcess_lv1::getEPI(std::pair<int, int> p_asicid_and_asicch, int adc){
    TSpline3 *calfunc = readDetectorDatabase_->get_calfunc(p_asicid_and_asicch);
    double epi = 0;
    if(random_mode == 0){
        epi = calfunc->Eval(adc);
    }else if(random_mode == 1){
        epi = calfunc->Eval(adc + random.Uniform(-0.5, 0.5) );
    }else if(random_mode == 2){
        epi = calfunc->Eval(adc + random.Uniform(0, 1) );
    }else if(random_mode == 3){
        epi = calfunc->Eval(adc + random.Uniform(-1, 0) );
    }
    return epi;
}

} /* namespace hittree_gen*/
