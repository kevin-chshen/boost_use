# CMakeList.txt: boost_app 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
#if (POLICY CMP0141)
  #cmake_policy(SET CMP0141 NEW)
  cmake_policy(SET CMP0074 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
#endif()

project ("boost_app")

set(BOOST_ROOT "E:/cpp_project/vcpkg/installed/x86-windows")
set(Boost_INCLUDE_DIR "${BOOST_ROOT}/include")
set(Boost_LIBRARIES_DIR "${BOOST_ROOT}/lib")

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
)

message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

# Find Boost
find_package(Boost REQUIRED COMPONENTS log system filesystem thread) # RQUIIRED找不到boost库会报错这里优先找了vcpkg的路径

source_group(headFile/ *.h)
include_directories(./)

# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 将源代码添加到此项目的可执行文件。
add_executable (boost_app ${DIR_SRCS})

message("Add Boost begin")

message("Boost_ROOT = ${Boost_ROOT}")
message("Boost_INCLUDE_DIR = ${Boost_INCLUDE_DIR}")
message("Boost_LIBRARIES = ${Boost_LIBRARIES}")
#add_library(boost_log-vc140-mt STATIC IMPORTED)
#set_target_properties(boost_log-vc140-mt PROPERTIES IMPORTED_LOCATION "${Boost_LIBRARIES}/boost_log-vc140-mt.lib")
# Add Boost include directories
include_directories(${Boost_INCLUDE_DIR})
target_include_directories(boost_app PUBLIC ${Boost_INCLUDE_DIR})
#Add Boost libraries
#target_link_libraries(boost_app PRIVATE boost_log-vc140-mt)
message("Add Boost end")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET boost_app PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。

