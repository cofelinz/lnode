#include<iostream>
#include <string>
using namespace std;

extern "C" {  
#include <lua.h>  
#include <lualib.h>  
#include <lauxlib.h>  
}

int main(int argc,char*argv[])  
{  
	/* initialize Lua */  
	lua_State *L = luaL_newstate();  
	/* load Lua libraries */  
	luaL_openlibs(L);  

	std:;string main_file("main.lua");
	if (argc >= 2){
		main_file = argv[1];
	}

	/* run the script */
	luaL_dofile(L, main_file.c_str());  

	/* cleanup Lua */  
	lua_close(L);  

	return 0;  
}  