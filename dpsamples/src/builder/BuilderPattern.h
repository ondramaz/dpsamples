/*
 * BuilderPattern.h
 *
 *  Created on: Jan 28, 2018
 *      Author: ondra
 */

#ifndef BUILDER_BUILDERPATTERN_H_
#define BUILDER_BUILDERPATTERN_H_

#include "../Pattern.h"

class BuilderPattern : public Pattern {
public:
	BuilderPattern();
	virtual ~BuilderPattern();
	void run();
    virtual std::string name() const { return "Builder pattern"; }
};


#endif /* BUILDER_BUILDERPATTERN_H_ */
