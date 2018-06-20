cmake_minimum_required(VERSION 2.8.3)
project(my_package)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)




add_message_files(
   FILES
   CalPosInfo.msg
   DriveInfo.msg
   my_msg.msg
   my_msg_2.msg
 )

set(PACKAGE_DEPENDENCIES
  eigen_conversions
  geometry_msgs
  cartographer_ros_msgs
  roscpp
  sensor_msgs
  nav_msgs
  tf2
  tf2_eigen
  tf2_ros
)

set(CMAKE_CXX_FLAGS "-pthread -std=c++11 -Wreorder")

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g -DNDEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(FATAL_ERROR "Cartographer is too slow to be useful in debug mode.")
else()
  message(FATAL_ERROR "Unknown CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

find_package(catkin REQUIRED COMPONENTS  ${PACKAGE_DEPENDENCIES})
include_directories(${catkin_INCLUDE_DIRS})

generate_messages(
   DEPENDENCIES
   std_msgs
 )

catkin_package(
  CATKIN_DEPENDS
    message_runtime
    ${PACKAGE_DEPENDENCIES}
)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

find_package(PCL REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})

find_package(cartographer REQUIRED)
include_directories(${CARTOGRAPHER_INCLUDE_DIRS})
link_directories(${CARTOGRAPHER_LIBRARY_DIRS})

find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIRS})

find_package(Boost REQUIRED
 COMPONENTS
 system
 iostreams
)
add_definitions(${BOOST_DEFINITIONS})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(cartographer_node_2
  src/test_unique.cpp
  src/map_writer.cc
  src/map_writer.h
  src/msg_conversion.cc
  src/msg_conversion.h
  src/node_options.cc
  src/node_options.h
  src/occupancy_grid.cc
  src/occupancy_grid.h
  src/ros_log_sink.cc
  src/ros_log_sink.h
  src/sensor_data.cc
  src/sensor_data.h
  src/sensor_data_producer.cc
  src/sensor_data_producer.h
  src/time_conversion.cc
  src/time_conversion.h
)
add_executable(client client/add_two_ints_client.cpp)



target_link_libraries(cartographer_node_2
  ${CARTOGRAPHER_LIBRARIES}
  ${PCL_LIBRARIES}
  ${catkin_LIBRARIES}
  gflags
  yaml-cpp
)
add_dependencies(cartographer_node_2
  ${catkin_EXPORTED_TARGETS}
  my_package_gencpp
)


target_link_libraries(client
  ${CARTOGRAPHER_LIBRARIES}
  ${PCL_LIBRARIES}
  ${catkin_LIBRARIES}
  gflags
  yaml-cpp
)
add_dependencies(client
  ${catkin_EXPORTED_TARGETS}
)
install(DIRECTORY launch urdf configuration_files
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS cartographer_node_2
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS client
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(PROGRAMS scripts/tf_remove_frames.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(talker src/talker.cc)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker ${catkin_EXPORTED_TARGETS})

add_executable(send_gps src/send_gps.cc)
target_link_libraries(send_gps ${catkin_LIBRARIES})
add_dependencies(send_gps ${catkin_EXPORTED_TARGETS})



