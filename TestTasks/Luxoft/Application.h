#pragma once
////////////////////////////////////////////////////////////////////////////////
// File:   Application.h
// Author: Denis Lyubomishchenko
// Date:   29.12.2015
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <QtWidgets\QApplication>

#include "Dialog.hxx"

class Application : public QApplication
{
public:
	Application(int argc, char *argv[]);
	virtual ~Application();
	int exec();

private:
	MyDialog *dialog;
};
