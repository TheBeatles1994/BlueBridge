@echo off

echo �ýű������Զ�������main.cpp�ļ�����Ŀ¼
echo ͬʱ���� ��Ŀ.txt �ļ�

set CUR_PATH=%~dp0
set FILE_NAME=%CUR_PATH%..\TestPro\main.cpp
set TARGET_DIR_NAME=%CUR_PATH%
set TARGET_REF_NAME=%CUR_PATH%��Ŀ.txt

copy /B %FILE_NAME% %TARGET_DIR_NAME%
echo ��Ŀ:>> %TARGET_REF_NAME%
echo ���

pause

