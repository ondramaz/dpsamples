/*
 * FactoryPattern.h
 *
 *  Created on: Jan 12, 2018
 *      Author: ondra
 */

#ifndef FACTORY_FACTORYPATTERN_H_
#define FACTORY_FACTORYPATTERN_H_

#include "../Pattern.h"


class FactoryPattern: public Pattern {
public:
	FactoryPattern();
	virtual ~FactoryPattern();
	void run();
	virtual std::string name() const { return "Factory pattern"; }
};


#endif /* FACTORY_FACTORYPATTERN_H_ */
