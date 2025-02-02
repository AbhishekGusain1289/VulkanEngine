#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>


// std
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class App{
    public:
        void run();
        ~App();
    private:

        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;

        VkInstance instance;


        void initWindow();
        void initVulkan();
        void mainLoop();
        void createInstance();


        GLFWwindow* window;
};