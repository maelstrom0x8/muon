cmake_minimum_required(VERSION 3.14)

project(muon LANGUAGES CXX)
set(MUON_VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(Qt6 6.2 COMPONENTS Core Quick Sql QuickControls2 REQUIRED)
add_subdirectory(muon)

option(MUON_BUILD_TESTS "Build all muon's tests" OFF)
mark_as_advanced(MUON_BUILD_TESTS)

if(MUON_BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)
  add_subdirectory(tests)
endif()