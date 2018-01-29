/*
 * PatternFactory.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: ondra
 */

#include "PatternFactory.h"

#include <sstream>

#include "adapter/AdapterPattern.h"
#include "builder/BuilderPattern.h"
#include "command/CommandPattern.h"
#include "decorator/DecoratorPattern.h"
#include "eventqueue/EventQueuePattern.h"
#include "Factory/FactoryPattern.h"
#include "observer/ObserverPattern.h"
#include "prototype/PrototypePattern.h"
#include "proxy/ProxyPattern.h"
#include "sandbox/SandboxPattern.h"
#include "servicelocator/ServiceLocatorPattern.h"
#include "template/TemplatePattern.h"

PatternFactory::PatternFactory() {
	patternList.push_back(new FactoryPattern());
	patternList.push_back(new BuilderPattern());
	patternList.push_back(new AdapterPattern());
	patternList.push_back(new CommandPattern());
	patternList.push_back(new DecoratorPattern());
	patternList.push_back(new EventQueuePattern);
	patternList.push_back(new ObserverPattern());
	patternList.push_back(new PrototypePattern());
	patternList.push_back(new ProxyPattern());
	patternList.push_back(new SandboxPattern());
	patternList.push_back(new ServiceLocatorPattern());
	patternList.push_back(new TemplatePattern());
}

PatternFactory::~PatternFactory() {
	for (auto p : patternList)
		delete p;
	patternList.clear();

}

Pattern *PatternFactory::getPattern(unsigned int patternNum) const {
	if (patternNum >= patternList.size())
		return nullptr;
	return patternList.at(patternNum);

}

string PatternFactory::toString() const {
	ostringstream s;
	int i = 0;
	for (Pattern *p : patternList) {
		s << i << "-" << p->name() << "\n";
		++i;
	}
	return s.str();
}
