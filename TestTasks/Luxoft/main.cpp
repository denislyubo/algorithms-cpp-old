#include <QtCore/QString>
#include <QtCore/qbytearray.h>
#include <iostream>

#include "Application.h"
#include "Dialog.hxx"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	Application app(argc, argv);

	return app.exec();
}

//int main(int argc, char* argv[])
//{
//	MyDialog();
//
//	/*QString str("Abra");
//
//	cout << str.toStdString() << endl;*/
//
//	int a;
//
//	cin >> a;
//	
//	return 0;
//}