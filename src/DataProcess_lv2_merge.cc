#include "DataProcess_lv2_merge.hh"

using namespace anl;

namespace hittree_gen 
{

DataProcess_lv2_merge::DataProcess_lv2_merge() {
}

void DataProcess_lv2_merge::doProcessing(){
    merge();
}

void DataProcess_lv2_merge::merge(){
    eventData_lv2->ndetector_lv2 = 1;
    eventData_lv2->detid_lv2[0] = 10;
    eventData_lv2->material_lv2[0] = 1;
    eventData_lv2->nsignal_x_lv2[0] = 1;
    eventData_lv2->nsignal_y_lv2[0] = 1;
    (eventData_lv2->n_merged_strips_x_lv2)[0][0] = 1;
    eventData_lv2->n_merged_strips_y_lv2[0][0] = 1;
    eventData_lv2->detch_array_x_lv2[0][0][0] = 10;
    eventData_lv2->detch_array_y_lv2[0][0][0] = 10;
    eventData_lv2->epi_array_x_lv2[0][0][0] = 10;
    eventData_lv2->epi_array_y_lv2[0][0][0] = 5;
    eventData_lv2->epi_x_lv2[0][0] = 25.0;
    eventData_lv2->epi_y_lv2[0][0] = 20.0;
    eventData_lv2->pos_x_lv2[0][0] = 10;
    eventData_lv2->delta_x_lv2[0][0] = 0.1;
    eventData_lv2->pos_y_lv2[0][0] = 5;
    eventData_lv2->delta_y_lv2[0][0] = 0.1;
    eventData_lv2->pos_z_lv2[0] = 2;
    eventData_lv2->delta_z_lv2[0] = 0.1;
}

bool DataProcess_lv2_merge::isAdjacent(int i){
    return true;
}

void DataProcess_lv2_merge::initialize(){
}

void DataProcess_lv2_merge::set_merged_signal(){
}

} /* namespace hittree_gen*/
