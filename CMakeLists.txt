cmake_minimum_required(VERSION 3.18)
project(rush-hour)

add_compile_options(-Wall)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
find_package(SFML COMPONENTS graphics window system)


add_executable(${PROJECT_NAME}
    src/generate.cpp
    src/gennewplateau.cpp
    src/interface.cpp
    src/main.cpp
    src/move.cpp
    src/solve.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)