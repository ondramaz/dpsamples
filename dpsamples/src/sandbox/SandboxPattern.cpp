#include "SandboxPattern.h"
#include <iostream>

SandboxPattern::SandboxPattern() {
}

SandboxPattern::~SandboxPattern() {
}

class BaseClass {

protected:

	void method1() {
		cout << "Method1" << endl;
	}

	void method2() {
		cout << "Method2" << endl;
	}

	void method3() {
		cout << "Method3" << endl;
	}

// sandbox
public:
	virtual void sandbox() = 0;
	virtual ~BaseClass() {
	}

};

class DerivedClass1: public BaseClass {
public:
	virtual void sandbox() {
		method1();
		method2();
	}
};

class DerivedClass2: public BaseClass {
public:
	virtual void sandbox() {
		method3();
		method1();
	}
};

void SandboxPattern::run() {

	DerivedClass1 c1;
	c1.sandbox();
	DerivedClass2 c2;
	c2.sandbox();
}

