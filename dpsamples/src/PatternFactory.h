/*
 * PatternFactory.h
 *
 *  Created on: Jan 29, 2018
 *      Author: ondra
 */

#ifndef PATTERNFACTORY_H_
#define PATTERNFACTORY_H_

#include <string>
#include <vector>

#include "Pattern.h"

using namespace std;

class PatternFactory {
	vector<Pattern*> patternList;

public:
	PatternFactory();
	virtual ~PatternFactory();
	Pattern *getPattern(unsigned int patternNum) const;
	string toString() const;

private:
};

#endif /* PATTERNFACTORY_H_ */

