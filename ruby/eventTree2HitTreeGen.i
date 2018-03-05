%module eventTree2HitTreeGen 
%{
#include "BasicModule.hh"

// include headers of my modules
#include "EventDataBuffer.hh"
#include "DataProcess_lv1.hh"
#include "DataProcess_lv2_base.hh"
#include "DataProcess_lv2_merge.hh"
#include "DataProcess_lv3_base.hh"
#include "DataProcess_lv3_reconstruct.hh"
#include "ReadDetectorDatabase.hh"
#include "ReadInputTree.hh"
#include "SaveData.hh"
#include "WriteTree.hh"

%}

%import "ANL.i"


// interface to my modules


namespace hittree_gen {

class EventDataBuffer: public anl::BasicModule
{
public:
    EventDataBuffer();
    ~EventDataBuffer();
};

class DataProcess_lv1 : public anl::BasicModule
{
public:
    DataProcess_lv1();
    ~DataProcess_lv1();
};

class DataProcess_lv2_base : public anl::BasicModule
{
public:
    DataProcess_lv2_base();
    ~DataProcess_lv2_base();
};

class DataProcess_lv2_merge : public DataProcess_lv2_base
{
public:
    DataProcess_lv2_merge();
    ~DataProcess_lv2_merge();
};

class DataProcess_lv3_base : public anl::BasicModule
{
public:
    DataProcess_lv3_base();
    ~DataProcess_lv3_base();
};

class DataProcess_lv3_reconstruct : public DataProcess_lv3_base
{
public:
    DataProcess_lv3_reconstruct();
    ~DataProcess_lv3_reconstruct();
};

class ReadDetectorDatabase : public anl::BasicModule
{
public:
    ReadDetectorDatabase();
    ~ReadDetectorDatabase();
};

class ReadInputTree : public anl::BasicModule
{
public:
    ReadInputTree();
    ~ReadInputTree();
};

class SaveData : public anl::BasicModule
{
public:
    SaveData();
    ~SaveData();
};

class WriteTree : public anl::BasicModule
{
public:
    WriteTree();
    ~WriteTree();
};

}
