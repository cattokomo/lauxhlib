/**
 *  Copyright (C) 2022 Masatoshi Fukunaga
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 *  deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *  IN THE SOFTWARE.
 */
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// lua
#define LAUXHLIB_USED_IN_LUA
#include "lauxhlib.h"

#define RET_BOOLEAN(fn)                                                        \
 do {                                                                          \
  lua_pushboolean(L, fn(L, 1));                                                \
  return 1;                                                                    \
 } while (0)

static int callable_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_iscallable);
}

static int file_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isfile);
}

static int uint64_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isuint64);
}

static int uint32_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isuint32);
}

static int uint16_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isuint16);
}

static int uint8_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isuint8);
}

static int int64_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isint64);
}

static int int32_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isint32);
}

static int int16_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isint16);
}

static int int8_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isint8);
}

static int pint_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_ispint);
}

static int uint_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isuint);
}

static int int_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isint);
}

static int unsigned_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isunsigned);
}

static int finite_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isfinite);
}

static int thread_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isthread);
}

static int userdata_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isuserdata);
}

static int cfunc_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_iscfunc);
}

static int func_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isfunc);
}

static int table_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_istable);
}

static int str_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isstr);
}

static int num_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isnum);
}

static int pointer_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_ispointer);
}

static int bool_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isbool);
}

static int none_lua(lua_State *L)
{
    RET_BOOLEAN(lauxh_isnil);
}

#undef RET_BOOLEAN

LUALIB_API int luaopen_lauxhlib_is(lua_State *L)
{
    struct luaL_Reg funcs[] = {
        {"none",     none_lua    },
        {"bool",     bool_lua    },
        {"pointer",  pointer_lua },
        {"num",      num_lua     },
        {"str",      str_lua     },
        {"table",    table_lua   },
        {"func",     func_lua    },
        {"cfunc",    cfunc_lua   },
        {"userdata", userdata_lua},
        {"thread",   thread_lua  },
        {"unsigned", unsigned_lua},
        {"finite",   finite_lua  },
        {"int",      int_lua     },
        {"uint",     uint_lua    },
        {"pint",     pint_lua    },
        {"int8",     int8_lua    },
        {"int16",    int16_lua   },
        {"int32",    int32_lua   },
        {"int64",    int64_lua   },
        {"uint8",    uint8_lua   },
        {"uint16",   uint16_lua  },
        {"uint32",   uint32_lua  },
        {"uint64",   uint64_lua  },
        {"file",     file_lua    },
        {"callable", callable_lua},
        {NULL,       NULL        }
    };

    lua_newtable(L);
    for (struct luaL_Reg *ptr = funcs; ptr->name; ptr++) {
        lauxh_pushfn2tbl(L, ptr->name, ptr->func);
    }

    return 1;
}
