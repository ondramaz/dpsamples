//============================================================================
// Name        : dpsamples.cpp
// Author      : Ondrej Mazanec
// Version     :
// Copyright   : 
// Description : Design pattern samples in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "Pattern.h"
#include "PatternFactory.h"

using namespace std;

int main() {

	PatternFactory factory;

	while (1) {

		cout << "\nChoose pattern: (-1 = exit) " << endl;
		cout << factory.toString();

		int num;
		cin >> num;

		if (num == -1)
			break;

		Pattern *p = factory.getPattern(num);
		if (p != nullptr)
			p->run();

	}
	return 0;
}
