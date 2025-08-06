cmake_minimum_required(VERSION 3.19)
set(PROJECT_NAME figures)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt6_add_resources(RESOURCES resources.qrc)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME}
    WIN32 MACOSX_BUNDLE
    main.cpp
    ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
        mainwindow
)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_subdirectory(lib/mainwindow)
# add_subdirectory(lib/canvas)
# add_subdirectory(lib/tools)

