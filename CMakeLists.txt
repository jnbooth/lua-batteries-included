cmake_minimum_required(VERSION 3.24)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(lualibs LANGUAGES C VERSION 0.1.0)

add_subdirectory(base64)
add_subdirectory(lua)
add_subdirectory(pcre2)

add_library(lrexlib_static STATIC
  lrexlib/src/algo.h
  lrexlib/src/common.c
  lrexlib/src/common.h
  lrexlib/src/pcre2/lpcre2.c
  lrexlib/src/pcre2/lpcre2_f.c
)
target_include_directories(lrexlib_static PRIVATE pcre2/src)
target_compile_definitions(lrexlib_static PRIVATE
  PCRE2_CODE_UNIT_WIDTH=8
  VERSION="10.44"
)
target_link_libraries(lrexlib_static PUBLIC lua_static pcre2-posix)

add_library(lualibs
  lutil/lutil.c
  # lbc
  lbc/lbc.c
  lbc/src/config.h
  lbc/src/number.h lbc/src/number.c
  # lpeg
  lpeg/lpcap.h lpeg/lpcap.c
  lpeg/lpcode.h lpeg/lpcode.c
  lpeg/lpcset.h lpeg/lpcset.c
  lpeg/lpprint.h lpeg/lpprint.c
  lpeg/lptree.h lpeg/lptree.c
  lpeg/lptypes.h
  lpeg/lpvm.h lpeg/lpvm.c
  # lsqlite3
  lsqlite3/lsqlite3.c
  lsqlite3/sqlite3.h lsqlite3/sqlite3.c
  # LuaBitOp
  LuaBitOp/bit.c
)

target_include_directories(lualibs PRIVATE lbc/src)

target_link_libraries(lualibs PUBLIC lua_static lrexlib_static)
target_link_libraries(lualibs PRIVATE base64)
