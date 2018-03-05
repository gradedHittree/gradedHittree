/*
2017/09/14 modified by Goro Yabu
*/
#ifndef HitTreeGen_DataProcess_lv3_reconstruct_H
#define HitTreeGen_DataProcess_lv3_reconstruct_H 1

#include "DataProcess_lv3_base.hh"

namespace hittree_gen{

class DataProcess_lv3_reconstruct: public DataProcess_lv3_base
{
  DEFINE_ANL_MODULE(DataProcess_lv3_reconstruct, 2.0);
public:
  DataProcess_lv3_reconstruct();
  ~DataProcess_lv3_reconstruct() = default;

private:
  void initialize();
  void doProcessing();
  void reconstruct();
  
};

} /* namespace comptonsoft */

#endif 
