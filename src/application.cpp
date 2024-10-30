#include <iostream>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

int main() {
    // 初始化 GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return -1;
    }

    // 检查 GLFW 是否支持 Vulkan
    if (!glfwVulkanSupported()) {
        std::cerr << "GLFW does not support Vulkan." << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "GLFW and Vulkan are successfully configured." << std::endl;

    // 创建一个 GLFW 窗口（可选，用于确认窗口创建功能正常）
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // 不创建 OpenGL 上下文
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    // 使用 Vulkan API 获取实例扩展
    uint32_t extensionCount = 0;
    const char** extensions = glfwGetRequiredInstanceExtensions(&extensionCount);

    std::cout << "Required Vulkan extensions:" << std::endl;
    for (uint32_t i = 0; i < extensionCount; ++i) {
        std::cout << "  " << extensions[i] << std::endl;
    }

    // 创建 Vulkan 实例
    VkInstance instance;
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan GLFW Test";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = extensionCount;
    createInfo.ppEnabledExtensionNames = extensions;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    std::cout << "Vulkan instance created successfully." << std::endl;

    // 清理资源
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
