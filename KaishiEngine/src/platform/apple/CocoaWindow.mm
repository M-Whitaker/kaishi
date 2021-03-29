//
// Created by Matt Whitaker on 24/03/2021.
//

#include "platform/platformDefinition.h"

#ifdef KAI_MACOS

#import "platform/apple/CocoaWindow.h"

@implementation KaishiWindowController

- (CocoaWindowInformation)editNativeWindow:(GLFWwindow *)glfwWindow {
  NSWindow *window = glfwGetCocoaWindow(glfwWindow);
  NSApplication *app = [NSApplication sharedApplication];
  NSMenu *mainMenu = [app mainMenu];

  CocoaWindowInformation windowInfo{};
  windowInfo.title = window.title.UTF8String;
  if (@available(macOS 10.14, *))
    windowInfo.darkMode = app.effectiveAppearance.name == NSAppearanceNameDarkAqua;
  else
    windowInfo.darkMode = false;

  return windowInfo;
}

- (IBAction)openFileMenu:(id)sender {
  NSOpenPanel *panel = [NSOpenPanel openPanel];
  
  NSLog(@"Cococa Window");

  [panel beginWithCompletionHandler:^(NSInteger result) {
    if (result == NSModalResponseOK) {
      NSURL *theDoc = [panel URLs][0];

      // Open  the document.
      NSLog(@"%@", theDoc);
    }
  }];
}

@end

CocoaWindowInformation OBJC_API(createCocoaWindow)(GLFWwindow *glfwWindow) {
  KaishiWindowController *windowController = [[KaishiWindowController alloc] init];
  CocoaWindowInformation windowInfo = [windowController editNativeWindow:(glfwWindow)];
  [windowController release];
  return windowInfo;
}

#endif  // KAI_MACOS
