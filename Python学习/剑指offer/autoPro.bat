@echo off

echo �ýű������Զ�������prac.py�ļ�����Ŀ¼
echo ͬʱ���� ��Ŀ.txt �ļ�

set CUR_PATH=%~dp0
set FILE_NAME=%CUR_PATH%..\prac.py
set TARGET_DIR_NAME=%CUR_PATH%
set TARGET_REF_NAME=%CUR_PATH%��Ŀ.txt
mkdir 0�������ļ���

copy /B %FILE_NAME% %TARGET_DIR_NAME%
echo ��Ŀ:>> %TARGET_REF_NAME%
echo ���

pause

