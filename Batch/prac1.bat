::When a batch file is being executed, if echo is turned on, 
::it would print the command currently it’s running on to the command prompt. 
::By default echo is turned on for any batch file.
@echo off
ECHO Start of Loop

::/L表示以增量形式从开始到结束的一个数字序列
FOR /L %%i IN (1,1,5) DO (
  ECHO %%i
)
::/F表示可操作文件、字符串以及命令
for /F "tokens=2" %%i in ('date /t') do set mydate=%%i
set mytime=%time%
echo Current time is %mydate%:%mytime%

pause