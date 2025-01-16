cmake_minimum_required(VERSION 3.11)
include(FetchContent)

project(c++_essential_training
        VERSION 1.0.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find packages locally
# find_package(PACKAGE_NAME)

# Find cmake fetchable dependancies used for all projects
# FetchContent_Declare(json
#     URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
# FetchContent_MakeAvailable(json)

# Just encase we need a tests directory for these lessons
if(BUILD_TESTS)
  add_subdirectory(tests)
endif()

# Add the executable
add_executable(lib_catalog_card src/library_catalog_card.cpp)
add_executable(prime_number src/prime_number_challenge.cpp)
add_executable(nonrecurisve_factorial src/nonrecurisve_factorial_challange.cpp)
add_executable(nonrecurisve_factorial_template src/nonrecursive_factorial_template_challenge.cpp)
add_executable(nonmember_operators src/nonmember_operators_challenge.cpp)

# link any needed libs

# install them to a spcific location

# install any share scripts, etc.
