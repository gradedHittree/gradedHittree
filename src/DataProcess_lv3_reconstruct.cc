#include "DataProcess_lv3_reconstruct.hh"

using namespace anl;

namespace hittree_gen 
{

DataProcess_lv3_reconstruct::DataProcess_lv3_reconstruct()
{
}

void DataProcess_lv3_reconstruct::doProcessing(){
    reconstruct();
}

void DataProcess_lv3_reconstruct::reconstruct(){
    eventData_lv3->ndetector_lv3 = 1;
    eventData_lv3->detid_lv3[0] = 10;
    eventData_lv3->material_lv3[0] = 20;
    eventData_lv3->nsignal_x_lv3[0] = 2;
    eventData_lv3->nsignal_y_lv3[0] = 2;
    eventData_lv3->nhit_lv3[0] = 1;
    eventData_lv3->n_merged_strips_x_lv3[0][0] = 5;
    eventData_lv3->n_merged_strips_y_lv3[0][0] = 5;
    eventData_lv3->epi_x_lv3[0][0] = 10.0;
    eventData_lv3->epi_y_lv3[0][0] = 10.0;
    eventData_lv3->epi_reconstructed_lv3[0][0] = 20.0;
    eventData_lv3->pos_x_lv3[0][0] = 5;
    eventData_lv3->delta_x_lv3[0][0] = 0.1;
    eventData_lv3->pos_y_lv3[0][0] = 6;
    eventData_lv3->delta_y_lv3[0][0] = 0.1;
    eventData_lv3->pos_z_lv3[0][0] = 7;
    eventData_lv3->delta_z_lv3[0][0] = 0.1;
}

void DataProcess_lv3_reconstruct::initialize(){
}

} /* namespace hittree_gen*/
