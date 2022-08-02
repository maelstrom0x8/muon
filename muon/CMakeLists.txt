cmake_minimum_required(VERSION 3.14)

project(muon VERSION ${MUON_VERSION} LANGUAGES CXX)

set(RESOURCE_DIR "${muon_SOURCE_DIR}/res")
set(INCLUDE_DIR "${muon_SOURCE_DIR}/include")
set(SOURCE_DIR "${muon_SOURCE_DIR}/src")

include_directories(
  ${RESOURCE_DIR}
  ${INCLUDE_DIR}
  ${SOURCE_DIR}
)


file(GLOB_RECURSE MUON_SOURCES
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cc"
)

add_library(muon STATIC ${MUON_SOURCES} )

target_link_libraries(muon PRIVATE Qt6::Core Qt6::Quick Qt6::Sql Qt6::QuickControls2)

target_compile_definitions(muon PRIVATE MUON_LIBRARY)


file(GLOB_RECURSE SOURCES
    "${RESOURCE_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cc"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${RESOURCE_DIR})

qt_add_executable(muon-main
    MANUAL_FINALIZATION
    app_main.cc
    qml/qml.qrc
)

target_include_directories(muon-main PUBLIC ${MUON_INCLUDE_DIRS})
target_link_directories(muon-main PUBLIC ${MUON_INCLUDE_DIRS})

target_compile_definitions(muon-main
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

if(CMAKE_BUILD_TYPE STREQUAL "Asan")  
  target_compile_options(muon-main PRIVATE -fsanitize=address -ltag)
  target_link_options(muon-main PRIVATE -fsanitize=address -ltag)
endif(CMAKE_BUILD_TYPE STREQUAL "Asan")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(muon-main PRIVATE -g -O3 -ltag)
  target_link_options(muon-main PRIVATE -g -O3 -ltag)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")


if(CMAKE_BUILD_TYPE STREQUAL "Tsan")
  target_compile_options(muon-main PRIVATE -fsanitize=thread)
  target_link_options(muon-main PRIVATE -fsanitize=thread)
endif(CMAKE_BUILD_TYPE STREQUAL "Tsan")

target_link_libraries(muon-main PUBLIC muon)

set_target_properties(muon-main PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER muon.xio.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(muon-main)
    qt_finalize_executable(muon-main)
endif()
