#include "GBWin.h"

#include <Windows.h>
#include <iostream>

int main(int argc, char *argv[])
{

	GBWin Wind;

	std::cout << "Dev build: " << Wind._WindowName << " STARTED" << std::endl;
	Wind.TestMSG("Linker Test");

	std::cout << "\n\n\n";

	Wind.init();

	std::cout << "\n================================================"
			  << "\nEnter any key (not space or enter) to quit: ";
	char a;
	std::cin >> a;

	return 0;
}