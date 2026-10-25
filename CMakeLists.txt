# libsyncopate project config
# usage:
# (configure)
#   cmake --preset debug
# (build)
#   cmake --build --preset debug
# (lint/format)
#   cmake --build --preset debug --target format-check
#   cmake --build --preset debug --target tidy
# (tests)
#   ctest --preset debug

cmake_minimum_required(VERSION 3.25)
project(
    syncopate
    VERSION 0.1.0
    DESCRIPTION "C++23 library"
    LANGUAGES CXX
)


# compiled binary location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# require c++23 and disable compiler specific flags
set(CMAKE_CXX_STANDARD              23)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)


# libsyncopate sources
add_library(syncopate 
    "src/logger.cpp"
)
target_include_directories(syncopate PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


# compiler warning config
if(MSVC)
    target_compile_options(syncopate PRIVATE
        /W4
        /permissive-
    )
else()
    target_compile_options(syncopate PRIVATE
        -Wall
        -Wextra
    )
endif()


# developer tools
option(ENABLE_CLANG_FORMAT  "enable clang-format target" OFF)
option(ENABLE_CLANG_TIDY    "enable clang-tidy target" OFF)

include(cmake/format.cmake)
include(cmake/tidy.cmake)


# usage examples
option(SYNCOPATE_USAGE_EXAMPLES "Build libsyncopate examples" OFF)

if(SYNCOPATE_USAGE_EXAMPLES)
    add_subdirectory(examples)
endif()


# tests
option(SYNCOPATE_BUILD_TESTS "build libsyncopate tests" ON)
if(SYNCOPATE_BUILD_TESTS)
    include(CTest)

    # use googletest for test suites
    set(gtest_force_shared_crt  ON CACHE BOOL "" FORCE)
    set(BUILD_GMOCK             OFF CACHE BOOL "" FORCE)
    set(INSTALL_GTEST           OFF CACHE BOOL "" FORCE)
    set(GTEST_VER               "v1.18.0")

    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG ${GTEST_VER}
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(gtest)

    add_subdirectory(tests)
endif()