@echo off

SET QTDIR=G:\Libs\Qt5.5.1\5.5\msvc2013_64\

SET PATH=%PATH%;%QTDIR%;%QTDIR%\bin;
set QMAKESPEC=win32-msvc2015

start TestTasks.sln