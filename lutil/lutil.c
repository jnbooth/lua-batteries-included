#include <stdlib.h>
#include <string.h>
#include "libbase64.h"
#include "lauxlib.h"

int optint(lua_State *L, int idx, int ifNil)
{
  const int actualType = lua_type(L, idx);
  if (actualType <= 0)
    return ifNil;
  luaL_argexpected(L, actualType == LUA_TNUMBER, idx, "integer");
  int isInt;
  const int result = lua_tointegerx(L, idx, &isInt);
  luaL_argexpected(L, isInt, idx, "integer");
  return result;
}

static int L_base64encode(lua_State *L)
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

static int L_base64decode(lua_State *L)
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

static int L_split(lua_State *L)
{
  size_t inputLength;
  const char *input = luaL_checklstring(L, 1, &inputLength);
  size_t sepLength;
  const char *sep = luaL_checklstring(L, 2, &sepLength);
  const int count = optint(L, 2, 0);
  if (sepLength != 1)
    luaL_error(L, "Separator must be a single character");
  if (count < 0)
    luaL_error(L, "Count must be positive or zero");

  lua_newtable(L);
  const int max = count == 0 ? INT_MAX : count;

  const char *endPtr = input + inputLength;
  const char *sepPtr;
  int i = 1;
  for (; i <= max && input < endPtr && (sepPtr = strchr(input, *sep)) != NULL; ++i)
  {
    lua_pushlstring(L, input, sepPtr - input);
    lua_rawseti(L, -2, i);
    input = sepPtr + 1;
  }
  if (input < endPtr)
  {
    lua_pushlstring(L, input, endPtr - input);
    lua_rawseti(L, -2, i);
  }
  return 1;
}

static const struct luaL_Reg utillib[] =
    {{"base64decode", L_base64decode},
     {"base64encode", L_base64encode},
     {"split", L_split},

     {NULL, NULL}};

LUALIB_API int luaopen_util(lua_State *L)
{
  luaL_newlib(L, utillib);
  lua_pushvalue(L, -1);
  lua_setglobal(L, "utils");
  return 1;
}
