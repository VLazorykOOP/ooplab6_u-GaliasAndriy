#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Ієрархія типів складається з сутностей : геометрична фігура, коло, квадрат
//та вписане коло в квадраті.
namespace Figures {
	class Figure {
	protected:
		double R = 1; // radius of the circle
		string color = "transparent";
	public:
		Figure() {
			R = 0; color = "default";
		}
		Figure(double RR, string col) {
			R = RR; color = col;
		}
		Figure(string col) {
			color = col; R = NULL;
		}

		double getR() { 
			return R; 
		}
		void setR(double Radius) {
			R = Radius;
		}
		string getColor() { 
			return color; 
		}
		void setColor(string c) {
			color = c;
		}
		void input() {
			cout << "\n  Enter next data about a figure:\n";
			do {
				cout << "  Enter R-radius: "; 
				cin >> R;
				try {
					if (R < 0 && R > 1000) {
						throw "Invalid radius entered. Please enter R (0 < R < 1000)";
					}
				}
				catch (const char* error) {
					cerr << error << endl;
				}
			} while (R < 0 && R > 1000);
			cout << "  Enter color: "; 
			cin >> color;
			/*do {
				cout << "  Enter S-square(area): ";
				cin >> S;
				try {
					if (R < 0 && R > 100000) {
						throw "Invalid radius entered. Please enter S (0 < S < 1000)";
					}
				}
				catch (const char* error) {
					cerr << error << endl;
				}
			} while (S < 0 && S > 100000);*/
		}
		string toString() {
			string RR, SS;
			RR = to_string(R);
			string res = "  Figure:\n    R = " + RR + "    Color: " + color;
			return res;
		}
	};

	class Square : public Figure {
	protected: 
		double a = 0; // side
		double d = 0; // diagonal
		double squareS = 0;
	public:
		 Square() : a(1.0), d(a*sqrt(2.0)), squareS(a*a) {}
		 Square(double aa) : a(aa) {
			 double RR = a * sqrt(2.0);
			 setR(RR);
		 }
		 Square(double R, string color) : Figure(R, color), a(R*sqrt(2.0)), d(a*sqrt(2.0)), squareS(a*a*1.0) {} // R given value 
		 Square(double a, string color, int) : Figure(color), d(a*(2.0)), squareS(a*a) { // a-side given value
			 double RR = a * sqrt(2.0);
			 setR(RR);
		 }
		 double getSide() { return a; }
		 void setSide(double aa) { a = aa; }
		 double getDiagonal() { return d; }
		 void setDiagonal(double dd) { d = dd; }
		 double getSquareS() { return squareS; }
		 void setSquareS(double S1) { squareS = S1; }

		 string toString() {
			 string aa, dd, S1;
			 aa = to_string(a);
			 dd = to_string(d);
			 S1 = to_string(squareS);
			 string res = "\n  Square: \n    Side(a) = " + aa + "\n    Diagonal = "
				 + dd + "\n    Area of square = " + S1;
			 return res;
		 }
	};

	class Circle : public Figure {
	protected: 
		double pi = 3.141592;
		double l; // arc of a circle
		double circleS;
	public:
		Circle() : l(1), circleS(pi * pow((l/2*pi), 2)) {}
		Circle(double RR, string col) : Figure(RR, col), l(pi * 2.0 * RR), circleS(pi * RR * RR) {}
		Circle(string col, double ll) : Figure(col), l(ll), circleS(pi * pow(ll / (2.0 * pi), 2)) {}

		double getL() { return l; }
		void setL(double ll) { l = ll; }
		double getS() { return circleS; }
		void setS(double S1) { circleS = S1; }

		string toString() {
			string ll, S1;
			ll = to_string(l);
			S1 = to_string(circleS);
			string res = "\n  Circle: \n    l = " + ll + "\n    Area of circle = " + S1;
			return res;
		}
	};

	class InscribedCircle : public Figure, public Square, public Circle {
	protected: 
		double r; // radius of the inscribed circle
		double insCS;
	public:
		InscribedCircle() : r(1), insCS(pi * (r * r)) {
		}
		InscribedCircle(double RR, string col) : Figure(RR, col) { 
			circleS = pi * RR * RR;
			a = RR * sqrt(2.0) * 1.0;
			d = RR * 2.0;
			squareS = a * a * 1.0;
			r = a / 2.0;
			insCS = pi * (r * r) * 1.0;
			l = pi * 2.0 * RR;
		}
		InscribedCircle(double aa, string col, int) : Square(aa), Figure(col) {
			squareS = aa * aa * 1.0;
			d = aa * sqrt(2.0) * 1.0;
			r = aa / 2.0;
			insCS = pi * (r * r) * 1.0;
			circleS = pi * pow((d / 2.0), 2) * 1.0;
			double RR = d / 2;
			l = pi * 2.0 * RR;
		}
		double get_r() { return r; }
		void set_r(double rr) {
			r = rr;
		}

		string toString() {
			string rr, S3;
			rr = to_string(r);
			S3 = to_string(insCS);
			string res = "\n------------------------------------------------" + Square::toString() 
				+ Circle::toString() + "\n  Inscribed circle:\n    r = " + rr 
				+ "\n    Area of an inscribed circle = " + S3 + "\n" + Figure::toString() 
				+ "\n------------------------------------------------";
			return res;
		}
	};

	int Task3() {
		InscribedCircle def;
		InscribedCircle objWithParams(4.0, "green");
		InscribedCircle objWithParams3(7, "yellow", NULL);
		InscribedCircle* obj = new InscribedCircle();
		obj->setSide(3);
		obj->setL(15);
		obj->set_r(1.5);
		obj->setSquareS(9);

		cout << def.toString() << endl;
		cout << "\n";
		cout << objWithParams.toString() << endl;
		cout << objWithParams3.toString() << endl;
		cout << obj->toString() << endl;

		return 0;
	}
}