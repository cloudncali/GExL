# Project master CMakeList.txt file
#
# Reference(s):
# http://www.itk.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file
# http://www.sfml-dev.org/
# @date 20110421 RQL Modified to match example in reference(s) above
# @date 20140905 Modified for GExL use.

# Make sure they are using a recent version of CMake
cmake_minimum_required(VERSION 2.6)

# set a default build type if none was provided
# this has to be done before the project() instruction!
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

# project name
project(GExL)

# Include the macros file for this project
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# project options
set_option(BUILD_STATIC_STD_LIBS FALSE BOOL "Set to TRUE to statically link to the standard libraries, FALSE to use them as DLLs")
set_option(BUILD_SHARED_LIBS FALSE BOOL "Set to FALSE to build static libraries")
set_option(BUILD_EXAMPLES TRUE BOOL "Set to FALSE to skip building examples")
set_option(INSTALL_DOC TRUE BOOL "Set to FALSE to skip build/install Documentation")

# setup version numbers
set(GExL_VERSION_MAJOR 0)
set(GExL_VERSION_MINOR 0)
set(GExL_VERSION_PATCH 0)

set(GExL_VERSION "${GExL_VERSION_MAJOR}.${GExL_VERSION_MINOR}.${GExL_VERSION_PATCH}")

# define the path of our additional CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)

# include the configuration file after the project options are defined
include(${PROJECT_SOURCE_DIR}/cmake/Config.cmake)

# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}/include")
# disable the rpath stuff
set(CMAKE_SKIP_BUILD_RPATH TRUE)

# add the GExL subdirectory
add_subdirectory(src/GExL)

# add the examples subdirectory
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
if(INSTALL_DOC)
    add_subdirectory(doc)
endif()
# Add all targets to the build-tree export set
export(TARGETS gexl-core
  FILE "${PROJECT_BINARY_DIR}/GExL_LibraryDepends.cmake")

# Create a GExL_Config.cmake file for the use from the build tree
set(GExL_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
set(GExL_LIB_DIR "${PROJECT_BINARY_DIR}")
set(GExL_CMAKE_DIR "${PROJECT_BINARY_DIR}")
configure_file(gexl-config.cmake.in
  "${PROJECT_BINARY_DIR}/gexl-config.cmake" @ONLY)
configure_file(gexl-configversion.cmake.in
  "${PROJECT_BINARY_DIR}/gexl-configversion.cmake" @ONLY)

set(GExL_INCLUDE_DIRS include)
set(GExL_LIB_DIR lib)
set(GExL_CMAKE_DIR cmake)
configure_file(gexl-config.cmake.in
  "${PROJECT_BINARY_DIR}/InstallFiles/gexl-config.cmake" @ONLY)
configure_file(gexl-configversion.cmake.in
  "${PROJECT_BINARY_DIR}/InstallFiles/gexl-configversion.cmake" @ONLY)

install(FILES
  "${PROJECT_BINARY_DIR}/InstallFiles/gexl-config.cmake"
  "${PROJECT_BINARY_DIR}/InstallFiles/gexl-configversion.cmake"
  DESTINATION "${GExL_CMAKE_DIR}" COMPONENT dev)
# install our FindGExL cmake module into the Cmake Modules directory
install(FILES ${PROJECT_SOURCE_DIR}/cmake/Modules/FindGExL.cmake DESTINATION cmake/Modules)

# install our license file into our INSTALL_DATA_DIR
install(FILES LICENSE DESTINATION .)

