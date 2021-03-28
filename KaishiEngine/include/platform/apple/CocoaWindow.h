//
// Created by Matt Whitaker on 24/03/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_APPLE_COCOAWINDOW_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_APPLE_COCOAWINDOW_H_

#include <Cocoa/Cocoa.h>

#define GLFW_INCLUDE_NONE
#import <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_COCOA
#import <GLFW/glfw3native.h>

#import "platform/apple/c.interface.h"

@interface KaishiWindowController : NSWindowController

/**
 *
 * @param glfwWindow
 */
- (CocoaWindowInformation)editNativeWindow:(GLFWwindow *)glfwWindow;

/**
 *
 * @param sender
 */
- (IBAction)openFileMenu:(id)sender;

@end

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_APPLE_COCOAWINDOW_H_
