#include "ObserverPattern.h"

#include <iostream>
#include <vector>

ObserverPattern::ObserverPattern() {
	//ctor
}

ObserverPattern::~ObserverPattern() {
	//dtor
}

class Subject;

class Event {
public:
	Event(int event) :
			event(event) {
	}

	int event;
};

class Listener {
public:

	virtual void onNotify(Subject const &s, Event const &e) = 0;
	virtual ~Listener() {
	}

};

class ActionListener: public Listener {
public:

	void onNotify(Subject const &s, Event const &e) {
		std::cout << "Action:" << e.event << std::endl;
	}

};

class Subject {
	std::vector<Listener*> ll;
public:

	void addListener(Listener *l);
	void notify(const Event &e);
};

void Subject::addListener(Listener *l) {
	ll.push_back(l);
}

void Subject::notify(const Event &e) {
	for (auto l : ll) {
		l->onNotify(*this, e);
	}
}

class Button: public Subject {

public:
	void press(char b) {
		notify(b);
	}
};

void ObserverPattern::run() {

	ActionListener l;
	ActionListener l2;

	Button b;
	b.addListener(&l);
	b.addListener(&l2);

	b.press(10);
}
