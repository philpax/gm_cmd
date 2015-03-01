dofile("../../common.lua")

RequireDefaultlibs()

SOLUTION 	"cmd"

targetdir	"bin"
INCLUDES 	"gmod_sdk"
defines		{"NDEBUG"}

WINDOWS()
LINUX()

PROJECT()
SOURCE_SDK_LINKS()
configuration 		"linux"
