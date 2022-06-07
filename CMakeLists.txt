cmake_minimum_required(VERSION 3.22)
project(second_task)

set(CMAKE_CXX_STANDARD 14)

add_executable(second_task main.cpp RingBuffer.h RingBufferException.h)
