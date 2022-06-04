cmake_minimum_required(VERSION 3.0)
project(acl)

include(CMakeDependentOption)

set(CMAKE_CXX_STANDARD 11)

set(ACL_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "acl library root directory" FORCE)

cmake_dependent_option(BUILD_ACL_TESTING
  "Build both acl library and testing or build Library only"
  ON "CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR" OFF)

if (UNIX)
add_definitions(-Wall -Werror -ggdb3 -std=c99 -Wextra -pedantic)
add_definitions("-D_DEFAULT_SOURCE -D_GNU_SOURCE")
endif()

if (MSVC)
add_compile_options(/wd4996)
endif()

set(ACL_SRC_FILES
    acl.h
    acl.c
)

# include_directories(inc)

add_library(acl SHARED ${ACL_SRC_FILES})
