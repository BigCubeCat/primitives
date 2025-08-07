set(PROJECT_NAME figures_lib)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME} STATIC
  abstract_shape.hpp
  drawable_iface.hpp
  figure_tag.hpp

  edge.hpp
  edge.cpp

  rectangle.hpp
  rectangle.cpp

  triangle.hpp
  triangle.cpp

  ellipse.hpp
  ellipse.cpp
)

target_link_libraries(${PROJECT_NAME} 
PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
)

target_compile_definitions(${PROJECT_NAME} PRIVATE CANVAS_LIBRARY)

