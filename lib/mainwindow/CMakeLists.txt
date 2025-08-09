find_package(Qt6 6.2 REQUIRED COMPONENTS Core Widgets UiTools)

qt6_wrap_ui(UI_HEADERS mainwindow.ui)

add_library(mainwindow STATIC
        mainwindow.cpp
        mainwindow.hpp
        ${UI_HEADERS}
)

target_link_libraries(mainwindow
        PUBLIC
        Qt6::Core
        Qt6::Widgets
        PRIVATE
        canvas_lib
        utils_lib
        engine_lib
)

target_include_directories(mainwindow PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(mainwindow PROPERTIES
        AUTOMOC ON
        AUTOUIC OFF
        AUTORCC OFF
)

target_include_directories(mainwindow
        PUBLIC
        ${CMAKE_SOURCE_DIR}/lib
)