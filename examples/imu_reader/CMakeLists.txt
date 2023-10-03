cmake_minimum_required(VERSION 2.8.4)
project(imu_reader)

set(CMAKE_SUPPRESS_REGENERATION TRUE)

add_subdirectory(../.. libvncxx)

if(CMAKE_COMPILER_ID MATCHES "GNU|Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(SOURCE_FILES
    main.cpp)

include_directories(../../include)

add_executable(imu_reader ${SOURCE_FILES})

target_link_libraries(imu_reader PRIVATE libvncxx)

if (UNIX OR APPLE)
	target_link_libraries(imu_reader LINK_PUBLIC pthread)
else()
	target_link_libraries(imu_reader LINK_PUBLIC Advapi32 SetupAPI)
endif()
