cmake_minimum_required(VERSION 3.14)

# Define the project name and optionally a version
project(Jumpdrive VERSION 1.0) #
set(BOOST_VERSION 1.90.0)

include(FetchContent)
FetchContent_Declare(
  boost
  GIT_REPOSITORY https://github.com/boostorg/boost
  GIT_TAG        boost-${BOOST_VERSION}
  # Use the specific CMake support infrastructure from boostorg/cmake repo for better integration
  SOURCE_DIR     ${CMAKE_BINARY_DIR}/_deps/boost-src
)
FetchContent_MakeAvailable(boost)

# Specify the C++ standard to use
set(CMAKE_CXX_STANDARD 23) #
set(CMAKE_CXX_STANDARD_REQUIRED True) #

file(GLOB SOURCE_FILES "*.cpp")
file(GLOB HEADER_FILES "*.h")

# Add a library target, specifying its name and source files
# STATIC or SHARED can be explicitly set, or omitted to let CMake decide based on BUILD_SHARED_LIBS
add_library(Jumpdrive STATIC ${SOURCE_FILES} ${HEADER_FILES}) #
target_link_libraries(Jumpdrive PRIVATE Boost::system Boost::filesystem Boost::multi_index)
# Specify include directories for the library target
# The 'PUBLIC' keyword means both the library itself and consumers of the library need this include path
target_include_directories(Jumpdrive PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Optional: Install the library for external use (makes it "findable" by other projects)
install(TARGETS Jumpdrive DESTINATION lib)
install(FILES ./*.h DESTINATION include)
