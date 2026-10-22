target_sources(${PROJECT_NAME}
    PRIVATE
    math_func.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
