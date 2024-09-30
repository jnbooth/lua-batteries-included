#include <stdlib.h>
#include <string.h>
#include "libbase64.h"
#include "lauxlib.h"

static int L_encode(lua_State *L)
{
  size_t inputLength;
  const char *input = luaL_checklstring(L, 1, &inputLength);
  char *output = malloc(inputLength * 4 / 3);
  size_t outputLength;
  base64_encode(input, inputLength, output, &outputLength, 0);
  lua_pushlstring(L, output, outputLength);
  free(output);
  return 1;
}

static int L_decode(lua_State *L)
{
  size_t inputLength;
  const char *input = luaL_checklstring(L, 1, &inputLength);
  char *output = malloc(inputLength * 3 / 4);
  size_t outputLength;
  base64_decode(input, inputLength, output, &outputLength, 0);
  lua_pushlstring(L, output, outputLength);
  free(output);
  return 1;
}

static const struct luaL_Reg base64lib[] =
    {{"decode", L_decode},
     {"encode", L_encode},

     {NULL, NULL}};

LUALIB_API int luaopen_base64(lua_State *L)
{
  luaL_newlib(L, base64lib);
  lua_pushvalue(L, -1);
  lua_setglobal(L, "base64");
  return 1;
}
