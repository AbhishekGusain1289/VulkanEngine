#include "app.hpp"

App::~App(){
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

}
void App::mainLoop(){
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }
}