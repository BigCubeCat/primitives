find_package(GTest REQUIRED)
set(TESTS_EXECUTABLE_NAME figures_test)

add_executable(${TESTS_EXECUTABLE_NAME}
        main.cc
)

target_link_libraries(${TESTS_EXECUTABLE_NAME} PRIVATE
        figures_lib
        GTest::gtest_main
        Threads::Threads
        Qt::Core
        Qt::Widgets
)

target_include_directories(${TESTS_EXECUTABLE_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/figures
)

add_test(NAME ${TESTS_EXECUTABLE_NAME} COMMAND ${TESTS_EXECUTABLE_NAME})

