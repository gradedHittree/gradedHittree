/*
2017/09/13 modified by Goro Yabu 
*/
#ifndef HitTreeGen_WriteTree_H
#define HitTreeGen_WriteTree_H 1

#include "BasicModule.hh"
#include <memory>
#include "TTree.h"

#include "ReadInputTree.hh"
#include "EventDataBuffer.hh"
#include "ConstantPar.hh"

namespace hittree_gen {

class WriteTree : public anl::BasicModule
{
  DEFINE_ANL_MODULE(WriteTree, 1.0);
public:
  WriteTree();
  ~WriteTree() = default;
  
  anl::ANLStatus mod_startup();
  anl::ANLStatus mod_init();
  anl::ANLStatus mod_his();
  anl::ANLStatus mod_ana();
  anl::ANLStatus mod_endrun();

private:
  const EventDataBuffer *eventDataBuffer_;
  const ReadInputTree *readInputTree_;

  EventData_common *eventData_common;
  EventData_lv1 *eventData_lv1;
  EventData_lv2 *eventData_lv2;
  EventData_lv3 *eventData_lv3;
  TTree *hittree;
  std::string treename;

  bool bool_clone_inputtree;
  bool bool_inputtree_is_eventtree;
  bool bool_write_lv1, bool_write_lv2, bool_write_lv3;
  void Branch_common();
  void Branch_lv1();
  void Branch_lv2();
  void Branch_lv3();
};

} 

#endif 
