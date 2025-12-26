cmake_minimum_required(VERSION 3.10)
project(SystemProgrammingProject)

set(CMAKE_CXX_STANDARD 17)

# Find the PostgreSQL C++ library
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# Include directories
include_directories(include)
include_directories(${PQXX_INCLUDE_DIRS})

# Define the executable
add_executable(sysprog_app src/main.cpp)

# Link the libraries
target_link_libraries(sysprog_app PRIVATE ${PQXX_LIBRARIES})
