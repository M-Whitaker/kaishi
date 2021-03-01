cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(OUTPUT_DIR_DEBUG "${CMAKE_BINARY_DIR}/bin/examples/openGLApplication/Debug")
set(OUTPUT_DIR_RELEASE "${CMAKE_BINARY_DIR}/bin/examples/openGLApplication/Release")

file(GLOB_RECURSE "APPLICATION_SOURCE" "${CMAKE_SOURCE_DIR}/examples/openGLApplication/src/*.cc")
file(GLOB_RECURSE "APPLICATION_HEADERS" "${CMAKE_SOURCE_DIR}/examples/openGLApplication/src/*.h")

foreach(item IN ITEMS ${APPLICATION_SOURCE} ${APPLICATION_HEADERS})
    get_filename_component(src_path "${item}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}" "" group_path "${src_path}")
    string(REPLACE "/" "\\" group_path "${group_path}")
    source_group("${group_path}" FILES "${item}")
endforeach()

add_executable(openGLApplication ${APPLICATION_SOURCE} ${APPLICATION_HEADERS})

target_link_libraries(openGLApplication PRIVATE KaishiEngine)
target_include_directories(openGLApplication PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/"
        "${CMAKE_SOURCE_DIR}/KaishiEngine/src/"
        "${CMAKE_SOURCE_DIR}/vendor/glad/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glad/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
        "${CMAKE_SOURCE_DIR}/vendor/imgui/"
        "${CMAKE_SOURCE_DIR}/vendor/stb/"
        )

set_target_properties(openGLApplication PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/examples/openGLApplication/Debug/")
set_target_properties(openGLApplication PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/examples/openGLApplication/Release/")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}/bin/examples/openGLApplication/${CMAKE_BUILD_TYPE}/")
