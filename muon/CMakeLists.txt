cmake_minimum_required(VERSION 3.14)

project(muon VERSION ${MUON_VERSION} LANGUAGES CXX)

set(MUON_INCLUDE_DIRS "${muon_SOURCE_DIR}/include")

message(${muon_SOURCE_DIR})

set(PROJECT_SOURCES 
  src/main.cc
  src/muon.cc
  src/trackmodel.cc
  include/muon.h
  include/trackmodel.h
  qml/qml.qrc
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${RESOURCE_DIR})
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -ltag")

qt_add_executable(main
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_include_directories(main PUBLIC ${MUON_INCLUDE_DIRS})
target_link_directories(main PUBLIC ${MUON_INCLUDE_DIRS})

target_compile_definitions(main
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

if(CMAKE_BUILD_TYPE STREQUAL "Asan")  
  target_compile_options(main PRIVATE -fsanitize=address)
  target_link_options(main PRIVATE -fsanitize=address)
endif(CMAKE_BUILD_TYPE STREQUAL "Asan")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(main PRIVATE -g -O3)
  target_link_options(main PRIVATE -g -O3)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")


if(CMAKE_BUILD_TYPE STREQUAL "Tsan")
  target_compile_options(main PRIVATE -fsanitize=thread)
  target_link_options(main PRIVATE -fsanitize=thread)
endif(CMAKE_BUILD_TYPE STREQUAL "Tsan")

target_link_libraries(main PUBLIC Qt6::Core Qt6::Quick Qt6::QuickControls2 Qt6::Sql)

set_target_properties(main PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER muon.xio.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(main)
    qt_finalize_executable(main)
endif()
