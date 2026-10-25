add_executable(ci_test
    ci_test.cpp
)

target_link_libraries(ci_test
    PRIVATE
        syncopate
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ci_test)