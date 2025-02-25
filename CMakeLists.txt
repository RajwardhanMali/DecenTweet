cmake_minimum_required(VERSION 3.10)
project(decentweet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BLOCKCHAIN_CORE_DIR ${CMAKE_SOURCE_DIR}/blockchain-core)
include_directories(${BLOCKCHAIN_CORE_DIR}/include)

file(GLOB SOURCES
    ${BLOCKCHAIN_CORE_DIR}/src/*.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(decentweet ${SOURCES})