//
// Created by Matt Whitaker on 28/02/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_KAIPCH_H_
#define KAISHIENGINE_INCLUDE_KAISHI_KAIPCH_H_

#include "stdio.h"

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
#endif  // TARGET_OS
#endif  // __APPLE__

#endif  // KAISHIENGINE_INCLUDE_KAISHI_KAIPCH_H_
