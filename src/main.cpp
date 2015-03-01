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

LUA_FUNCTION( ServerExec )
{
	L->CheckType( 1, GLua::TYPE_STRING );
	char* cmd = L->GetString( 1 );
	char* result = exec(cmd).c_str();
	L->Push( result );

	return 1;
}

GMOD_MODULE_OPEN()
{
	L = Lua();
	L->SetGlobal( "ServerExec", ServerExec );
 
	//ConMsg("gmsv_cmd_linux started!");
	return 0;
}

GMOD_MODULE_CLOSE()
{
	//ConMsg("gmsv_cmd_linux stopped!");
	return 0;
}
