#!/usr/bin/env ruby

#require 'comptonsoft/basic'
#include ComptonSoft
#
require 'ANLLib'
require 'eventTree2HitTreeGen'
include EventTree2HitTreeGen

#analysis_param="database/analysis_parameters.xml"

class MyApp < ANL::ANLApp

  def setup()
    @filename = ARGV[0]
    @outfilename = File.basename(@filename,".root")+"_hittree_lv123.root"
    @map_filename = "map.root"
    @profile_filename = "profile.root"
    @calfunc_filename = "rename_spline_maxbin_no17.root"

    chain :SaveData
    with_parameters(output: @outfilename)    

    chain :EventDataBuffer

    chain :ReadDetectorDatabase
    with_parameters(map_file: @map_filename,
                    profile_file: @profile_filename,
                    calfunc_file: @calfunc_filename)    

    chain :ReadInputTree
    with_parameters(file_list: [@filename],
                    inputdata_level: 0,
                    treename: "eventtree")    

    chain :DataProcess_lv1

    chain :DataProcess_lv2_merge

    chain :DataProcess_lv3_reconstruct

    chain :WriteTree
    with_parameters(write_lv1: true,
                    write_lv2: true,
                    write_lv3: true,
                    treename: "hittree", 
                    clone_inputTree: true,
                    inputtree_is_eventtree?: true)    

  end
end

anl = MyApp.new
anl.write_parameters_to_json "parameters.json"
anl.run(-1, 1000)
