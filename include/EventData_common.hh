#ifndef HitTreeGen_EventDataStruct_common_H
#define HitTreeGen_EventDataStruct_common_H 1

#include <string>
#include <vector>
#include "EventData.hh"
#include "ConstantPar.hh"
#include "TROOT.h"
#include "TTree.h"

class TFile;

namespace hittree_gen{

class EventData_common : public EventData{
    public:
        EventData_common() = default;
        ~EventData_common() = default;

        void ResetData(){
            eventID = 0;
        };

        Long64_t eventID;
};

}

#endif
