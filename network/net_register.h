// Mydll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>

//��ע���C����
//��Ҫ˵�����ǣ��ú���������C����ʽ�����������extern "C"�Ǳ���ġ�
//����һ����ȡƽ�����ĺ���
extern"C"int average(lua_State* L)
{
	double sum=0;
	int num = lua_gettop(L);//��ȡ�����ĸ���for (int i = 1; i <= num;i++)
	sum+= lua_tonumber(L, i);
	//���λ�ȡ���в���ֵ�����
	lua_pushnumber(L, sum/num);//��ƽ����ѹ��ջ����lua��ȡreturn1;//���ط���ֵ������֪ͨluaӦ����ջ��ȡ����ֵ��Ϊ���ؽ��
}

extern"C"int Communicate(lua_State* L)
{
	constchar *name = lua_tostring(L, 1);//��ȡ�ַ���
	printf("Hello %s\n", name);
	printf("I`m in C,I send a message to you");
	lua_pushstring(L, "This message from C");
	return1;
}

//luaL_Reg�ṹ��ĵ�һ���ֶ�Ϊ�ַ�������ע��ʱ����֪ͨLua�ú��������֡�
//��һ���ֶ�ΪC����ָ�롣
//�ṹ�������е����һ��Ԫ�ص������ֶξ�ΪNULL��������ʾLuaע�ắ���Ѿ����������ĩβ��
static luaL_Reg cMethods[] = {
	{ "average", average },
	{ "Communicate", Communicate },
	{ NULL, NULL }
};


//��C���Ψһ��ں������亯��ǩ����ͬ�������ע�ắ���������¼���˵����
//1. ���ǿ��Խ��ú����򵥵����Ϊģ��Ĺ���������
//2. �亯��������Ϊluaopen_xxx������xxx��ʾlibrary���ơ�Lua����require "xxx"��Ҫ��֮��Ӧ��
//3. ��luaL_register�ĵ����У����һ���ַ�������Ϊģ����"xxx"���ڶ�������Ϊ��ע�ắ�������顣
//4. ��Ҫǿ�����ǣ�������Ҫ�õ�"xxx"�Ĵ��룬����C����Lua�������뱣��һ�£�����Lua��Լ����
//   �����޷����á�extern"C" __declspec(dllexport)
int luaopen_Network(lua_State* L)
{
	const char* libName = "linz.network";
	luaL_register(L, libName, cMethods);
	return;
}