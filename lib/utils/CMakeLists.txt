set(PROJECT_NAME utils_lib)

add_library(${PROJECT_NAME} STATIC
        serialization.hpp
        serialization.cpp
        io.cpp
        io.hpp
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE engine_lib
        Qt${QT_VERSION_MAJOR}::Widgets
)
