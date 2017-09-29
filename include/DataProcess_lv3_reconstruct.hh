/*
2017/09/14 modified by Goro Yabu
*/
#ifndef HitTreeGen_DataProcess_lv3_reconstruct_H
#define HitTreeGen_DataProcess_lv3_reconstruct_H 1

#include "DataProcess_lv3_base.hh"

namespace hittree_gen{

class DataProcess_lv3_reconstruct: public DataProcess_lv3_base
{
  DEFINE_ANL_MODULE(DataProcess_lv3_reconstruct, 1.0);
public:
  DataProcess_lv3_reconstruct();
  ~DataProcess_lv3_reconstruct() = default;

private:
  void initialize();
  void doProcessing();

  void reconstruct();
  void reconstruct_1_1hit();
  void reconstruct_2_1hit();
  void reconstruct_1_2hit();
  void reconstruct_2_2hit();
  void reconstruct_multihit();
  bool isConsistent(const double e0V, const double eHV);
  static bool sort_epi_descend(const std::pair<int, double> &left,const std::pair<int, double> &right);
  double calc_reconstructed_epi(const double e0V, const double eHV);
  void delete_one_signal_0V(int i);
  void delete_one_signal_HV(int i);
  void set_signal(double pos_x, double delta_x,double pos_y, double delta_y, double pos_z, double delta_z, double epi);
  
  void set_reconstructed_signal();
  void delete_signal();
  void fill_signal_into_vector(int i);
  
  std::vector<int> filled_signal_index;

  int detid;
  int detector_material;

  int nsignal;
  std::vector<double> pos_x_0V;
  std::vector<double> pos_y_0V;
  std::vector<double> pos_z_0V;
  std::vector<double> delta_x_0V;
  std::vector<double> delta_y_0V;
  std::vector<double> delta_z_0V;
  std::vector<double> epi_0V;

  std::vector<double> pos_x_HV;
  std::vector<double> pos_y_HV;
  std::vector<double> pos_z_HV;
  std::vector<double> delta_x_HV;
  std::vector<double> delta_y_HV;
  std::vector<double> delta_z_HV;
  std::vector<double> epi_HV;

  std::vector<std::pair<int, double>> order_epi_0V;
  std::vector<std::pair<int, double>> order_epi_HV;
  std::vector<int> fill_0V;
  std::vector<int> fill_HV;
  
  int nhit = 0;
  double reconstructed_pos_x;
  double reconstructed_pos_y;
  double reconstructed_pos_z;
  double reconstructed_delta_x;
  double reconstructed_delta_y;
  double reconstructed_delta_z;
  double reconstructed_epi;
  
};

} /* namespace comptonsoft */

#endif 
