cmake_minimum_required(VERSION 3.13)

project(BilinearInterp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BilinearInterp
	main.cpp LookUpTable.cpp LookUpTable.h)

configure_file(lookupTab.txt lookupTab.txt COPYONLY)
