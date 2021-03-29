//
// Created by Matt Whitaker on 24/03/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_APPLE_C_INTERFACE_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_APPLE_C_INTERFACE_H_

#include "platform/platformDefinition.h"

#ifdef KAI_MACOS

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define OBJC_API(methodName) OBJC ## _ ## methodName

struct CocoaWindowInformation {
  bool darkMode;
  const char *title;
};

/**
 * This is the C "trampoline" function that will be used
 * to invoke a specific Objective-C method FROM C++
 * @param glfwWindow
 */
CocoaWindowInformation OBJC_API(createCocoaWindow)(GLFWwindow *glfwWindow);

#endif  // KAI_MACOS

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_APPLE_C_INTERFACE_H_
