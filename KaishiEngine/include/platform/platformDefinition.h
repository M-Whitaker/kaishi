//
// Created by Matt Whitaker on 29/03/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_PLATFORMDEFINITION_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_PLATFORMDEFINITION_H_

#ifdef _WIN32
#define KAI_WINDOWS
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_OSX
#define KAI_MACOS
#define USER_CONFIG_FOLDER "~/Library/application support/KaishiEngine"
#elif TARGET_OS_IOS
#error "IOS NOT SUPPORTED"
#endif  // TARGET_OS
#endif  // __APPLE__

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_PLATFORMDEFINITION_H_
