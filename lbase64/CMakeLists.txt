cmake_minimum_required(VERSION 3.24)

project(lbase64 LANGUAGES C VERSION 0.1.0)

add_library(lbase64
  lbase64.c
)

add_subdirectory(base64)
target_link_libraries(lbase64 PRIVATE base64)
