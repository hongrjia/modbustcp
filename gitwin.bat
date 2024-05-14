@echo off


set OUTDIR=%~1%
IF "%OUTDIR%" == "" (
    if exist sdk/src (
        set OUTDIR=sdk/include
    ) else (
        set OUTDIR=include
    )
) else (
    echo FILE_H=%~1%/gitver.h
)

::echo OUTDIR=%OUTDIR%
set FILE_H=%OUTDIR%/gitver.h

git rev-parse HEAD  >tmp.ini
set /p GIT_SHA1=<tmp.ini

git rev-parse --abbrev-ref HEAD  >tmp.ini
set /p GIT_BRANCH=<tmp.ini


git rev-parse origin/%GIT_BRANCH% >tmp.ini
set /p GIT_REMOTE_SHA1=<tmp.ini

git ls-remote --get-url origin  >tmp.ini
set /p GIT_REMOTE=<tmp.ini


git log -1 --format=%%ad --date=local >tmp.ini
set /p GIT_DATE=<tmp.ini

set compileTime=%date:~0,4%-%date:~5,2%-%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2%

git rev-list --count HEAD >tmp.ini
set /p COMMIT_NUM=<tmp.ini

git status|findstr "modified" |find /i /c "modified" >tmp.ini
set /p MODIFY_NUM=<tmp.ini

echo COMMIT_NUM=%COMMIT_NUM%
echo MODIFY_NUM=%MODIFY_NUM%
echo GIT_SHA1=%GIT_SHA1%
echo GIT_REMOTE_SHA1=%GIT_REMOTE_SHA1%
echo "USERNAME"=%USERNAME%

set GIT_VER=%USERNAME%#
IF "%GIT_SHA1%"=="%GIT_REMOTE_SHA1%" (
    set GIT_VER=R
)

set GIT_VER=%GIT_VER%%COMMIT_NUM%
if "%MODIFY_NUM%" NEQ  "0" (
    set GIT_VER=%GIT_VER%M%MODIFY_NUM%
)

echo FILE_H=%FILE_H%
echo GIT_VER=%GIT_VER%

echo #ifndef __GIT_VER_H > %FILE_H%
echo #define __GIT_VER_H >>%FILE_H%

echo #define GIT_VER    "%GIT_VER%" >>%FILE_H%

echo #define GIT_SHA1   "%GIT_SHA1%" >>%FILE_H%
echo #define GIT_DATE   "%GIT_DATE%" >>%FILE_H%
echo #define GIT_BRANCH "%GIT_BRANCH%" >>%FILE_H%
echo #define GIT_REMOTE "%GIT_REMOTE%" >>%FILE_H%
echo #define GIT_REMOTE_SHA1   "%GIT_REMOTE_SHA1%" >>%FILE_H%
echo #define COMPILE_USER      "%USERNAME%" >>%FILE_H%

echo #endif >>%FILE_H%

::REM if exist tmp.ini del tmp.ini