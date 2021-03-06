// Mydll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>

//待注册的C函数
//需要说明的是，该函数必须以C的形式被导出，因此extern "C"是必须的。
//定义一个求取平均数的函数
extern"C"int average(lua_State* L)
{
	double sum=0;
	int num = lua_gettop(L);//获取参数的个数for (int i = 1; i <= num;i++)
	sum+= lua_tonumber(L, i);
	//依次获取所有参数值，相加
	lua_pushnumber(L, sum/num);//将平均数压如栈，供lua获取return1;//返回返回值个数，通知lua应该在栈里取几个值作为返回结果
}

extern"C"int Communicate(lua_State* L)
{
	constchar *name = lua_tostring(L, 1);//获取字符串
	printf("Hello %s\n", name);
	printf("I`m in C,I send a message to you");
	lua_pushstring(L, "This message from C");
	return1;
}

//luaL_Reg结构体的第一个字段为字符串，在注册时用于通知Lua该函数的名字。
//第一个字段为C函数指针。
//结构体数组中的最后一个元素的两个字段均为NULL，用于提示Lua注册函数已经到达数组的末尾。
static luaL_Reg cMethods[] = {
	{ "average", average },
	{ "Communicate", Communicate },
	{ NULL, NULL }
};


//该C库的唯一入口函数。其函数签名等同于上面的注册函数。见如下几点说明：
//1. 我们可以将该函数简单的理解为模块的工厂函数。
//2. 其函数名必须为luaopen_xxx，其中xxx表示library名称。Lua代码require "xxx"需要与之对应。
//3. 在luaL_register的调用中，其第一个字符串参数为模块名"xxx"，第二个参数为待注册函数的数组。
//4. 需要强调的是，所有需要用到"xxx"的代码，不论C还是Lua，都必须保持一致，这是Lua的约定，
//   否则将无法调用。extern"C" __declspec(dllexport)
int luaopen_Network(lua_State* L)
{
	const char* libName = "linz.network";
	luaL_register(L, libName, cMethods);
	return;
}