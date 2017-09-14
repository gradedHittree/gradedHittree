# Install script for directory: /Users/goroyabu/Soft/new_hittree_soft/ruby

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/goroyabu")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/goroyabu/lib/ruby" TYPE MODULE FILES "/Users/goroyabu/Soft/new_hittree_soft/build/ruby/eventTree2HitTreeGen.bundle")
  if(EXISTS "$ENV{DESTDIR}/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/goroyabu/Soft/new_hittree_soft/build/libEventTree2HitTreeGen.dylib" "libEventTree2HitTreeGen.dylib"
      "$ENV{DESTDIR}/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/goroyabu/lib"
      "$ENV{DESTDIR}/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/usr/local/Cellar/root/5.34.36_2/lib/root"
      "$ENV{DESTDIR}/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" "$ENV{DESTDIR}/Users/goroyabu/lib/ruby/eventTree2HitTreeGen.bundle")
    endif()
  endif()
endif()

