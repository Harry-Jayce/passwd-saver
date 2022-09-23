# Passwd Saver

This is a tool to help users save password and other info in the local.

This repo only use C++17 std library, so that the source code is cross-platform.
But the bad thing is that the Lua script is written for Linux, if you wanna use Lua script to build, 
the Windows is not supported. So in that case, you just need to write your own build-script to control.
And you can still utilize CMake code, because it is cross-platform.

I use CMake as build-tool, and Lua script will call CMake cmds to build.

Users usually don't need to type CMake cmds, because I already write down common , just use like:
** Generate CMake Files in build/ **
'''lua mklua.lua gen'''
** call cmake --build to build project **
'''lua mklua.lua build'''
** ls build/ **
'''lua mklua.lua see-build'''

** Clean CMake Files in build/**
'''lua mklua.lua clean'''
** clean exe **
'''lua mklua.lua clean-exe'''

You should stay at the project path to call Lua script.



