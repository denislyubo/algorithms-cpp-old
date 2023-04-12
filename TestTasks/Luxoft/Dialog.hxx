#pragma once

#include <QtWidgets/QDialog>

#include "ui\ui_dialog.h"

class MyDialog : public QDialog
{
Q_OBJECT
public:
	MyDialog();
	~MyDialog();

private:
	Ui::Dialog m_ui;
};