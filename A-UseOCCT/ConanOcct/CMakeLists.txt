cmake_minimum_required(VERSION 2.8.12)
project(ConanOcct)

# 让find_package找到conan安装的包
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build)  #添加到find_package module模式搜索路径
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/build)  #添加到find_package config模式搜索路径

set(OpenCASCADE_BUILD_WITH_DEBUG ON)
find_package(OpenCASCADE
COMPONENTS
  FoundationClasses
  # ModelingAlgorithms
  # ModelingData
  # DataExchange
  # Visualization
REQUIRED
)
# message(STATUS ${OpenCASCADE_LIBRARIES})
# message(STATUS ${OpenCASCADE_LIBRARY_DIR})
# message(STATUS ${OpenCASCADE_INCLUDE_DIR})

set(Project_Src_Dir ${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE files "${Project_Src_Dir}/*.cpp")
add_executable(${PROJECT_NAME} ${files})
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCASCADE_INCLUDE_DIR})
link_directories(${OpenCASCADE_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} ${OpenCASCADE_LIBRARIES})