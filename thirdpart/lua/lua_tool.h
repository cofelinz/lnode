#pragma once

//
// 如果c++编写的lua扩展抛出异常，通过exception_safe_wrapper<xxx>封装一下就可以把异常传递到lua中显示为错误
//
// 用法：
//
// int foo(lua_State * L) { throw ...; }
//
// &foo <--> &exception_safe_wrapper<foo>::f
//

#include "lua.hpp"
#include "stdexcept"
#include "stdio.h"

namespace
{

	template<lua_CFunction func = 0>
	struct exception_safe_tool
	{
	private:
		exception_safe_tool();
	public:
		static int f(lua_State * L)
		{
			try
			{
				return func(L);
			}
			catch (std::exception & err)
			{
				luaL_error(L, "%s", err.what());
			}
			catch (...)
			{
				luaL_error(L, "<unknown error>");
			}

			return 0;
		}
	};


	// 使用fflua绑定 注册某个class时，用这个工具生成它的名字
	// 生成的名字保证不会冲突
	// usage: class_raw_name_tool<Class>::get()
	template<typename T>
	struct class_raw_name_tool
	{
		static char buf[128];

		static const char * get()
		{
			static int placeholder = 0;
			sprintf(buf, "clz_%p", &placeholder);
			return buf;
		}
	};
	template<typename T> char class_raw_name_tool<T>::buf[128] = {0};
}


