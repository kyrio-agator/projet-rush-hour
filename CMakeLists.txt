cmake_minimum_required(VERSION 3.18)
project(rush-hour)

add_compile_options(-Wall)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME}.out
    generate.cpp
    gennewplateau.cpp
    interface.cpp
    main.cpp
    move.cpp
    solve.cpp
)