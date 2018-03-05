#ifndef HitTreeGen_EventDataStruct_lv3_H
#define HitTreeGen_EventDataStruct_lv3_H 1

#include <string>
#include <vector>

class TFile;

namespace hittree_gen{

class EventData_lv3 : public EventData{
    public:
        EventData_lv3() = default;
        ~EventData_lv3() = default;

        void ResetData(){
            ndetector_lv3 = 0;
            set_allzero_array1d(detid_lv3);
            set_allzero_array1d(material_lv3);
            set_allzero_array1d(nsignal_x_lv3);
            set_allzero_array1d(nsignal_y_lv3);
            set_allzero_array1d(nhit_lv3);
            set_allzero_array2d(n_merged_strips_x_lv3);
            set_allzero_array2d(n_merged_strips_y_lv3);
            set_allzero_array2d(epi_x_lv3);
            set_allzero_array2d(epi_y_lv3);
            set_allzero_array2d(epi_reconstructed_lv3);
            set_allzero_array2d(pos_x_lv3);
            set_allzero_array2d(delta_x_lv3);
            set_allzero_array2d(pos_y_lv3);
            set_allzero_array2d(delta_y_lv3);
            set_allzero_array2d(pos_z_lv3);
            set_allzero_array2d(delta_z_lv3);
        };

        Int_t ndetector_lv3;
        Int_t detid_lv3[MAX_N_DETECTOR];
        Int_t material_lv3[MAX_N_DETECTOR];
        Int_t nsignal_x_lv3[MAX_N_DETECTOR];
        Int_t nsignal_y_lv3[MAX_N_DETECTOR];
        Int_t nhit_lv3[MAX_N_DETECTOR];
        Int_t n_merged_strips_x_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Int_t n_merged_strips_y_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t epi_x_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t epi_y_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t epi_reconstructed_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t pos_x_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t delta_x_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t pos_y_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t delta_y_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t pos_z_lv3[MAX_N_DETECTOR][MAX_N_HIT];
        Double_t delta_z_lv3[MAX_N_DETECTOR][MAX_N_HIT];
};

}

#endif
