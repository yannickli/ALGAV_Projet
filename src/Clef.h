/*
 * Clef.h
 *
 *  Created on: 15 oct. 2018
 *      Author: 3305496
 */

#ifndef CLEF_H_
#define CLEF_H_

#include <iostream>

class Clef {
private:
	//i1 est l'entier de poids fort
	unsigned int i1;
	unsigned int i2;
	unsigned int i3;
	unsigned int i4;
public:
	Clef() :
			i1(0), i2(0), i3(0), i4(0) {
	}
	Clef(unsigned int a, unsigned int b, unsigned int c, unsigned int d) :
			i1(a), i2(b), i3(c), i4(d) {
	}
	Clef(const Clef & c) :
			i1(c.i1), i2(c.i2), i3(c.i3), i4(c.i4) {
	}
	unsigned int getI1() {
		return i1;
	}
	unsigned int getI2() {
		return i2;
	}
	unsigned int getI3() {
		return i3;
	}
	unsigned int getI4() {
		return i4;
	}
	bool operator<(Clef a) {
		if (i1 != a.getI1())
			return i1 < a.getI1();
		if (i2 != a.getI2())
			return i2 < a.getI2();
		if (i3 != a.getI3())
			return i3 < a.getI3();
		return i4 < a.getI4();
	}
	bool operator>(Clef a) {
		if (i1 != a.getI1())
			return i1 > a.getI1();
		if (i2 != a.getI2())
			return i2 > a.getI2();
		if (i3 != a.getI3())
			return i3 > a.getI3();
		return i4 > a.getI4();
	}
	bool operator==(Clef a) {
		if (i1 == a.getI1())
			if (i2 == a.getI2())
				if (i3 == a.getI3())
					if (i4 == a.getI4())
						return true;
		return false;
	}
	void afficher() {
		std::cout << i1 << "." << i2 << "." << i3 << "." << i4 << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& os, const Clef& c);
};

#endif /* CLEF_H_ */
