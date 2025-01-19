cmake_minimum_required(VERSION 3.24)

project(lbc LANGUAGES C VERSION 0.1.0)

add_library(lbc
  lbc/lbc.c
  lbc/src/config.h
  lbc/src/number.h lbc/src/number.c
)

target_include_directories(lbc PRIVATE lbc/src)
