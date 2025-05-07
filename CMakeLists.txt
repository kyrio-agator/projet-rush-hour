cmake_minimum_required(VERSION 3.18)
project(rush-hour)

add_compile_options(-Wall)

find_package(SFML COMPONENTS graphics window system)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(C:\\SFML-2.5.0\\lib)

add_executable(${PROJECT_NAME}
    src/generate.cpp
    src/interface.cpp
    src/main.cpp
    src/move.cpp
    src/solve.cpp
    src/type.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)