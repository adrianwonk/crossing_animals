target_sources(${PROJECT_NAME}
    PRIVATE
    main.c
    math_func.c
    pub.c
    student.c
    test_pub.c
    test_students.c
    test_put_students_in_pub.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
