cmake_minimum_required(VERSION 3.24)
project(fcpp_code_examples)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
add_executable(fcpp_code_examples main.cpp)
target_link_libraries(fcpp_code_examples
        PRIVATE
        fmt::fmt-header-only
        nlohmann_json::nlohmann_json
        range-v3::meta range-v3::concepts range-v3::range-v3
        Catch2::Catch2 Catch2::Catch2WithMain
)

