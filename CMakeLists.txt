cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_EXTENSIONS OFF)

# 3. Project declaration
project(main
    VERSION 1.0.0
    LANGUAGES C
)

include(FetchContent)

FetchContent_Declare(
    color_log
    GIT_REPOSITORY https://github.com/adrianwonk/color_log.git
    GIT_TAG v5
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(color_log)

# 5. Locate system ncurses installation
find_package(Curses REQUIRED)

# 6. Declare executable build target
add_executable(${PROJECT_NAME})

add_subdirectory(src)

# 7. Link ncurses libraries and include header search paths
target_link_libraries(${PROJECT_NAME} PRIVATE color_log::color_log)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})
