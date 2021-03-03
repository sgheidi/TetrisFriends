cmake_minimum_required(VERSION 2.8)

project(TetrisFriends)

FILE(
GLOB SOURCE_FILES
src/*.h
src/core/*.h
src/tetronimos/*.h
src/*.cc
src/core/*.cc
src/tetronimos/*.cc
)

add_executable(
    TetrisFriends
    ${SOURCE_FILES})

# Find OpenGL
find_package(OpenGL)
include_directories(${OPENGL_INCLUDE_DIRS})

add_subdirectory(deps/glfw-3.3.2)
include_directories(deps/glfw-3.3.2/include)
target_link_libraries(TetrisFriends glfw
    ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
