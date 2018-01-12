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
#include "observer/ObserverPattern.h"
#include "prototype/PrototypePattern.h"
#include "proxy/ProxyPattern.h"
#include "sandbox/SandboxPattern.h"
#include "servicelocator/ServiceLocatorPattern.h"
#include "template/TemplatePattern.h"

class PatternFactory {
private:
	std::vector<Pattern*> patternVector;

public:
	PatternFactory() {
		patternVector.push_back(new CommandPattern());
		patternVector.push_back(new DecoratorPattern());
		patternVector.push_back(new EventQueuePattern);
		patternVector.push_back(new ObserverPattern());
		patternVector.push_back(new PrototypePattern());
		patternVector.push_back(new ProxyPattern());
		patternVector.push_back(new SandboxPattern());
		patternVector.push_back(new ServiceLocatorPattern());
		patternVector.push_back(new TemplatePattern());
		patternVector.push_back(new FactoryPattern);

	}
	Pattern *newPattern(unsigned int patternNum) {
		if (patternNum >= patternVector.size())
			return nullptr;
		return patternVector.at(patternNum);
	}

	std::string toString() const {
		std::ostringstream s;
		int i = 0;
		for (Pattern *p : patternVector) {
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

	Pattern *p = factoryPattern.newPattern(num);
	if (p != nullptr)
		p->run();

	return 0;
}
