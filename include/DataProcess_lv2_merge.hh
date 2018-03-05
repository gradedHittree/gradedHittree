/*
2017/09/13 modified by Goro Yabu
*/

#ifndef HitTreeGen_DataProcess_lv2_merge_H
#define HitTreeGen_DataProcess_lv2_merge_H 1

#include "TH1D.h"
#include "DataProcess_lv2_base.hh"
#include "ConstantPar.hh"

namespace hittree_gen{

class DataProcess_lv2_merge: public DataProcess_lv2_base
{
  DEFINE_ANL_MODULE(DataProcess_lv2_merge, 2.0);
public:
  DataProcess_lv2_merge();
  ~DataProcess_lv2_merge() = default;

private:
  void initialize();
  void doProcessing();
  bool isAdjacent(int i);
  void merge();
  void set_merged_signal();

};

} /* namespace comptonsoft */

#endif 
