#include "WriteTree.hh"

using namespace anl;

namespace hittree_gen{

WriteTree::WriteTree()
 :  hittree(nullptr),
    treename("hittree"),
    eventDataBuffer_(nullptr),
    eventData_lv1(nullptr),
    eventData_lv2(nullptr),
    eventData_lv3(nullptr),
    bool_clone_inputtree(0),
    bool_inputtree_is_eventtree(0),
    bool_write_lv1(0),
    bool_write_lv2(0),
    bool_write_lv3(0)
{
}

ANLStatus WriteTree::mod_startup(){
    register_parameter(&bool_clone_inputtree, "clone_inputTree");
    register_parameter(&bool_inputtree_is_eventtree, "inputtree_is_eventtree?");
    register_parameter(&bool_write_lv1, "write_lv1");
    register_parameter(&bool_write_lv2, "write_lv2");
    register_parameter(&bool_write_lv3, "write_lv3");
    register_parameter(&treename, "treename");

    return AS_OK;
}

ANLStatus WriteTree::mod_init()
{
  GetANLModule("EventDataBuffer", &eventDataBuffer_);
  GetANLModule("ReadInputTree", &readInputTree_);

  eventData_common = eventDataBuffer_->getEventData_common();
  eventData_lv1 = eventDataBuffer_->getEventData_lv1();
  eventData_lv2 = eventDataBuffer_->getEventData_lv2();
  eventData_lv3 = eventDataBuffer_->getEventData_lv3();

  return AS_OK;
}

ANLStatus WriteTree::mod_his(){
  if(bool_clone_inputtree){
    hittree = readInputTree_->getTreePointer()->CloneTree(0);
  }else{
    hittree = new TTree();
  }
  hittree->SetNameTitle(treename.c_str(), treename.c_str());

  if(bool_inputtree_is_eventtree || !bool_clone_inputtree){ Branch_common();}
  if(bool_write_lv1){ Branch_lv1();}
  if(bool_write_lv2){ Branch_lv2();}
  if(bool_write_lv3){ Branch_lv3();}

  return AS_OK;
}

ANLStatus WriteTree::mod_ana()
{
  hittree->Fill();
  return AS_OK;
}

ANLStatus WriteTree::mod_endrun(){
  hittree->Write();
  return AS_OK;
}

void WriteTree::Branch_common(){
  hittree->Branch("eventID",&(eventData_common->eventID));
}

void WriteTree::Branch_lv1(){
  hittree->Branch("ndetector_lv1",&(eventData_lv1->ndetector_lv1),"ndetector_lv1/I");
  hittree->Branch("detid_lv1",eventData_lv1->detid_lv1,"detid_lv1[ndetector_lv1]/I");
  hittree->Branch("material_lv1",eventData_lv1->material_lv1,"material_lv1[ndetector_lv1]/I");
  hittree->Branch("nsignal_x_lv1",eventData_lv1->nsignal_x_lv1,"nsignal_x_lv1[ndetector_lv1]/I");
  hittree->Branch("nsignal_y_lv1",eventData_lv1->nsignal_y_lv1,"nsignal_y_lv1[ndetector_lv1]/I");
  hittree->Branch("detch_x_lv1",eventData_lv1->detch_x_lv1,Form("detch_x_lv1[ndetector_lv1][%d]/I", MAX_N_SIGNAL));
  hittree->Branch("detch_y_lv1",eventData_lv1->detch_y_lv1,Form("detch_y_lv1[ndetector_lv1][%d]/I", MAX_N_SIGNAL));
  hittree->Branch("epi_x_lv1",eventData_lv1->epi_x_lv1,Form("epi_x_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("epi_y_lv1",eventData_lv1->epi_y_lv1,Form("epi_y_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("ethre_x_lv1",eventData_lv1->ethre_x_lv1,Form("ethre_x_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("ethre_y_lv1",eventData_lv1->ethre_y_lv1,Form("ethre_y_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("pos_x_lv1",eventData_lv1->pos_x_lv1,Form("pos_x_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("delta_x_lv1",eventData_lv1->delta_x_lv1,Form("delta_x_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("pos_y_lv1",eventData_lv1->pos_y_lv1,Form("pos_y_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("delta_y_lv1",eventData_lv1->delta_y_lv1,Form("delta_y_lv1[ndetector_lv1][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("pos_z_lv1",eventData_lv1->pos_z_lv1,"pos_z_lv1[ndetector_lv1]/D");
  hittree->Branch("delta_z_lv1",eventData_lv1->delta_z_lv1,"delta_z_lv1[ndetector_lv1]/D");
}

void WriteTree::Branch_lv2(){
  hittree->Branch("ndetector_lv2", &(eventData_lv2->ndetector_lv2), "ndetector_lv2/I");
  hittree->Branch("detid_lv2", eventData_lv2->detid_lv2, "detid_lv2[ndetector_lv2]/I");
  hittree->Branch("material_lv2", eventData_lv2->material_lv2, "material_lv2[ndetector_lv2]/I");
  hittree->Branch("nsignal_x_lv2", eventData_lv2->nsignal_x_lv2, "nsignal_x_lv2[ndetector_lv2]/I");
  hittree->Branch("nsignal_y_lv2", eventData_lv2->nsignal_y_lv2, "nsignal_y_lv2[ndetector_lv2]/I");
  hittree->Branch("n_merged_strips_x_lv2", eventData_lv2->n_merged_strips_x_lv2,
                                  Form("n_merged_strips_x_lv2[ndetector_lv2][%d]/I", MAX_N_SIGNAL));
  hittree->Branch("n_merged_strips_y_lv2", eventData_lv2->n_merged_strips_y_lv2,
                                  Form("n_merged_strips_y_lv2[ndetector_lv2][%d]/I", MAX_N_SIGNAL));
  hittree->Branch("detch_array_x_lv2", eventData_lv2->detch_array_x_lv2,
                                  Form("detch_array_x_lv2[ndetector_lv2][%d][%d]/I", MAX_N_SIGNAL, MAX_N_SIGNAL_2));
  hittree->Branch("detch_array_y_lv2", eventData_lv2->detch_array_y_lv2,
                                  Form("detch_array_y_lv2[ndetector_lv2][%d][%d]/I", MAX_N_SIGNAL, MAX_N_SIGNAL_2));
  hittree->Branch("epi_array_x_lv2", eventData_lv2->epi_array_x_lv2,
                                  Form("epi_array_x_lv2[ndetector_lv2][%d][%d]/D", MAX_N_SIGNAL, MAX_N_SIGNAL_2));
  hittree->Branch("epi_array_y_lv2", eventData_lv2->epi_array_y_lv2,
                                  Form("epi_array_y_lv2[ndetector_lv2][%d][%d]/D", MAX_N_SIGNAL, MAX_N_SIGNAL_2));
  hittree->Branch("epi_x_lv2", eventData_lv2->epi_x_lv2,
                                  Form("epi_x_lv2[ndetector_lv2][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("epi_y_lv2", eventData_lv2->epi_y_lv2,
                                  Form("epi_y_lv2[ndetector_lv2][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("pos_x_lv2", eventData_lv2->pos_x_lv2,
                                  Form("pos_x_lv2[ndetector_lv2][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("delta_x_lv2", eventData_lv2->delta_x_lv2,
                                  Form("delta_x_lv2[ndetector_lv2][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("pos_y_lv2", eventData_lv2->pos_y_lv2,
                                  Form("pos_y_lv2[ndetector_lv2][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("delta_y_lv2", eventData_lv2->delta_y_lv2,
                                  Form("delta_y_lv2[ndetector_lv2][%d]/D", MAX_N_SIGNAL));
  hittree->Branch("pos_z_lv2", eventData_lv2->pos_z_lv2, "pos_z_lv2[ndetector_lv2]/D");
  hittree->Branch("delta_z_lv2", eventData_lv2->delta_z_lv2, "delta_z_lv2[ndetector_lv2]/D");
}

void WriteTree::Branch_lv3(){
  hittree->Branch("ndetector_lv3", &(eventData_lv3->ndetector_lv3), "ndetector_lv3/I");
  hittree->Branch("detid_lv3", eventData_lv3->detid_lv3, "detid_lv3[ndetector_lv3]/I");
  hittree->Branch("material_lv3", eventData_lv3->material_lv3, "material_lv3[ndetector_lv3]/I");
  hittree->Branch("nsignal_x_lv3", eventData_lv3->nsignal_x_lv3, "nsignal_x_lv3[ndetector_lv3]/I");
  hittree->Branch("nsignal_y_lv3", eventData_lv3->nsignal_y_lv3, "nsignal_y_lv3[ndetector_lv3]/I");
  hittree->Branch("nhit_lv3", eventData_lv3->nhit_lv3, "nhit_lv3[ndetector_lv3]/I");
  hittree->Branch("n_merged_strips_x_lv3", eventData_lv3->n_merged_strips_x_lv3,
                      Form("n_merged_strips_x_lv3[ndetector_lv3][%d]/I", MAX_N_HIT));
  hittree->Branch("n_merged_strips_y_lv3", eventData_lv3->n_merged_strips_y_lv3,
                      Form("n_merged_strips_y_lv3[ndetector_lv3][%d]/I", MAX_N_HIT));
  hittree->Branch("epi_x_lv3", eventData_lv3->epi_x_lv3,
                      Form("epi_x_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("epi_y_lv3", eventData_lv3->epi_y_lv3,
                      Form("epi_y_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("epi_reconstructed_lv3", eventData_lv3->epi_reconstructed_lv3,
                      Form("epi_reconstructed_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("pos_x_lv3", eventData_lv3->pos_x_lv3,
                      Form("pos_x_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("delta_x_lv3", eventData_lv3->delta_x_lv3,
                      Form("delta_x_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("pos_y_lv3", eventData_lv3->pos_y_lv3,
                      Form("pos_y_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("delta_y_lv3", eventData_lv3->delta_y_lv3,
                      Form("delta_y_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("pos_z_lv3", eventData_lv3->pos_z_lv3,
                      Form("pos_z_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
  hittree->Branch("delta_z_lv3", eventData_lv3->delta_z_lv3,
                      Form("delta_z_lv3[ndetector_lv3][%d]/D", MAX_N_HIT));
}

} /* namespace hittree_gen*/
