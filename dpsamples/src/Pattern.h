/*
 * Pattern.h
 *
 *  Created on: Jan 8, 2018
 *      Author: ondra
 */

#ifndef PATTERN_H_
#define PATTERN_H_

#include <string>


class Pattern {
public:
	Pattern();
	virtual ~Pattern();
	virtual void run() = 0;
	virtual std::string name() const = 0;
};

#endif /* PATTERN_H_ */
