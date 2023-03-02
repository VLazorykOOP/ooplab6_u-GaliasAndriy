#include "Lab6Example.h"
#include <iostream>
#include <string>

using namespace std;

namespace Inheritance {
	class Base {
	protected: 
		int dat;
		double arr[3] = {-1, 1, 5};
		string baseInfo = "Base class";
	public:
		Base() : dat(1) {}
		Base(int d) : dat(d) {}

		string toString() {
			string data;
			data = to_string(dat);
			string res = " Base elem: " + data + "\n";
			return res;
		}
	};

	class Left1 : protected Base {
	protected: 
		int l1;
		string left1_obj = " Left1 class";
	public:
		Left1() : l1(11) {}
		Left1(int l) : l1(l) {}
		Left1(int l, int bp) : Base(bp), l1(l) {}
		string toString() {
			string left;
			left = to_string(l1);
			string res = " -- Left1:Base --\n" + Base::toString() + " Left1 elem: " + left + "\n";
			return res;
		}
	};

	class Center : protected Left1 {
	protected:
		int center;
		string center_obj = " Center class";
	public:
		Center() : center(222) {}
		Center(int c) : center(c) {}
		Center(int c, int bp, int l1) : Left1(bp, l1), center(c) {}

		string toString() {
			string cen;
			cen = to_string(center);
			string res = " -- Center:Left1 --\n" + Left1::toString() + " Center elem: " + cen + "\n";
			return res;
		}
	};

	class Left2 : protected Left1, protected Center {
	protected:
		int l2;
		string left2_obj = " Left2 class";
	public:
		Left2() : l2(12) {}
		Left2(int l) : l2(l) {}
		Left2(int l, int l1, int BEL, int l1C, int BEC, int center) : 
			Left1(BEL, l1), Center(BEC, l1C, center), l2(l) {}

		string toString() {
			string left2;
			left2 = to_string(l2);
			string res = " -- Left2:Left1, Center --\n" + Left1::toString() + Center::toString() + " Left2 elem: " + left2 + "\n";
			return res;
		}
	};

	class Right1 : protected Base {
	protected:
		int r1;
		string left1_obj = " Right1 class";
	public:
		Right1() : r1(31) {}
		Right1(int r) : r1(r) {}
		Right1(int r, int bp) : Base(bp), r1(r) {}

		string toString() {
			string right;
			right = to_string(r1);
			string res = " -- Right1:Base --\n" + Base::toString() + " Right1 elem: " + right + "\n";
			return res;
		}
	};

	class Right2 : protected Right1, protected Center, protected Base {
	protected:
		int r2;
		string left2_obj = " Right2 class";
	public:
		Right2() : r2(32) {}
		Right2(int r) : r2(r) {}
		Right2(int r, int r1, int BER, int center, int BEC, int l1C, int PB) 
			: Right1(BER, r1), Center(BEC, l1C, center), Base(PB), r2(r) {}

		string toString() {
			string right2;
			right2 = to_string(r2);
			string res = " -- Right2:Right1, Center, Base --\n" + Base::toString() + Right1::toString() + Center::toString() +
				" Right2 elem: " + right2 + "\n";
			return res;
		}
	};

	//virtual classes

	class Left1_V : virtual protected Base {
	protected:
		int l1;
		string left1_obj = " Left1 class";
	public:
		Left1_V() : l1(11) {}
		Left1_V(int l) : l1(l) {}
		Left1_V(int l, int bp) : Base(bp), l1(l) {}
		string toString() {
			string left;
			left = to_string(l1);
			string res = " -- Left1:Base --\n" + Base::toString() + " Left1 elem: " + left + "\n";
			return res;
		}
	};

	class Center_V : virtual protected Left1_V {
	protected:
		int center;
		string center_obj = " Center class";
	public:
		Center_V() : center(222) {}
		Center_V(int c) : center(c) {}
		Center_V(int c, int bp, int l1) : Left1_V(bp, l1), center(c) {}

		string toString() {
			string cen;
			cen = to_string(center);
			string res = " -- Center:Left1 --\n" + Left1_V::toString() + " Center elem: " + cen + "\n";
			return res;
		}
	};

	class Left2_V : virtual protected Left1_V, virtual protected Center_V {
	protected:
		int l2;
		string left2_obj = " Left2 class";
	public:
		Left2_V() : l2(12) {}
		Left2_V(int l) : l2(l) {}
		Left2_V(int l, int l1, int BEL, int l1C, int BEC, int center) :
			Left1_V(BEL, l1), Center_V(BEC, l1C, center), l2(l) {}

		string toString() {
			string left2;
			left2 = to_string(l2);
			string res = " -- Left2:Left1, Center --\n" + Left1_V::toString() + Center_V::toString() + " Left2 elem: " + left2 + "\n";
			return res;
		}
	};

	class Right1_V : virtual protected Base {
	protected:
		int r1;
		string left1_obj = " Right1 class";
	public:
		Right1_V() : r1(31) {}
		Right1_V(int r) : r1(r) {}
		Right1_V(int r, int bp) : Base(bp), r1(r) {}

		string toString() {
			string right;
			right = to_string(r1);
			string res = " -- Right1:Base --\n" + Base::toString() + " Right1 elem: " + right + "\n";
			return res;
		}
	};

	class Right2_V : virtual protected Right1_V, virtual protected Center_V, virtual protected Base {
	protected:
		int r2;
		string left2_obj = " Right2 class";
	public:
		Right2_V() : r2(32) {}
		Right2_V(int r) : r2(r) {}
		Right2_V(int r, int r1, int BER, int center, int BEC, int l1C, int PB)
			: Right1_V(BER, r1), Center_V(BEC, l1C, center), Base(PB), r2(r) {}

		string toString() {
			string right2;
			right2 = to_string(r2);
			string res = " -- Right2:Right1, Center, Base --\n" + Base::toString() + Right1_V::toString() 
				+ Center_V::toString() + " Right2 elem: " + right2 + "\n";
			return res;
		}
	};

	
	int Task1() {
		Right2 empty, filled(32, 0, 31, 0, 22, 11, 0);
		Left2 emptyLeft, filledLeft(12, 11, 0, 122, 0, 222);

		cout << " Testing of non-virtual classes" << endl;
		cout << " --------------------------------------\n";
		cout << " Size for Base: " << sizeof(Base) << endl;
		cout << " Size for Left1: " << sizeof(Left1) << endl;
		cout << " Size for Center: " << sizeof(Center) << endl;
		cout << " Size for Left2: " << sizeof(Left2) << endl;
		cout << " Size for Right1: " << sizeof(Right1) << endl;
		cout << " Size for Right2: " << sizeof(Right2) << endl;

		cout << " Size for empty obj Right2: " << sizeof(empty) 
			<< "\n or filled obj: " << sizeof(filled) << endl;
		cout << " Size for empty obj Left2: " << sizeof(emptyLeft)
			<< "\n or filled obj: " << sizeof(filledLeft) << endl;
		cout << " --------------------------------------\n";

		cout << "\n\n";
		cout << filled.toString() << endl;
		cout << emptyLeft.toString() << endl;

		// virtual
		Right2_V emptyV, filledV(322, -1, 311, 0, 222, 111, 1);

		cout << " --------------------------------------\n";
		cout << " Size for Base: " << sizeof(Base) << endl;
		cout << " Size for Left1: " << sizeof(Left1_V) << endl;
		cout << " Size for Center: " << sizeof(Center_V) << endl;
		cout << " Size for Left2: " << sizeof(Left2_V) << endl;
		cout << " Size for Right1: " << sizeof(Right1_V) << endl;
		cout << " Size for Right2: " << sizeof(Right2_V) << endl;
		cout << " Size for empty obj Right2: " << sizeof(emptyV)
			<< "\n or filled obj: " << sizeof(filledV) << endl;
		cout << " --------------------------------------\n";
		cout << filledV.toString() << endl;

		// knowing the size of a class object is important for memory allocation, serialization and performance
		// reasons. method sizeof() can help you ensure that your code is correct and efficient

		return 0;
	}
}