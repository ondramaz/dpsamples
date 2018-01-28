#include "ObserverPattern.h"

#include <iostream>
#include <sstream>
#include <vector>

ObserverPattern::ObserverPattern() {
	//ctor
}

ObserverPattern::~ObserverPattern() {
	//dtor
}

class Subject;

class Event {
protected:
	std::string name;

public:
	std::string asString() {
		return name;
	}
};

class MouseEvent: public Event {
	int code;
public:
	MouseEvent(int code) {
		this->code = code;
		std::stringstream ss;
		ss << "Mouse event: " << code;
		name = ss.str();
	}
};

class Listener {
public:

	virtual void onNotify(Subject const &s, Event *e) = 0;
	virtual ~Listener() {
	}
};

class ActionListener: public Listener {
public:

	void onNotify(Subject const &s, Event *e) {
		std::cout << "Action performed:" << e->asString() << std::endl;
	}
};

class Subject {
	std::vector<Listener*> ll;
public:

	void addListener(Listener *l);
	void notify(Event *e);
};

void Subject::addListener(Listener *l) {
	std::cout << "Listener registered\n";
	ll.push_back(l);
}

void Subject::notify(Event *e) {
	std::cout << "Notify event:" << e->asString() << "\n";
	for (auto l : ll) {
		l->onNotify(*this, e);
	}
}

class Button: public Subject {

public:
	void press() {
		MouseEvent e(10);
		notify(&e);
	}
};

void ObserverPattern::run() {

	ActionListener l;
	ActionListener l2;

	Button b;
	b.addListener(&l);
	b.addListener(&l2);

	b.press();
}
