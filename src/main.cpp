#include <stdio.h>

#include "GarrysMod/Lua/Interface.h"

#include "Color.h"
#include "tier0/dbg.h"
#include "tier1/interface.h"

using namespace std;
using namespace GarrysMod::Lua;

GMOD_MODULE_OPEN()
{
	ConMsg("Hello world!");
	return 0;
}

GMOD_MODULE_CLOSE()
{
	ConMsg("Module Stopped!");
	return 0;
}