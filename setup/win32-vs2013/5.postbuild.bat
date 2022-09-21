set CURDIR=%~dp0
cd %CURDIR%

echo on

rmdir /s/q ..\..\repo
mkdir ..\..\config

rem pkcommforward
xcopy /S /Y ..\..\bin\*.dll ..\..\repo\video-ar\bin\
xcopy /S /Y ..\..\bin\*.exe ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\vcruntime1400.dll ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\libmysql.dll ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\pkcommunicate.dll ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\pkcomm.dll ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\pklog.dll ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\pkinifile.dll ..\..\repo\pkcommforward\bin\
rem xcopy /S /Y ..\..\bin\pkserverbase.dll ..\..\repo\pkcommforward\bin\
rem copy /Y ..\..\source\server\pkcommforwardserver\config\db.conf ..\..\repo\pkcommforward\config\db-pkcommforward.conf 

set CURRENT_DATE=%date:~0,4%-%date:~5,2%-%date:~8,2%
set RAR_FILENAME=video-ar-%CURRENT_DATE%.rar
..\rar a -ep1 ../../repo/%RAR_FILENAME%  ../../repo/video-ar/bin  ..\..\repo\video-ar\config 
copy ..\..\repo\%RAR_FILENAME% ..\..\repo\video-ar.rar /y

cd %CURDIR%