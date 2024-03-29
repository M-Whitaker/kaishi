cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(APPLE)
project(KaishiEngine LANGUAGES C CXX OBJC)
else()
project(KaishiEngine LANGUAGES C CXX)
endif()

# Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(COMMON_CXX_FLAGS "${COMMON_CXX_FLAGS} -g3 -O0 -Wall -pedantic -Wextra -m64 -mavx2 -mfma -ffast-math")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(COMMON_CXX_FLAGS "${COMMON_CXX_FLAGS}   -Wall -pedantic -Wextra -m64 -mavx2 -mfma -ffast-math")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(COMMON_CXX_FLAGS "${COMMON_CXX_FLAGS}  /std:c++17 /W4 /arch:AVX2 /fp:fast /MP /DNOMINMAX")
endif()

# Definitions
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    add_definitions(-DHP_RELEASE)
else()
    add_definitions(-DHP_DEBUG)
endif()

# Dependencies
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor)

# Projects
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/KaishiEngine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples/openGLApplication)

# Visual Studio
#set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT KaishiEngine)