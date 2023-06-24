# CMakeList.txt: cmake_app 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("cmake_app")

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
)

message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")


# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 将源代码添加到此项目的可执行文件。
add_executable (cmake_app ${DIR_SRCS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cmake_app PROPERTY CXX_STANDARD 20)
endif()

# 生成安装包
# include(InstallRequiredSystemLibraries)
# 中级用set 插入版本信息
# set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
# set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
# include (CPack)

# TODO: 如有需要，请添加测试并安装目标。
