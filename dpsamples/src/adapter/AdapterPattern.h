/*
 * AdapterPattern.h
 *
 *  Created on: Jan 29, 2018
 *      Author: ondra
 */

#ifndef ADAPTER_ADAPTERPATTERN_H_
#define ADAPTER_ADAPTERPATTERN_H_

#include "../Pattern.h"

using namespace std;

class AdapterPattern: public Pattern {
public:
	AdapterPattern();
	virtual ~AdapterPattern();
	void run();
    virtual string name() const { return "Adapter pattern"; }
};

#endif /* ADAPTER_ADAPTERPATTERN_H_ */
