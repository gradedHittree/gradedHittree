#include "ReadInputTree.hh"

using namespace anl;

namespace hittree_gen 
{

ReadInputTree::ReadInputTree()
  : inputdata_level(-1),
  treename("eventtree"),
  readDetectorDatabase_(nullptr),
  eventDataBuffer_(nullptr)
{
  add_alias("ReadInputTree");
}

ANLStatus ReadInputTree::mod_startup()
{
  register_parameter(&m_FileList, "file_list");
  register_parameter(&inputdata_level, "inputdata_level");
  register_parameter(&treename, "treename");
  
  return AS_OK;
}

ANLStatus ReadInputTree::mod_init()
{
  if(inputdata_level < 0 || 2 < inputdata_level){
    std::cout << "The parameter inputdata_level is less than 0 or more than 2 !" << std::endl;
    return AS_QUIT_ERR;
  }

  GetANLModule("ReadDetectorDatabase", &readDetectorDatabase_);
  GetANLModule("EventDataBuffer", &eventDataBuffer_);

  eventData_common = eventDataBuffer_->getEventData_common();
  eventData_lv0 = eventDataBuffer_->getEventData_lv0();
  eventData_lv1 = eventDataBuffer_->getEventData_lv1();
  eventData_lv2 = eventDataBuffer_->getEventData_lv2();
//  eventData_lv3 = eventDataBuffer_->getEventData_lv3();

  m_FileIterator = m_FileList.begin();

  m_Tree = new TChain(treename.c_str());
  while (!wasLastFile()) {
    m_Tree->Add(nextFile().c_str());
  }
  
  m_NEvents = m_Tree->GetEntries();
  std::cout << "Total Event : " << m_NEvents << std::endl;

  if(inputdata_level == 0) setBranchAddress_lv0();
  if(inputdata_level == 1) setBranchAddress_lv1();
  if(inputdata_level == 2) setBranchAddress_lv2();

  return AS_OK;
}

ANLStatus ReadInputTree::mod_ana()
{
  static unsigned int iEvent = 0;
  if(iEvent == m_NEvents) {
    return AS_QUIT;
  }

  if(inputdata_level == 0) loadData_lv0(iEvent);
  if(inputdata_level == 1) loadData_lv1(iEvent);
  if(inputdata_level == 2) loadData_lv2(iEvent);

  iEvent++;
  return AS_OK;
}

void ReadInputTree::setBranchAddress_lv0(){
  nasic = readDetectorDatabase_->get_nasic();

  for(int iasic = 0; iasic < nasic; ++iasic){
      int asicid = readDetectorDatabase_->get_asicid(iasic); 

      std::ostringstream oss;
      oss << "adc" << asicid;
      std::string branchName = oss.str();
      m_Tree->SetBranchAddress(branchName.c_str(), m_ADC[iasic]);
//      std::cout << branchName << std::endl;

      oss.str("");
      oss << "index" << asicid;
      branchName = oss.str();
      m_Tree->SetBranchAddress(branchName.c_str(), m_INDEX[iasic]);
//      std::cout << branchName << std::endl;

      oss.str("");
      oss << "hitnum" << asicid;
      branchName = oss.str();
      m_Tree->SetBranchAddress(branchName.c_str(), &m_HITNUM[iasic]);
//      std::cout << branchName << std::endl;
      
      oss.str("");
      oss << "cmn" << asicid;
      branchName = oss.str();
      m_Tree->SetBranchAddress(branchName.c_str(), &m_CMN[iasic]);
//      std::cout << branchName << std::endl;
  }
}

void ReadInputTree::setBranchAddress_lv1(){
  m_Tree->SetBranchAddress("eventID",&(eventData_common->eventID));
  m_Tree->SetBranchAddress("ndetector_lv1",&(eventData_lv1->ndetector_lv1));
  m_Tree->SetBranchAddress("detid_lv1",eventData_lv1->detid_lv1);
  m_Tree->SetBranchAddress("material_lv1",eventData_lv1->material_lv1);
  m_Tree->SetBranchAddress("nsignal_x_lv1",eventData_lv1->nsignal_x_lv1);
  m_Tree->SetBranchAddress("nsignal_y_lv1",eventData_lv1->nsignal_y_lv1);
  m_Tree->SetBranchAddress("detch_x_lv1",eventData_lv1->detch_x_lv1);
  m_Tree->SetBranchAddress("detch_y_lv1",eventData_lv1->detch_y_lv1);
  m_Tree->SetBranchAddress("epi_x_lv1",eventData_lv1->epi_x_lv1);
  m_Tree->SetBranchAddress("epi_y_lv1",eventData_lv1->epi_y_lv1);
  m_Tree->SetBranchAddress("ethre_x_lv1",eventData_lv1->ethre_x_lv1);
  m_Tree->SetBranchAddress("ethre_y_lv1",eventData_lv1->ethre_y_lv1);
  m_Tree->SetBranchAddress("pos_x_lv1",eventData_lv1->pos_x_lv1);
  m_Tree->SetBranchAddress("delta_x_lv1",eventData_lv1->delta_x_lv1);
  m_Tree->SetBranchAddress("pos_y_lv1",eventData_lv1->pos_y_lv1);
  m_Tree->SetBranchAddress("delta_y_lv1",eventData_lv1->delta_y_lv1);
  m_Tree->SetBranchAddress("pos_z_lv1",eventData_lv1->pos_z_lv1);
  m_Tree->SetBranchAddress("delta_z_lv1",eventData_lv1->delta_z_lv1);
}

void ReadInputTree::setBranchAddress_lv2(){
  m_Tree->SetBranchAddress("eventID",&(eventData_common->eventID));
  m_Tree->SetBranchAddress("ndetector_lv2", &(eventData_lv2->ndetector_lv2));
  m_Tree->SetBranchAddress("detid_lv2", eventData_lv2->detid_lv2);
  m_Tree->SetBranchAddress("material_lv2", eventData_lv2->material_lv2);
  m_Tree->SetBranchAddress("nsignal_x_lv2", eventData_lv2->nsignal_x_lv2);
  m_Tree->SetBranchAddress("nsignal_y_lv2", eventData_lv2->nsignal_y_lv2);
  m_Tree->SetBranchAddress("n_merged_strips_x_lv2", eventData_lv2->n_merged_strips_x_lv2);
  m_Tree->SetBranchAddress("n_merged_strips_y_lv2", eventData_lv2->n_merged_strips_y_lv2);
  m_Tree->SetBranchAddress("detch_array_x_lv2", eventData_lv2->detch_array_x_lv2);
  m_Tree->SetBranchAddress("detch_array_y_lv2", eventData_lv2->detch_array_y_lv2);
  m_Tree->SetBranchAddress("epi_array_x_lv2", eventData_lv2->epi_array_x_lv2);
  m_Tree->SetBranchAddress("epi_array_y_lv2", eventData_lv2->epi_array_y_lv2);
  m_Tree->SetBranchAddress("epi_x_lv2", eventData_lv2->epi_x_lv2);
  m_Tree->SetBranchAddress("epi_y_lv2", eventData_lv2->epi_y_lv2);
  m_Tree->SetBranchAddress("pos_x_lv2", eventData_lv2->pos_x_lv2);
  m_Tree->SetBranchAddress("delta_x_lv2", eventData_lv2->delta_x_lv2);
  m_Tree->SetBranchAddress("pos_y_lv2", eventData_lv2->pos_y_lv2);
  m_Tree->SetBranchAddress("delta_y_lv2", eventData_lv2->delta_y_lv2);
  m_Tree->SetBranchAddress("pos_z_lv2", eventData_lv2->pos_z_lv2);
  m_Tree->SetBranchAddress("delta_z_lv2", eventData_lv2->delta_z_lv2);
}

void ReadInputTree::loadData_lv0(unsigned int iEvent){
  eventData_lv0->ResetData();

  m_Tree->GetEntry(iEvent);

  int nsignal = 0;
  for(int iasic = 0; iasic < nasic; ++iasic){
      int hitnum = (int)m_HITNUM[iasic];

      if(hitnum == 0){
        continue;
      }

      for(int ich = 0; ich < hitnum; ++ich){
          ++nsignal;
          int asicid = readDetectorDatabase_->get_asicid(iasic); 
          int asicch = (int)m_INDEX[iasic][ich];
          int adc = (int)m_ADC[iasic][ich] - (int)m_CMN[iasic];

          eventData_lv0->set_asicid(asicid);
          eventData_lv0->set_asicch(asicch);
          eventData_lv0->set_adc(adc);
      }
  }
  eventData_lv0->set_nsignal(nsignal);
}

void ReadInputTree::loadData_lv1(unsigned int iEvent){
  eventData_common->ResetData();
  eventData_lv1->ResetData();

  m_Tree->GetEntry(iEvent);
}

void ReadInputTree::loadData_lv2(unsigned int iEvent){
  eventData_common->ResetData();
  eventData_lv2->ResetData();

  m_Tree->GetEntry(iEvent);
}

bool ReadInputTree::checkFiles()
{
  for (auto& filename: m_FileList) {
    std::ifstream fin;
    fin.open( filename.c_str() );
    if (!fin) {
      std::cout << "ReadInputTree: cannot open " << filename << std::endl;
      return false;
    }
    fin.close();
  }
  return true;
}

} /* namespace hittree_gen*/
