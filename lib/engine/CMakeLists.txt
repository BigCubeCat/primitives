set(PROJECT_NAME engine_lib)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME} STATIC

  figures/abstract_shape.hpp
  figures/drawable_iface.hpp
  figures/figure_tag.hpp
  figures/edge.hpp
  figures/edge.cpp
  figures/rectangle.hpp
  figures/rectangle.cpp
  figures/triangle.hpp
  figures/triangle.cpp
  figures/ellipse.hpp
  figures/ellipse.cpp

  scene.hpp
  scene.cpp
)

target_link_libraries(${PROJECT_NAME} 
PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
)

target_compile_definitions(${PROJECT_NAME} PRIVATE CANVAS_LIBRARY)

