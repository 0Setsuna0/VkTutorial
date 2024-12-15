# 查找 Vulkan 包
find_package(Vulkan REQUIRED)

# 将源代码添加到此项目的可执行文件。
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ./*.cpp ./*.h)

add_executable(vk_tutorial application.cpp ${srcs})

# 链接 Vulkan 和其他依赖库
target_link_libraries(vk_tutorial PUBLIC Vulkan::Vulkan)
target_link_libraries(vk_tutorial PUBLIC glfw)

# 设置头文件搜索路径
target_include_directories(vk_tutorial PUBLIC ${Vulkan_INCLUDE_DIRS})
target_include_directories(vk_tutorial PUBLIC ../srcs)
target_include_directories(vk_tutorial PRIVATE "${CMAKE_SOURCE_DIR}/3rd")
