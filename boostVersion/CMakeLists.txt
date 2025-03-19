# --- Settings ---
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_compile_options(-Wall -Wextra -g)
# ----------------

# --- Finding ---
find_package(Boost REQUIRED)
#----------------

# --- Assembling ---
add_executable(run main.cpp)

target_link_libraries(run boost::boost)