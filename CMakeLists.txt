cmake_minimum_required(VERSION 3.27...3.31)

project(MapGenerator
    VERSION 0.0.1
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTING "Build the testing tree" ON)
option(BUILD_CLI "Build the command line interface" OFF)

include(FetchContent)

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
	-Wall
	-Wextra
	-Wpedantic
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
  MAP_GEN_LIB_VERSION_STR="${PROJECT_VERSION}"
  MAP_GEN_LIB_NAME=${PROJECT_NAME}
  MAP_GEN_LIB_NAMESPACE=MAP_GEN_LIB
  MAP_GEN_LIB_NAME_STR="${PROJECT_NAME}"
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

add_library(sanitizers INTERFACE)

target_compile_options(sanitizers INTERFACE
    -fsanitize=address,undefined
    -fno-omit-frame-pointer
)

target_link_options(sanitizers INTERFACE
    -fsanitize=address,undefined
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME} PUBLIC sanitizers)
endif()

if(BUILD_CLI)
    FetchContent_Declare(
        cli11
        URL https://github.com/CLIUtils/CLI11/archive/refs/tags/v2.4.1.tar.gz
    )

    FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
    )

    FetchContent_MakeAvailable(cli11 json)

    file(GLOB_RECURSE CLI_SOURCES CONFIGURE_DEPENDS "cli/*.cpp")
    add_executable(${PROJECT_NAME}_cli ${CLI_SOURCES})

    target_link_libraries(${PROJECT_NAME}_cli PRIVATE
        ${PROJECT_NAME}::${PROJECT_NAME}
        CLI11::CLI11
        nlohmann_json::nlohmann_json
    )

    if (BUILD_CLI AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    	target_link_libraries(${PROJECT_NAME}_cli PRIVATE sanitizers)
    endif()

    set_target_properties(${PROJECT_NAME}_cli PROPERTIES
        OUTPUT_NAME "mapgen"
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
    )
endif()

if(PROJECT_IS_TOP_LEVEL AND BUILD_TESTING)
    enable_testing()

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)

    file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp" "tests/*.c")
    add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

    target_link_libraries(${PROJECT_NAME}_tests PRIVATE
        ${PROJECT_NAME}::${PROJECT_NAME}
        GTest::gtest_main
        pthread
    )

    if (BUILD_CLI AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    	target_link_libraries(${PROJECT_NAME}_tests PRIVATE sanitizers)
    endif()

    set_target_properties(${PROJECT_NAME}_tests PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
    )

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}_tests)
endif()
