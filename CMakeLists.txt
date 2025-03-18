set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(MYCOMPILE_FLAGS "-Wall -Wextra -g")

add_executable(run main.cpp)

add_library(graph graph.cpp)

target_link_libraries(run graph)