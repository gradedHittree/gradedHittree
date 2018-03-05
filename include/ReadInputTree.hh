#ifndef HitTreeGen_ReadInputTree_H
#define HitTreeGen_ReadInputTree_H 1

#include "BasicModule.hh"
#include "ReadDetectorDatabase.hh"
#include "EventDataBuffer.hh"
#include "EventData_common.hh"
#include "EventData_lv0.hh"
#include "ConstantPar.hh"
#include <string>
#include <fstream>
#include <vector>
#include "TChain.h"

class TFile;

namespace hittree_gen{

class ReadInputTree : public anl::BasicModule
{
  DEFINE_ANL_MODULE(ReadInputTree, 1.0);
public:
  ReadInputTree();
  ~ReadInputTree() = default;

  anl::ANLStatus mod_startup();
  anl::ANLStatus mod_init();
  anl::ANLStatus mod_ana();

  TChain* getTreePointer() const { return m_Tree; }
//  EventData_lv0* getEventData() const { return eventData; }

protected:
  std::string nextFile() { return *(m_FileIterator++); }
  bool wasLastFile() const { return (m_FileIterator==m_FileList.end()); }
  bool checkFiles();
  
private:
  EventData_common *eventData_common;
  EventData_lv0 *eventData_lv0;
  EventData_lv1 *eventData_lv1;
  EventData_lv2 *eventData_lv2;
//  EventData_lv3 *eventData_lv3;

  const ReadDetectorDatabase *readDetectorDatabase_;
  const EventDataBuffer *eventDataBuffer_;
  std::vector<std::string> m_FileList;
  std::vector<std::string>::const_iterator m_FileIterator;
  std::string treename;

  int inputdata_level;
  void setBranchAddress_lv0();
  void setBranchAddress_lv1();
  void setBranchAddress_lv2();

  void loadData_lv0(unsigned int iEvent);
  void loadData_lv1(unsigned int iEvent);
  void loadData_lv2(unsigned int iEvent);

  int nasic = 0;

  TChain* m_Tree = nullptr;
  uint32_t m_NEvents = 0u;
  uint16_t m_ADC[MAX_N_ASIC][N_ASICCH];
  uint16_t m_INDEX[MAX_N_ASIC][N_ASICCH];
  uint16_t m_HITNUM[MAX_N_ASIC];
  uint16_t m_CMN[MAX_N_ASIC];
  unsigned int m_UnixTime = 0;
  unsigned int m_LiveTime;
  unsigned int m_IntegralLiveTime;
  unsigned int m_Ti;
};

} /* namespace comptonsoft */

#endif 
