#include "Lab6Example.h"
#include <iostream>

void MenuExample() {
	/*std::cout << "    1   Example 1  \n";
	std::cout << "    2   Example 2  \n";
	std::cout << "    3   Example 3  \n";*/
	
	std::cout << "    Choose a task  \n";
	std::cout << "    1 - Task 1 (inheritance, virtual/non-virtual classes, scheme) \n";
	std::cout << "    2 - Task 2 (Abstract classes)\n";
	std::cout << "    3 - Task 3 (Figure classes)\n";
	std::cout << "    4 - Exit \n";
}
void Example()
{
	std::cout << "OOP. Laboratory work #6 \n";

	char ch = '4';
	do {
		system("cls");
		MenuExample();
		ch = std::cin.get();

		std::cin.get();

		switch (ch) {
		//case '1':  SpaceExample1::mainExample1();   break;
		//case '2':  SpaceExample2::mainExample2();   break;
		//case '3':  SpaceExample3::mainExample3();   break;
		case '1':  Inheritance::Task1(); break;
		case '2':  AbstractClasses::Task2(); break;
		case '3':  Figures::Task3(); break;
		case '4':  return;
		case 'e':  return;
		case 'E':  return;
		}
		std::cout << " Press any key and enter\n";
		ch = std::cin.get();
	} while (ch != '4');

	return ;
}



