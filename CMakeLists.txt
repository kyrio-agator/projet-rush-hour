find_package(SFML COMPONENTS graphics window system)


target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-graphics sfml-window sfml-system)   