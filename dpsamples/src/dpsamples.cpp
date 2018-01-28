//============================================================================
// Name        : dpsamples.cpp
// Author      : Ondrej Mazanec
// Version     :
// Copyright   : 
// Description : Design pattern samples in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "command/CommandPattern.h"
#include "decorator/DecoratorPattern.h"
#include "eventqueue/EventQueuePattern.h"
#include "Factory/FactoryPattern.h"
#include "builder/BuilderPattern.h"
#include "observer/ObserverPattern.h"
#include "prototype/PrototypePattern.h"
#include "proxy/ProxyPattern.h"
#include "sandbox/SandboxPattern.h"
#include "servicelocator/ServiceLocatorPattern.h"
#include "template/TemplatePattern.h"

class PatternFactory {
private:
	std::vector<Pattern*> patternList;

public:
	PatternFactory() {
		patternList.push_back(new FactoryPattern());
		patternList.push_back(new BuilderPattern());
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
	Pattern *getPattern(unsigned int patternNum) {
		if (patternNum >= patternList.size())
			return nullptr;
		return patternList.at(patternNum);
	}

	std::string toString() const {
		std::ostringstream s;
		int i = 0;
		for (Pattern *p : patternList) {
			s << i << "-" << p->name() << "\n";
			++i;
		}
		return s.str();
	}

};

int main() {

	PatternFactory factoryPattern;

	std::cout << "Choose pattern:" << std::endl;
	std::cout << factoryPattern.toString();

	unsigned int num;
	std::cin >> num;

	Pattern *p = factoryPattern.getPattern(num);
	if (p != nullptr)
		p->run();

	return 0;
}
