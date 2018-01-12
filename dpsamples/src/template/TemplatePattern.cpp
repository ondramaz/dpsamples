#include "TemplatePattern.h"
#include <iostream>

TemplatePattern::TemplatePattern() {
	//ctor
}

TemplatePattern::~TemplatePattern() {
	//dtor
}

class BaseClass {

protected:

	virtual void oper1() = 0;
	virtual void oper2() = 0;
	virtual void oper3() = 0;

// template
public:
	virtual ~BaseClass() {
	}
	void templateMethod();

};

void BaseClass::templateMethod() {
	oper1();
	oper2();
	oper3();
}

class DerivedClass1: public BaseClass {
protected:
	virtual void oper1() {
		std::cout << "Derived class 1- oper1" << std::endl;
	}
	virtual void oper2() {
		std::cout << "Derived class 1- oper2" << std::endl;
	}
	virtual void oper3() {
		std::cout << "Derived class 1- oper3" << std::endl;
	}
};

class DerivedClass2: public BaseClass {
protected:
	virtual void oper1() {
		std::cout << "Derived class 2- oper1" << std::endl;
	}
	virtual void oper2() {
		std::cout << "Derived class 2- oper2" << std::endl;
	}
	virtual void oper3() {
		std::cout << "Derived class 2- oper3" << std::endl;
	}
};

void TemplatePattern::run() {

	DerivedClass1 c1;
	c1.templateMethod();
	DerivedClass2 c2;
	c2.templateMethod();
}
