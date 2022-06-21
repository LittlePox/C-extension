cmake_minimum_required(VERSION 3.17)
#project(IndicatorGenerator)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-O2")

add_executable(Main test.cpp)
target_include_directories(Main PUBLIC C:/Users/user/AppData/Local/Programs/Python/Python38/Lib/site-packages/pybind11/include C:/Program Files/Python38/Lib/site-packages/pybind11/include C:/Users/user/AppData/Local/Programs/Python/Python38/include)
target_link_directories(Main PUBLIC C:/Users/user/AppData/Local/Programs/Python/Python38/libs C:/Users/user/AppData/Local/Programs/Python/Python38/PCbuild/amd64)
target_compile_options(Main PUBLIC /EHsc)
