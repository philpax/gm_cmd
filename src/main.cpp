#include <string>
#include <iostream>
#include <stdio.h>

#include "GarrysMod/Lua/Interface.h"

using namespace std;
using namespace GarrysMod::Lua;

#ifdef __linux__
#define POPEN popen
#define PCLOSE pclose
#elif _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#endif

std::string exec(const char* cmd) {
	FILE* pipe = POPEN(cmd, "r");
	if (!pipe) return "ERROR";
	char buffer[256];
	std::string result = "";
	while(!feof(pipe)) {
		if(fgets(buffer, 256, pipe) != NULL)
			result += buffer;
	}
	PCLOSE(pipe);
	return result;	
}

int exec(lua_State *state)
{
	LUA->CheckString(1);
	const char* cmd = LUA->GetString( 1 );
	std::string result = exec(cmd);
	
	LUA->PushString( result.c_str() );

	return 1;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(SPECIAL_GLOB);
	LUA->CreateTable();

	LUA->PushCFunction(exec);
	LUA->SetField(-2, "exec");

	LUA->SetField(-2, "server");
	LUA->Pop(1);

	//ConMsg("gmsv_cmd_linux started!");
	return 0;
}

GMOD_MODULE_CLOSE()
{
	//ConMsg("gmsv_cmd_linux stopped!");
	return 0;
}
