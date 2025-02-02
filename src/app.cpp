#include "app.hpp"

App::~App(){
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void App::run(){
    initWindow();
    initVulkan();
    mainLoop();
}
void App::initWindow(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "VULKAN WINDOW", nullptr, nullptr);
}

void App::initVulkan(){
    createInstance();
}
void App::mainLoop(){
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }
}


// As you'll see, the general pattern that object creation function parameters in Vulkan follow is:

// Pointer to struct with creation info
// Pointer to custom allocator callbacks, always nullptr in this tutorial
// Pointer to the variable that stores the handle to the new object


void App::createInstance(){
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Test App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Test Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    VkResult result =vkCreateInstance(&createInfo, nullptr, &instance);
    
    // To check extensions
    // std::cout << "GLFW Extensions (" << glfwExtensionCount << "):" << std::endl;
    // for (uint32_t i = 0; i < glfwExtensionCount; ++i) {
    //     std::cout << glfwExtensions[i] << std::endl;
    // };


    if(result != VK_SUCCESS){
        throw std::runtime_error("Failed to create instance");
    }
    
}