cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(APPLICATION_NAME openGLApplication)

set(OUTPUT_DIR_DEBUG "${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/Debug")
set(OUTPUT_DIR_RELEASE "${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/Release")

file(GLOB_RECURSE "APPLICATION_SOURCE" "${CMAKE_SOURCE_DIR}/examples/${APPLICATION_NAME}/src/*.cc")
file(GLOB_RECURSE "APPLICATION_HEADERS" "${CMAKE_SOURCE_DIR}/examples/${APPLICATION_NAME}/src/*.h")

foreach(item IN ITEMS ${APPLICATION_SOURCE} ${APPLICATION_HEADERS})
    get_filename_component(src_path "${item}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}" "" group_path "${src_path}")
    string(REPLACE "/" "\\" group_path "${group_path}")
    source_group("${group_path}" FILES "${item}")
endforeach()

if (WIN32)
    set(ICON ${CMAKE_CURRENT_SOURCE_DIR}/glfw.rc)
elseif (APPLE)
    set(ICON ${CMAKE_CURRENT_SOURCE_DIR}/glfw.icns)
endif()

set_source_files_properties(
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/Info.plist.in"
        PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
)

set_source_files_properties(
        "${ICON}"
        PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
)

set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/MainMenu.xib
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/
        )


add_executable(${APPLICATION_NAME} MACOSX_BUNDLE ${APPLICATION_SOURCE} ${APPLICATION_HEADERS} ${ICON} ${RESOURCES})
# Check if APPLE and build bundle & xib
if(APPLE)
set_source_files_properties(glfw.icns PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources")
set_target_properties(${APPLICATION_NAME} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER uk.co.mattwhitaker.${APPLICATION_NAME}
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Info.plist.in
        RESOURCE "${RESOURCES}"
        MACOSX_BUNDLE_BUNDLE_NAME ${APPLICATION_NAME}
        MACOSX_BUNDLE_ICON_FILE glfw.icns
        XCODE_ATTRIBUTE_ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon"
        XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym"
        XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS YES
        )
endif()

target_link_libraries(${APPLICATION_NAME} PRIVATE KaishiEngine)
target_include_directories(${APPLICATION_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/"
        "${CMAKE_SOURCE_DIR}/KaishiEngine/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glad/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glad/include/"
        "${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
        "${CMAKE_SOURCE_DIR}/vendor/imgui/"
        "${CMAKE_SOURCE_DIR}/vendor/stb/"
        )

set_target_properties(${APPLICATION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/Debug/")
set_target_properties(${APPLICATION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/Release/")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/${CMAKE_BUILD_TYPE}/")

if(APPLE)
## Make sure we can find the 'ibtool' program. If we can NOT find it we
# skip generation of this project
find_program(IBTOOL ibtool HINTS "/usr/bin" "${OSX_DEVELOPER_ROOT}/usr/bin")
if (${IBTOOL} STREQUAL "IBTOOL-NOTFOUND")
    message(SEND_ERROR "ibtool can not be found and is needed to compile the .xib files. It should have been installed with
                    the Apple developer tools. The default system paths were searched in addition to ${OSX_DEVELOPER_ROOT}/usr/bin")
endif()
#
## Make sure the 'Resources' Directory is correctly created before we build
add_custom_command (TARGET ${APPLICATION_NAME} PRE_BUILD
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/${CMAKE_BUILD_TYPE}/${APPLICATION_NAME}.app/Contents/Resources)

set(XIBS MainMenu)

## Compile the .xib files using the 'ibtool' program with the destination being the app package
foreach(xib ${XIBS})
    add_custom_command (TARGET ${APPLICATION_NAME} POST_BUILD
            COMMAND ${IBTOOL} --errors --warnings --notices --output-format human-readable-text
            --compile ${CMAKE_BINARY_DIR}/bin/examples/${APPLICATION_NAME}/${CMAKE_BUILD_TYPE}/${APPLICATION_NAME}.app/Contents/Resources/${xib}.nib
            ${CMAKE_CURRENT_SOURCE_DIR}/${xib}.xib
            COMMENT "Compiling ${CMAKE_CURRENT_SOURCE_DIR}/${xib}.xib")
endforeach()
endif()
