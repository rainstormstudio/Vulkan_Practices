#pragma once

// indices of queue families
struct QueueFamilyIndices {
    int graphicsFamily = -1;    // location of graphics queue family

    // check if queue families are valid
    bool isValid() {
        return graphicsFamily >= 0;
    }
};