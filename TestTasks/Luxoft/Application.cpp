////////////////////////////////////////////////////////////////////////////////
// File:   Application.cpp
// Author: Denis Lyubomishchenko
// Date:   29.12.2015
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Application.h"

////////////////////////////////////////////////////////////////////////////////
Application::Application(int argc, char *argv[]) :
	QApplication(argc, argv)
{
	dialog = new MyDialog();
}

////////////////////////////////////////////////////////////////////////////////
Application::~Application()
{
	delete dialog;
}

////////////////////////////////////////////////////////////////////////////////
int Application::exec()
{
	dialog->show();

	return QApplication::exec();
}