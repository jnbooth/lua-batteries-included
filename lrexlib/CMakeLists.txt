cmake_minimum_required(VERSION 3.24)

project(lrexlib LANGUAGES C VERSION 0.1.0)

set(PCRE2_USE_STATIC_LIBS ON)

add_library(lrexlib
  lrexlib/src/algo.h
  lrexlib/src/common.c
  lrexlib/src/common.h
  lrexlib/src/pcre2/lpcre2.c
  lrexlib/src/pcre2/lpcre2_f.c
)

add_subdirectory(pcre2)

target_include_directories(lrexlib PRIVATE pcre2/src)
target_compile_definitions(lrexlib PRIVATE
  PCRE2_CODE_UNIT_WIDTH=8
  VERSION="10.44"
)
target_link_libraries(lrexlib PRIVATE pcre2-posix)

if (MSVC)
  target_compile_options(
    lrexlib
    PUBLIC
    /wd4005
    /wd4244
    /wd4267
    /wd4311
    /wd4996
  )
endif ()
