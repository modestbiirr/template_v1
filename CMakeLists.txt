cmake_minimum_required(VERSION 2.8.3)
project(template_v1)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  roscpp
  rospy
)

add_message_files(
  DIRECTORY msg
  FILES
  Temp1.msg
)

generate_messages(DEPENDENCIES )

catkin_package(CATKIN_DEPENDS message_runtime )

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(example_pub src/example_pub.cpp)
add_executable(example_sub src/example_sub.cpp)
target_link_libraries(example_pub ${catkin_LIBRARIES})
target_link_libraries(example_sub ${catkin_LIBRARIES})

