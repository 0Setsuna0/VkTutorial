# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_STANDARD 17)
project ("vk_tutorial")

set(SHADER_DIR "${CMAKE_SOURCE_DIR}/shader/")
set(ASSET_DIR "${CMAKE_SOURCE_DIR}/asset/")
add_definitions(-DSHADER_DIR="${SHADER_DIR}")
add_definitions(-DASSET_DIR="${ASSET_DIR}")

add_subdirectory ("src")
add_subdirectory ("3rd")
