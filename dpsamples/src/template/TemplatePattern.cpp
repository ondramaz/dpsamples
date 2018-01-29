#include "TemplatePattern.h"
#include <iostream>

TemplatePattern::TemplatePattern() {
}

TemplatePattern::~TemplatePattern() {
}

class BaseClass {

protected:

	virtual void method1() = 0;
	virtual void method2() = 0;
	virtual void method3() = 0;

// template
public:
	virtual ~BaseClass() {
	}
	void templateMethod();

};

void BaseClass::templateMethod() {
	method1();
	method2();
	method3();
}

class DerivedClass1: public BaseClass {
protected:
	virtual void method1() {
		cout << "Derived class 1- method1" << endl;
	}
	virtual void method2() {
		cout << "Derived class 1- method2" << endl;
	}
	virtual void method3() {
		cout << "Derived class 1- method3" << endl;
	}
};

class DerivedClass2: public BaseClass {
protected:
	virtual void method1() {
		cout << "Derived class 2- method1" << endl;
	}
	virtual void method2() {
		cout << "Derived class 2- method2" << endl;
	}
	virtual void method3() {
		cout << "Derived class 2- method3" << endl;
	}
};

void TemplatePattern::run() {

	DerivedClass1 c1;
	c1.templateMethod();
	DerivedClass2 c2;
	c2.templateMethod();
}
