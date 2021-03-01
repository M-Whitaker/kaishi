//
// Created by Matt Whitaker on 28/02/2021.
//

#ifndef KAISHIENGINE_KAIPCH_H
#define KAISHIENGINE_KAIPCH_H

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>

#ifdef _WIN32
#include <Windows.h>
#define KAI_WINDOWS
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_OSX
#define KAI_MACOS
#elif TARGET_OS_IOS
#error "IOS NOT SUPPORTED"
#endif //TARGET_OS
#endif //__APPLE__

#endif //KAISHIENGINE_KAIPCH_H
