cmake_minimum_required(VERSION 3.12)
project(CPP3)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP3 main.cpp FlightBooking.cpp FlightBooking.h FlightList.h FlightList.cpp FlightNode.h FlightNode.cpp)

