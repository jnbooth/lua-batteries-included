cmake_minimum_required(VERSION 3.24)

project(lsqlite3 LANGUAGES C VERSION 0.1.0)

add_library(lsqlite3
  lsqlite3.c
  sqlite3.h sqlite3.c
)

target_sources(lsqlite3
  PRIVATE
    lsqlite3.c
    sqlite3.c

  PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include
  FILES
    include/sqlite3.h
)

target_include_directories(lsqlite3 PUBLIC FILE_SET INTERFACE_HEADERS)

if (MSVC)
  target_compile_options(
    lua_static
    PUBLIC
    /wd4244
    /wd4996
  )
endif ()
