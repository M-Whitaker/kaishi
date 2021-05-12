cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

file(GLOB_RECURSE "ENGINE_SOURCE" "${CMAKE_SOURCE_DIR}/KaishiEngine/src/*.cc"
        "${CMAKE_SOURCE_DIR}/KaishiEngine/src/*.mm")
file(GLOB_RECURSE "ENGINE_HEADERS" "${CMAKE_SOURCE_DIR}/KaishiEngine/include/*.h")

foreach (item IN ITEMS ${ENGINE_SOURCE} ${ENGINE_HEADERS})
    get_filename_component(src_path "${item}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}" "" group_path "${src_path}")
    string(REPLACE "/" "\\" group_path "${group_path}")
    source_group("${group_path}" FILES "${item}")
endforeach ()


add_library(KaishiEngine ${ENGINE_SOURCE} ${ENGINE_HEADERS})
target_include_directories(KaishiEngine PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include/"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/Kaishi/"
        "${CMAKE_SOURCE_DIR}/vendor/glad/include/"
        "${CMAKE_SOURCE_DIR}/vendor/openal/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
        "${CMAKE_SOURCE_DIR}/vendor/imgui/"
        "${CMAKE_SOURCE_DIR}/vendor/stb/"
        )

target_precompile_headers(KaishiEngine PRIVATE ${CMAKE_SOURCE_DIR}/KaishiEngine/include/Kaishi/kaipch.h)
file(GLOB_RECURSE "OBJC_SOURCE" "${CMAKE_SOURCE_DIR}/*.mm")
set_source_files_properties(${OBJC_SOURCE} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

set_target_properties(KaishiEngine PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/KaishiEngine/Debug/")
set_target_properties(KaishiEngine PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/KaishiEngine/Release/")

message(STATUS "Searching for Vulkan")
find_package(Vulkan)


target_link_libraries(KaishiEngine PUBLIC glad OpenAL glfw glm imgui assimp stb)


if (NOT Vulkan_FOUND)
    message(STATUS "Vulkan not found.")
    target_compile_definitions(KaishiEngine PUBLIC GLFW_INCLUDE_NONE)
else ()
    message(STATUS "Vulkan found.")
    set(KAISHI_VULKAN_BUILD 1)
    target_link_libraries(KaishiEngine PUBLIC Vulkan::Vulkan)
    target_compile_definitions(KaishiEngine PUBLIC HP_SUPPORT_VULKAN)
endif ()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    message(STATUS ${CMAKE_BUILD_TYPE})
    set(KAISHI_DEBUG 1)
endif()

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h")

file(READ ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h filedata)
string(REGEX REPLACE "#CMAKE_GENERATOR" "${CMAKE_GENERATOR}" filedata "${filedata}")
string(REGEX REPLACE "#CMAKE_VERSION" "${CMAKE_VERSION}" filedata "${filedata}")
file(WRITE  ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h "${filedata}")
