#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "utilities.hpp"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstring>

class VulkanRenderer {
private:
    GLFWwindow *window;

    // Vulkan components
    VkInstance instance;
    struct {
        VkPhysicalDevice physicalDevice;
        VkDevice logicalDevice;
    } mainDevices;
    VkQueue graphicsQueue;

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    #ifdef NDEBUG
        const bool enableValidationLayers = false;
    #else
        const bool enableValidationLayers = true;
    #endif

    bool checkValidationLayerSupport();

    void createInstance();

    void getPhysicalDevice();
    void createLogicalDevice();

    bool checkInstanceExtensionSupport(std::vector<const char *> *checkExtensions);
    bool checkDeviceSuitable(VkPhysicalDevice device);

    QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
public:
    VulkanRenderer();

    int init(GLFWwindow* newWindow);
    void cleanup();

    ~VulkanRenderer();
};