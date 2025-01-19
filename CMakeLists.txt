cmake_minimum_required(VERSION 3.24)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(lualibs LANGUAGES C VERSION 0.1.0)

add_subdirectory(lua)
include_directories(${LUA_INCLUDE_DIR})

add_subdirectory(lbase64)
add_subdirectory(lbc)
add_subdirectory(lpeg)
add_subdirectory(lrexlib)
add_subdirectory(lsqlite3)
add_subdirectory(LuaBitOp)
add_subdirectory(lua-cjson)

target_link_libraries(lbase64 PRIVATE lua_static)
target_link_libraries(lbc PRIVATE lua_static)
target_link_libraries(lpeg PRIVATE lua_static)
target_link_libraries(lrexlib PRIVATE lua_static)
target_link_libraries(lsqlite3 PRIVATE lua_static)
target_link_libraries(luabitop PRIVATE lua_static)
target_link_libraries(lua-cjson PRIVATE lua_static)

add_library(lualibs INTERFACE)

target_link_libraries(lualibs
  INTERFACE
  lua_static
  lbase64
  lbc
  lpeg
  lrexlib
  lsqlite3
  luabitop
  lua-cjson
)

install(DIRECTORY lsqlite3/include TYPE INCLUDE)
