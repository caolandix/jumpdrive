cmake_minimum_required(VERSION 3.12)

# Define the project name and optionally a version
project(Jumpdrive VERSION 1.0) #

# Specify the C++ standard to use
set(CMAKE_CXX_STANDARD 23) #
set(CMAKE_CXX_STANDARD_REQUIRED True) #

# Add a library target, specifying its name and source files
# STATIC or SHARED can be explicitly set, or omitted to let CMake decide based on BUILD_SHARED_LIBS
add_library(Jumpdrive STATIC ./*.cpp ./*.h) #

# Specify include directories for the library target
# The 'PUBLIC' keyword means both the library itself and consumers of the library need this include path
target_include_directories(Jumpdrive PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Optional: Install the library for external use (makes it "findable" by other projects)
install(TARGETS Jumpdrive DESTINATION lib)
install(FILES ./*.h DESTINATION include)
