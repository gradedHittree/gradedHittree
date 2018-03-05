#ifndef HitTreeGen_EventDataStruct_lv2_H
#define HitTreeGen_EventDataStruct_lv2_H 1

#include <string>
#include <vector>
#include "EventData.hh"

class TFile;

namespace hittree_gen{

class EventData_lv2 : public EventData{
    public:
        EventData_lv2() = default;
        ~EventData_lv2() = default;

        void ResetData(){
            ndetector_lv2 = 0;
            set_allzero_array1d(detid_lv2);
            set_allzero_array1d(material_lv2);
            set_allzero_array1d(nsignal_x_lv2);
            set_allzero_array1d(nsignal_y_lv2);
            set_allzero_array2d(n_merged_strips_x_lv2);
            set_allzero_array2d(n_merged_strips_y_lv2);
            set_allzero_array3d(detch_array_x_lv2);
            set_allzero_array3d(detch_array_y_lv2);
            set_allzero_array3d(epi_array_x_lv2);
            set_allzero_array3d(epi_array_y_lv2);
            set_allzero_array2d(epi_x_lv2);
            set_allzero_array2d(epi_y_lv2);
            set_allzero_array2d(pos_x_lv2);
            set_allzero_array2d(delta_x_lv2);
            set_allzero_array2d(pos_y_lv2);
            set_allzero_array2d(delta_y_lv2);
            set_allzero_array1d(pos_z_lv2);
            set_allzero_array1d(delta_z_lv2);
        };

        Int_t ndetector_lv2;
        Int_t detid_lv2[MAX_N_DETECTOR];
        Int_t material_lv2[MAX_N_DETECTOR];
        Int_t nsignal_x_lv2[MAX_N_DETECTOR];
        Int_t nsignal_y_lv2[MAX_N_DETECTOR];
        Int_t n_merged_strips_x_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Int_t n_merged_strips_y_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Int_t detch_array_x_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL][MAX_N_SIGNAL_2];
        Int_t detch_array_y_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL][MAX_N_SIGNAL_2];
        Double_t epi_array_x_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL][MAX_N_SIGNAL_2];
        Double_t epi_array_y_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL][MAX_N_SIGNAL_2];
        Double_t epi_x_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t epi_y_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t pos_x_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t delta_x_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t pos_y_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t delta_y_lv2[MAX_N_DETECTOR][MAX_N_SIGNAL];
        Double_t pos_z_lv2[MAX_N_DETECTOR];
        Double_t delta_z_lv2[MAX_N_DETECTOR];
};

}

#endif
