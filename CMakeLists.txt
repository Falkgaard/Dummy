#pragma once
cmake_minimum_required ( VERSION 3.21 FATAL_ERROR )

# Configure project name and version here:
project (
	Dummy
	VERSION       0.1.0
	DESCRIPTION   "A Discord bot"
	LANGUAGES     C CXX
)

set ( CMAKE_EXPORT_COMPILE_COMMANDS ON ) # generate compile_commands.json

add_executable             ( ${PROJECT_NAME} "src/${PROJECT_NAME}/main.cpp" )
target_compile_features    ( ${PROJECT_NAME} PUBLIC cxx_std_20              )
target_include_directories ( ${PROJECT_NAME} PUBLIC "src/"                  )
set_target_properties      ( ${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF  )
#------------------------ External Dependencies: ---------------------------#
set( CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH} )
include ( cmake/CPM.cmake )
CPMAddPackage( "gh:yourWaifu/sleepy-discord#816b6f4cdf25369039fef34e7201ab49f0f219a0" )
target_link_libraries( ${PROJECT_NAME} PRIVATE sleepy-discord )

