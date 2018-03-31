@echo off

echo 该脚本用于自动化复制main.cpp文件到本目录
echo 同时创建 题目.txt 文件

set CUR_PATH=%~dp0
set FILE_NAME=%CUR_PATH%..\TestPro\main.cpp
set TARGET_DIR_NAME=%CUR_PATH%
set TARGET_REF_NAME=%CUR_PATH%题目.txt

copy /B %FILE_NAME% %TARGET_DIR_NAME%
echo 题目:>> %TARGET_REF_NAME%
echo 完成

pause

