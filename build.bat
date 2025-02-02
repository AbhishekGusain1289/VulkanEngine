@echo off

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"


SET includes=/Isrc /I%VULKAN_SDK%\Include /I"./ExternalLibraries/glfw/include" /I"./ExternalLibraries/"
SET links=/link /LIBPATH:%VULKAN_SDK%\Lib /LIBPATH:"./ExternalLibraries/glfw/lib-vc2019" vulkan-1.lib glfw3.lib user32.lib gdi32.lib shell32.lib
SET defines=/D DEBUG
SET crt=/MD

echo "Building Main..."

cl /EHsc /Z7 /Fe"main" %includes% %defines% %crt% src/*.cpp %links%

echo "Cleaning up intermediate files..."
del /Q *.ilk
del /Q *.obj
del /Q *.pdb

echo "Build and cleanup complete."