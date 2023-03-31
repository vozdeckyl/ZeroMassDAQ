
cmake_minimum_required(VERSION 3.18)

project(ZeroMassDAQ VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT DEFINED FULLSCREEN)
    set(FULLSCREEN 1)
endif()

configure_file(${PROJECT_SOURCE_DIR}/src/config.h.in ${PROJECT_SOURCE_DIR}/src/config.h)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cxx")


find_package(Boost 1.74 REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)


add_executable(zmdaq ${SOURCES})

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})

target_link_libraries(zmdaq pthread ${GTKMM_LIBRARIES} ${Boost_LIBRARIES})

add_custom_command(TARGET zmdaq PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/icons/png $<TARGET_FILE_DIR:zmdaq>/icons)

set(CPACK_PACKAGE_NAME "ZeroMassDAQ")

install(
    FILES
    ${CMAKE_SOURCE_DIR}/build/zmdaq
    ${CMAKE_SOURCE_DIR}/uninstall.sh
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_EXECUTE
    DESTINATION /usr/share/${CPACK_PACKAGE_NAME}
    )

install(
    FILES
    ${CMAKE_SOURCE_DIR}/build/icons
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ WORLD_WRITE
    DESTINATION /usr/share/${CPACK_PACKAGE_NAME}
    )

install(
    FILES
    ${CMAKE_SOURCE_DIR}/zeromassdaq.desktop
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    DESTINATION /usr/share/applications
    )

install(CODE "MESSAGE(\"
  Zero Mass DAQ has been installed.
  It can be uninstalled by running the following script:
    sudo /usr/share/ZeroMassDAQ/uninstall.sh \")"
  )
