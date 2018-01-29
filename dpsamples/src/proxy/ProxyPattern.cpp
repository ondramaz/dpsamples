#include "ProxyPattern.h"
#include <map>
#include <iostream>

ProxyPattern::ProxyPattern() {
}

ProxyPattern::~ProxyPattern() {
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
	map<int, int> m;

public:

	virtual int compute(int input);
};

int ProxyEngine::compute(int input) {
	// check if key is present
	if (m.find(input) != m.end()) {
		int r = m[input];
		cout << "Returned hashed result:" << r << endl;
		return r;
	}

	int r = engine.compute(input);
	m[input] = r;
	cout << "Returned computed result:" << r << endl;
	return r;
}

void ProxyPattern::run() {

	ProxyEngine engine;
	engine.compute(10);
	engine.compute(20);
	engine.compute(10);
	engine.compute(20);

}

