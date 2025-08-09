set(UTILSLIB_NAME utils_lib)

add_library(${UTILSLIB_NAME} STATIC
        serialization.hpp
        serialization.cpp
        io.cpp
        io.hpp
)

target_link_libraries(${UTILSLIB_NAME}
        PRIVATE engine_lib
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${UTILSLIB_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/lib
)
