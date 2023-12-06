cmake_minimum_required(VERSION 3.22.1)
project(dbserver)

find_package(pybind11 REQUIRED)

pybind11_add_module(py_dbserver py_dbserver.cpp)
set_property(TARGET py_dbserver PROPERTY CXX_STANDARD 11)
