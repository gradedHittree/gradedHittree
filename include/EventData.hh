#ifndef HitTreeGen_EventData_H
#define HitTreeGen_EventData_H 1

#include <string>
#include <vector>

class TFile;

namespace hittree_gen{

class EventData{
public:
    EventData(){}
    ~EventData(){}

    virtual void ResetData() {}

protected:
    template<typename array1d>
    void set_allzero_array1d(array1d &array1d_){
        for(int i = 0; i < sizeof(array1d_)/sizeof(array1d_[0]); ++i){
            array1d_[i] = 0;
        }
    }

    template<typename array2d>
    void set_allzero_array2d(array2d &array2d_){
        for(int i = 0; i < sizeof(array2d_)/sizeof(array2d_[0]); ++i){
            for(int j = 0; j < sizeof(array2d_[0])/sizeof(array2d_[0][0]); ++j){
                array2d_[i][j] = 0;
            }
        }
    }

    template<typename array3d>
    void set_allzero_array3d(array3d &array3d_){
        for(int i = 0; i < sizeof(array3d_)/sizeof(array3d_[0]); ++i){
            for(int j = 0; j < sizeof(array3d_[0])/sizeof(array3d_[0][0]); ++j){
                for(int k = 0; k < sizeof(array3d_[0][0])/sizeof(array3d_[0][0][0]); ++k){
                    array3d_[i][j][k] = 0;
                }
            }
        }
    }
};

}

#endif
