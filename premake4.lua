package.path = package.path .. ";../BuildScripts/?.lua"
require "findExternalLibrary"
require "getOSType"
require "setProjectLocation"

project "Core"
	setProjectLocation()
	setupExternalLibraries()
	language "C++"
	kind "StaticLib"
	includedirs{"./include"}
	files  {"./include/*.h", "./cpp/*.cpp"}
	
	configuration {"Debug*"}
		defines {"_DEBUG", "DEBUG"}
		flags{"Symbols"}
		targetdir ("./bin/"..getOSType().."/Debug")
	
	configuration {"Release*"}
		defines{"NDEBUG"}
		flags{"Optimize"}
		targetdir ("./bin/"..getOSType().."/Release")
		
------------------------- USAGE PROJECT FOR INCLUDING INTO OTHER PROJECTS--------
usage "Core"
		kind "StaticLib"
		includedirs{"./include"}
		
		configuration{"Debug*"}
			links{"./bin/"..getOSType().."/Debug"}
			
		configuration{"Release *"}
			links{"./bin/"..getOSType().."/Release"}

	