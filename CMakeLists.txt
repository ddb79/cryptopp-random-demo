cmake_minimum_required(VERSION 3.10)
project(demoRandom)

set(CMAKE_CXX_STANDARD 11)

link_directories(cryptopp)

add_executable(main.exe main.cpp )
target_link_libraries(main.exe libcryptopp.a)