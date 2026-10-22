target_sources(${PROJECT_NAME}
    PRIVATE
    main.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(tests)
add_subdirectory(utils)
add_subdirectory(pub)
add_subdirectory(student)
