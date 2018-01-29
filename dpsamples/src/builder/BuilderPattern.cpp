/*
 * BuilderPattern.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: ondra
 */

#include "BuilderPattern.h"

#include <iostream>
#include <string>

BuilderPattern::BuilderPattern() {
}

BuilderPattern::~BuilderPattern() {
}

class User {
private:
	string firstName;
	string middleName;
	string surName;

	User(string firstName, string middleName, string surName) :
			firstName(firstName), middleName(middleName), surName(surName) {
	}

	friend ostream& operator <<(ostream& stream, const User &u) {
		stream << u.firstName << " " << u.middleName << " " << u.surName;
		return stream;
	}

public:

	void doSomething();

	class UserBuilder;
};

class User::UserBuilder {

	string firstName;
	string middleName;
	string surName;

public:
	UserBuilder& setFirstName(string firstName) {
		this->firstName = firstName;
		return *this;
	}
	UserBuilder& setMiddleName(string firstName) {
		this->middleName = middleName;
		return *this;
	}
	UserBuilder& setSurName(string firstName) {
		this->surName = surName;
		return *this;
	}

	User build() {
		return User(firstName, middleName, surName);
	}
};

void BuilderPattern::run() {

	User u = User::UserBuilder().setFirstName(string("John")).build();
	cout << u;
}
