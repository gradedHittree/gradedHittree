// changed some parameters 2018-03-02 yoneda
#ifndef HitTreeGen_EventDataStruct_lv1_H
#define HitTreeGen_EventDataStruct_lv1_H 1

#include <string>
#include <vector>
#include "EventData.hh"
#include "ConstantPar.hh"

class TFile;

namespace hittree_gen{

class EventData_lv1 : public EventData{
    public:
        EventData_lv1() = default;
        ~EventData_lv1() = default;

        void ResetData(){
            ndetector_lv1 = 0;
            set_allzero_array1d(detid_lv1);
            set_allzero_array1d(material_lv1);
            set_allzero_array1d(nsignal_x_lv1);
            set_allzero_array1d(nsignal_y_lv1);
            set_allzero_array2d(detch_x_lv1);
            set_allzero_array2d(detch_y_lv1);
            set_allzero_array2d(epi_x_lv1);
            set_allzero_array2d(epi_y_lv1);
            set_allzero_array2d(ethre_x_lv1);
            set_allzero_array2d(ethre_y_lv1);
            set_allzero_array2d(pos_x_lv1);
            set_allzero_array2d(delta_x_lv1);
            set_allzero_array2d(pos_y_lv1);
            set_allzero_array2d(delta_y_lv1);
            set_allzero_array1d(pos_z_lv1);
            set_allzero_array1d(delta_z_lv1);
        };

        Int_t ndetector_lv1;
        Int_t detid_lv1[MAX_N_DETECTOR];
        Int_t material_lv1[MAX_N_DETECTOR];
        Int_t nsignal_x_lv1[MAX_N_DETECTOR];
        Int_t nsignal_y_lv1[MAX_N_DETECTOR];
        Int_t detch_x_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Int_t detch_y_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t epi_x_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t epi_y_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t ethre_x_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t ethre_y_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t pos_x_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t delta_x_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t pos_y_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t delta_y_lv1[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t pos_z_lv1[MAX_N_DETECTOR];
        Double_t delta_z_lv1[MAX_N_DETECTOR];
};

}

#endif
