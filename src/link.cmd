@echo off

setlocal

set PROJECTDIR=%~dp0
set PLUGINDIR=%appdata%\Elgato\Streamdeck\Plugins
set PLUGINNAME=de.hogs.ets2.sdPlugin

set SRCDIR=%PROJECTDIR%\plugin.dir
set TARGETDIR=%PLUGINDIR%\%PLUGINNAME%

if not exist %TARGETDIR% goto create_symlink
echo plugin directory exists

for %%i in ("%TARGETDIR%") do set attribs=%%~ai
if "%attribs:~8,1%" neq "l" (
	echo create backup
	rename %TARGETDIR% %PLUGINNAME%.bak
) else (
	echo remove symlink
	rmdir %TARGETDIR%
)

:create_symlink
mklink /J "%TARGETDIR%" "%SRCDIR%"
echo symlink created

endlocal