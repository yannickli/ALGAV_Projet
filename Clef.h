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
	int i1;
	int i2;
	int i3;
	int i4;
public:
	Clef() {
		std::cout << "Erreur" << std::endl;
	}
	Clef(int a, int b, int c, int d) :
			i1(a), i2(b), i3(c), i4(d) {
	}
	Clef(const Clef & c) :
			i1(c.i1), i2(c.i2), i3(c.i3), i4(c.i4) {
	}
	int getI1() {
		return i1;
	}
	int getI2() {
		return i2;
	}
	int getI3() {
		return i3;
	}
	int getI4() {
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
	bool operator==(Clef a) {
		if (i1 == a.getI1())
			if (i2 == a.getI2())
				if (i3 == a.getI3())
					if (i4 == a.getI4())
						return true;
		return false;
	}
};

#endif /* CLEF_H_ */
