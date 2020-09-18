# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.11)

add_definitions(-w)

# 项目信息
project(test)

# 指定生成目标
add_executable(${PROJECT_NAME} example.cpp)
# 头文件包含路径
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#set ( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT" )
#set ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /MTd" )