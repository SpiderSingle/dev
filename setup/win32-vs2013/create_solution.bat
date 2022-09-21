set CURDIR=%~dp0
cd %CURDIR%

mkdir ..\..\cmake-temp
cd ..\..\cmake-temp
"%CURDIR%\..\cmake\bin\cmake" -G "Visual Studio 12" ../source

cd %CURDIR%



