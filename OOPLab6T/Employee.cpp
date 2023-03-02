#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <regex>

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

		virtual string salary() = 0;

		bool isValidName(const string& name) {
			for (char c : name) {
				if (!isalpha(c) || isspace(c)) {
					return false;
				}
			}
			return true;
		}

		void input() {
			do {
				cout << "  Enter your first name: ";
				cin >> ws; // discard leading whitespace characters
				getline(cin, firstName);
				cout << "  Enter your last name: ";
				getline(cin, lastName);

				try {
					if (!isValidName(firstName) || !isValidName(lastName)) {
						throw "Invalid name entered! Enter a name that only contains letters";
					}
				}
				catch (const char* error) {
					cerr << error << endl;
				}
			} while (!isValidName(firstName) || !isValidName(lastName));

			do {
				cout << "  Enter your age: ";
				cin >> age;
				try {
					if (age < 5 || age > 105) {
						throw "Invalid age entered! Please enter a value between 5 and 105.";
					}
				}
				catch (const char* error) {
					cerr << error << endl;
				}
			} while (age < 5 || age > 105);
			
			cout << "  Enter your job title: ";
			cin >> ws; // discard leading whitespace characters
			getline(cin, title);
		}

		string toString() {
			string a;
			a = to_string(age);
			string result = "    First name : " + 
				firstName + "\n    Last name: " + lastName + "\n    Age: " + a + "\n    Job title: " + title;
			return result;
		}
	};

	class hourlyEmployee : public Employee {
	protected: 
	public:
		hourlyEmployee() : Employee() {}
		hourlyEmployee(string fn, string ln, int a, string t) : Employee(fn, ln, a, t) {}
		
		/*bool isValidWage(const string& wage) {
			if (!regex_match(wage, regex("[0-9,.]+"))) {
				return false;
			}

			string wageWithoutCommas = wage;
			wageWithoutCommas.erase(remove(wageWithoutCommas.begin(), wageWithoutCommas.end(), ','), wageWithoutCommas.end());
			double wage_double = stod(wageWithoutCommas);
			if (wage_double < 0 || wage_double > 100000) {
				return false;
			}
			return true;
		}*/

		virtual string salary() override {
			string res = Employee::toString() + "\n    Wage: 14$ per hour.";
			return res;
		}

		/*void Input() {
			Employee::input();
			string wage;
			do {
				cout << "Enter your wage (0 < wage < 100000): ";
				cin >> wage;

				if (!isValidWage(wage)) {
					cout << "Invalid input. Wage must be between (0 < wage < 100000)" << endl;
				}
			} while (!isValidWage(wage));
			salary(wage);
		}*/
	};

	class stateEmployee : public Employee {
	public:
		stateEmployee() : Employee() {}
		stateEmployee(string fn, string ln, int a, string t) : Employee(fn, ln, a, t) {}
		virtual string salary() override {
			string res = Employee::toString() + "\n    Wage: 20$ per hour\n    This employee performs a one-time order or temporary work!";
			return res;
		}
	};

	class interestRateEmployee : public Employee {
	public:
		interestRateEmployee() : Employee() {}
		interestRateEmployee(string fn, string ln, int a, string t) : Employee(fn, ln, a, t) {}
		virtual string salary() override {
			string res = Employee::toString() + "\n    Interest rate: 6% from orders/etc.\n";
			return res;
		}
	};

	int Task2() {
		cout << "-------- Task 2 --------\n" << endl;
		int n = 0;
		int type = 1;
		Employee** employeers; //("Oleh", "Vasylov", 20, "Front-end developer");
		do {
			cout << "Quantity of employeers (n < 10): ";
			cin >> n;
		} while (n <= 0 || n > 10);
		employeers = new Employee * [n];
		for (int i = 0; i < n; i++) {
			do {
				cout << "\n Choose a type of employee:  \n";
				cout << "  1 - Hourly employee \n";
				cout << "  2 - State employee \n";
				cout << "  3 - Interest rate employee \n";
				cout << "\n   Your choice: ";
				cin >> type;
			} while (type < 1 || type > 3);

			switch (type) {
			case 1: 
				employeers[i] = new hourlyEmployee();
				cout << "  Enter data about a " << "[" << i + 1 << "]" << " employee \n";
				employeers[i]->input();
				break;
			case 2:
				employeers[i] = new stateEmployee();
				cout << "  Enter data about a " << "[" << i + 1 << "]" << " employee \n";
				employeers[i]->input();
				break;
			case 3:
				employeers[i] = new interestRateEmployee();
				cout << "  Enter data about a " << "[" << i + 1 << "]" << " employee \n";
				employeers[i]->input();
				break;
			}
		}

		cout << "\n\n All data: \n--------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << "\n  Data about a [" << i+1 << "] employee: \n";
			cout << employeers[i]->salary() << endl;
		}
		cout << "--------------------------------\n\n";
		cin.get();

		return 0;
	}
}