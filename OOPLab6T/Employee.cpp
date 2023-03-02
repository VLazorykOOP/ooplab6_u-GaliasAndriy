#include "Lab6Example.h"
#include <iostream>
#include <string>

using namespace std;

//Створити абстрактний базовий клас працівник із віртуальною функцією
//нарахування зарплати.Створити похідні класи : службовець із погодинною оплатою,
//службовець у штаті та службовець із процентною ставкою.
namespace AbstractClasses {
	class Employee {
	protected:
		string firstName;
		string lastName;
		int age;
		string title; // job
	public:
		Employee() {
			firstName = "no data"; lastName = "no data"; age = NULL; title = "no data";
		}
		Employee(string firstN, string lastN, int ag, string titlee) 
			: firstName(firstN), lastName(lastN), age(ag), title(titlee) {}

		virtual string salary(string salary) = 0;

		bool isValidName(const string& name) {
			for (char c : name) {
				if (isalpha(c) || isspace(c)) {
					return false;
				}
			}
			return true;
		}

		void input() {
			do {
				cout << " Enter your first name: ";
				getline(cin, firstName);
				cout << " Enter your last name: ";
				getline(cin, lastName);

				try {
					if (!isValidName(firstName) || !isValidName(lastName)) {
						throw "Invalid name entered! Enter a name that only contains letters";
					}
					cout << " Your name: " << firstName << " " << lastName << endl;
				}
				catch (const char* error) {
					cerr << error << endl;
				}
			} while (!isValidName(firstName) || !isValidName(lastName));

			do {
				cout << "Enter your age: ";
				cin >> age;
				try {
					if (age < 5 || age > 105) {
						throw "Invalid age entered! Please enter a value between 5 and 105.";
					}
					cout << "Your age is: " << age << endl;
				}
				catch (const char* error) {
					cerr << error << endl;
				}
			} while (age < 5 || age > 105);
			
			cout << " Enter your job title: ";
			cin >> title;
		}

		string toString() {
			string a;
			a = to_string(age);
			string result = "\n ---------------------------------------- \n Data about employee: \n  First name: " + 
				firstName + "\n  Last name: " + lastName + "\n  Age: " + a + "\n  Job title: " + title;
			return result;
		}
	};

	class hourlyEmployee : public Employee {
	protected: 
	public:
		hourlyEmployee(string fn, string ln, int a, string t) : Employee(fn, ln, a, t) {}
		virtual string salary(string salary) override {
			string res = " Wage: " + salary + "$ per hour\n";
			return res;
		}
	};

	class stateEmployee : public Employee {
		stateEmployee(string fn, string ln, int a, string t) : Employee(fn, ln, a, t) {}
		virtual string salary(string salary) override {
			string res = " Wage: " + salary + "$ per hour\n This employee performs a one-time order or temporary work!";
			return res;
		}
	};

	class interestRateEmployee : public Employee {
		interestRateEmployee(string fn, string ln, int a, string t) : Employee(fn, ln, a, t) {}
		virtual string salary(string salary) override {
			string res = " Interest rate: " + salary + "% from orders\n";
			return res;
		}
	};

	int Task2() {
		cout << "-------- Task 2 --------n" << endl;

		return 0;
	}
}