set(ENGINELIB_NAME engine_lib)

project(${ENGINELIB_NAME} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${ENGINELIB_NAME} STATIC
        figures/AbstractObject.hpp
        figures/IObject.hpp
        figures/tag.hpp
        figures/TEdge.hpp
        figures/TEdge.cpp
        figures/rectangle.hpp
        figures/rectangle.cpp
        figures/triangle.hpp
        figures/triangle.cpp
        figures/ellipse.hpp
        figures/ellipse.cpp

        TObjectContainer.hpp
        TObjectContainer.cpp
        TObjectFactory.cpp
        TObjectFactory.hpp
        TScene.cpp
        TScene.hpp
        policy/AbstractPolicy.hpp
        policy/TMovePolicy.cpp
        policy/TMovePolicy.hpp
        policy/TJoinPolicy.cpp
        policy/TJoinPolicy.hpp
        policy/TDeletePolicy.cpp
        policy/TDeletePolicy.hpp
        policy/TCreatePolicy.cpp
        policy/TCreatePolicy.hpp
)

target_link_libraries(${ENGINELIB_NAME}
        PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${ENGINELIB_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/lib
)