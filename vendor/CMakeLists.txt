cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Setting dependency settings

set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glm)

set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_BUILD_SAMPLES OFF)
set(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/assimp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/include/)

set(ALSOFT_DLOPEN OFF)
set(ALSOFT_UTILS OFF)
set(ALSOFT_EXAMPLES OFF)
set(ALSOFT_INSTALL_CONFIG OFF)
set(ALSOFT_INSTALL_HRTF_DATA OFF)
set(ALSOFT_INSTALL_AMBDEC_PRESETS OFF)
set(ALSOFT_INSTALL_EXAMPLES OFF)
set(ALSOFT_INSTALL_UTILS OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/openal/)

# Adding stb
file(GLOB "STB_HEADERS" "${CMAKE_CURRENT_SOURCE_DIR}/stb/*.h")
file(GLOB "STB_SOURCES" "${CMAKE_CURRENT_SOURCE_DIR}/stb/*.c")
add_library(stb STATIC ${STB_SOURCES} ${STB_HEADERS})
set_target_properties(stb PROPERTIES LINKER_LANGUAGE C)

# Adding imgui
file(GLOB "IMGUI_HEADERS" "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h")
file(GLOB "IMGUI_SOURCES" "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp")
add_library(imgui ${IMGUI_SOURCES} ${IMGUI_HEADERS})
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(glad PROPERTIES FOLDER vendor/glad)
set_target_properties(glfw PROPERTIES FOLDER vendor/glfw)
set_target_properties(imgui PROPERTIES FOLDER vendor/imgui)
set_target_properties(stb PROPERTIES FOLDER vendor/stb)
set_target_properties(assimp PROPERTIES FOLDER vendor/assimp)
