cmake_minimum_required(VERSION 3.20)
project(ProjetoDA1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjetoDA1 main.cpp Classes/Delivery.cpp Classes/Delivery.h Classes/Helper.cpp Classes/Helper.h Classes/Courier.cpp Classes/Courier.h Classes/Vehicle.cpp Classes/Vehicle.h)
