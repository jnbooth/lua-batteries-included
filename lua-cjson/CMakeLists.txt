cmake_minimum_required(VERSION 3.24)

project(lua-cjson LANGUAGES C VERSION 0.1.0)

add_library(lua-cjson
  lua-cjson/fpconv.h lua-cjson/fpconv.c
  lua-cjson/lua_cjson.c
  lua-cjson/strbuf.h lua-cjson/strbuf.c
)

# Handle platforms missing isinf() macro (Eg, some Solaris systems).
include(CheckSymbolExists)
CHECK_SYMBOL_EXISTS(isinf math.h HAVE_ISINF)
if(NOT HAVE_ISINF)
  add_definitions(-DUSE_INTERNAL_ISINF)
endif()

if(WIN32)
  # Windows sprintf()/strtod() handle NaN/inf differently. Not supported.
  add_definitions(-DDISABLE_INVALID_NUMBERS)
endif()

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-Dinline=__inline)
  #add_definitions(-Dsnprintf=_snprintf)
  add_definitions(-Dstrncasecmp=_strnicmp)
endif()
