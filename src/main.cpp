#include <string>
#include <iostream>
#include <stdio.h>

#include "GarrysMod/Lua/Interface.h"

using namespace std;
using namespace GarrysMod::Lua;

std::string exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}

int exec(lua_State *state)
{
	LUA->CheckString(1);
	const char* cmd = LUA->GetString( 1 );
	char* result = exec(cmd).c_str();
	
	LUA->PushString( result );

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
