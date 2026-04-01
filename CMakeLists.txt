cmake_minimum_required(VERSION 3.31.6)

# Define the project name and optionally a version
project(Jumpdrive VERSION 1.0) #

# Specify the C++ standard to use
set(CMAKE_CXX_STANDARD 23) #
set(CMAKE_CXX_STANDARD_REQUIRED True) #

# Setup Boost library
set(BOOST_VERSION 1.90.0)
find_package(Boost REQUIRED)
target_link_libraries(
  Jumpdrive PRIVATE Boost::boost
)
include_directories(${Boost_INCLUDE_DIRS})

# Jumpdrive specific files and build actions
file(GLOB SOURCE_FILES "*.cpp")
file(GLOB HEADER_FILES "*.h")
add_library(Jumpdrive STATIC ${SOURCE_FILES} ${HEADER_FILES}) #

# Set the directory for this specific target
set_target_properties(Jumpdrive PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Specify include directories for the library target
# The 'PUBLIC' keyword means both the library itself and consumers of the library need this include path
target_include_directories(Jumpdrive PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

