set(CANVASLIB_NAME canvas_lib)

add_library(${CANVASLIB_NAME} STATIC
  canvas.cpp
  canvas.hpp
)

target_link_libraries(${CANVASLIB_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets engine_lib)

target_include_directories(${CANVASLIB_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/lib
)