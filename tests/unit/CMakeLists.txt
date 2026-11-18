# unit test configs
add_executable(json_value_test json_value_test.cpp)
target_link_libraries(json_value_test PRIVATE syncopate GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(json_value_test)
