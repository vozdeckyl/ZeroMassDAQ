
cmake_minimum_required(VERSION 3.22)

project(ZeroMassDAQ VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cxx")


find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)


add_executable(zmdaq ${SOURCES})

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

target_link_libraries(zmdaq ${GTKMM_LIBRARIES})

add_custom_command(TARGET zmdaq PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/icons/png $<TARGET_FILE_DIR:zmdaq>/icons)
