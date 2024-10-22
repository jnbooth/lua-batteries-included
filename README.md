# lua-batteries-included

## Installation

In CMakeLists.txt:

```cmake
FetchContent_Declare(
  lualibs
  GIT_REPOSITORY https://github.com/jnbooth/lua-batteries-included.git
  GIT_TAG        <TAG>
)

FetchContent_MakeAvailable(lua_libs)
```

## Usage

```cpp
extern "C"
{
#include "lauxlib.h"
#include "lualib.h"
  LUALIB_API int luaopen_base64(lua_State *L);
  LUALIB_API int luaopen_bc(lua_State *L);
  LUALIB_API int luaopen_bit(lua_State *L);
  LUALIB_API int luaopen_cjson(lua_State *L);
  LUALIB_API int luaopen_lpeg(lua_State *L);
  LUALIB_API int luaopen_rex_pcre2(lua_State *L);
  LUALIB_API int luaopen_lsqlite3(lua_State *L);
}
```

## Libraries

- lbase64: Provides `decode` and `encode` for converting between plaintext and base 64.
- [lbc](https://github.com/Tekenlight/lbc-101): Arbitrary precision math operations.
- [Lua BitOp](http://bitop.luajit.org/): Bitwise operations on numbers for cross-compatibility with scripts written before native bitwise operations were added to Lua.
- [Lua CJSON](https://github.com/mpx/lua-cjson/): Encoding and decoding objects (tables) as JSON strings.
- [LPeg](https://www.inf.puc-rio.br/~roberto/lpeg/): Pattern-matching based on Parsing Expression Grammars.
- [Lrexlib](https://github.com/rrthomas/lrexlib): PCRE2 regular expressions.
- [LuaSQLite3](http://lua.sqlite.org/index.cgi/doc/tip/doc/lsqlite3.wiki) - SQLite3 database management.
