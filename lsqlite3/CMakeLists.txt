cmake_minimum_required(VERSION 3.24)

project(lsqlite3 LANGUAGES C VERSION 0.1.0)

add_library(lsqlite3
  lsqlite3.c
  include/sqlite3.h sqlite3.c
)

include_directories(include)

if (MSVC)
  target_compile_options(
    lua_static
    PUBLIC
    /wd4244
    /wd4996
  )
endif ()
