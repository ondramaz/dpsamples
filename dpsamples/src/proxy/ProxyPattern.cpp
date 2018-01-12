#include "ProxyPattern.h"
#include <map>
#include <iostream>

ProxyPattern::ProxyPattern() {
	//ctor
}

ProxyPattern::~ProxyPattern() {
	//dtor
}

class Engine {
public:
	virtual ~Engine() {
	}
	virtual int compute(int input) = 0;
};

class RealEngine: public Engine {

public:
	virtual int compute(int input);
};

int RealEngine::compute(int input) {
	return input * input;
}

class ProxyEngine: public Engine {
	RealEngine engine;
	std::map<int, int> m;

public:

	virtual int compute(int input);
};

int ProxyEngine::compute(int input) {
	// check if key is present
	if (m.find(input) != m.end()) {
		int r = m[input];
		std::cout << "Returned hashed result:" << r << std::endl;
		return r;
	}

	int r = engine.compute(input);
	m[input] = r;
	std::cout << "Returned computed result:" << r << std::endl;
}

void ProxyPattern::run() {

	ProxyEngine engine;
	engine.compute(10);
	engine.compute(20);
	engine.compute(10);
	engine.compute(20);

}

