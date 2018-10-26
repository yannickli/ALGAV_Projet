/*
 * Clef.h
 *
 *  Created on: 15 oct. 2018
 *      Author: 3305496
 */

#ifndef CLEF_H_
#define CLEF_H_

class Clef {
private:
	int i1;
	int i2;
	int i3;
	int i4;
public:
	Clef(int a, int b, int c, int d) :
			i1(a), i2(b), i3(c), i4(d) {
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
	bool inf(Clef a) {
		if (i1 != a.getI1())
			return i1 < a.getI1();
		if (i2 != a.getI2())
			return i2 < a.getI2();
		if (i3 != a.getI3())
			return i3 < a.getI3();
		return i4 < a.getI4();
	}
};

bool eg(Clef a1, Clef a2) {
	if (a1.getI1() == a2.getI1())
		if (a1.getI2() == a2.getI2())
			if (a1.getI3() == a2.getI3())
				if (a1.getI4() == a2.getI4())
					return true;
	return false;
}

// Methode compare pour trier une liste
/*bool compare_Clef(const Clef a, const Clef b) const {
 if (a.i1 != b.i1)
 return a.i1 < b.i1;
 if (a.i2 != b.i2)
 return a.i2 < b.i2;
 if (a.i3 != b.i3)
 return a.i3 < b.i3;
 return a.i4 < b.i4;
 }*/

#endif /* CLEF_H_ */
