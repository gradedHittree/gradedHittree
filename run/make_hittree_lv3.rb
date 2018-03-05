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
    @outfilename = File.basename(@filename,"_hittree_lv2.root")+"_hittree_lv3.root"
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
                    inputdata_level: 2,
                    treename: "hittree")    

    chain :DataProcess_lv3_reconstruct

    chain :WriteTree
    with_parameters(write_lv1: false,
                    write_lv2: false,
                    write_lv3: true,
                    treename: "hittree", 
                    clone_inputTree: false,
                    inputtree_is_eventtree?: false)    

  end
end

anl = MyApp.new
anl.write_parameters_to_json "parameters.json"
anl.run(-1, 1000)
