#include "SandboxPattern.h"
#include <iostream>

SandboxPattern::SandboxPattern() {
	//ctor
}

SandboxPattern::~SandboxPattern() {
	//dtor
}

class BaseClass {

protected:

	void oper1() {
		std::cout << "Oper1" << std::endl;
	}

	void oper2() {
		std::cout << "Oper2" << std::endl;
	}

	void oper3() {
		std::cout << "Oper3" << std::endl;
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
		oper1();
		oper2();
	}
};

class DerivedClass2: public BaseClass {
public:
	virtual void sandbox() {
		oper3();
		oper1();
	}
};

void SandboxPattern::run() {

	DerivedClass1 c1;
	c1.sandbox();
	DerivedClass2 c2;
	c2.sandbox();
}

