set CURDIR=%~dp0
cd %CURDIR%

echo extract depends component......
rd /S /Q ..\..\bin
rd /S /Q ..\..\lib
cd ..\..\

cd %CURDIR%
