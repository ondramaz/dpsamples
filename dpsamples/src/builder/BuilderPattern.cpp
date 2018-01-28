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
	// TODO Auto-generated constructor stub

}

BuilderPattern::~BuilderPattern() {
	// TODO Auto-generated destructor stub
}

class User {
private:
	std::string firstName;
	std::string middleName;
	std::string surName;

	User(std::string firstName, std::string middleName, std::string surName) :
			firstName(firstName), middleName(middleName), surName(surName) {
	}

	friend std::ostream& operator <<(std::ostream& stream, const User &u) {
		stream << u.firstName << " " << u.middleName << " " << u.surName;
		return stream;
	}

public:

	void doSomething();

	class UserBuilder;
};

class User::UserBuilder {

	std::string firstName;
	std::string middleName;
	std::string surName;

public:
	UserBuilder& setFirstName(std::string firstName) {
		this->firstName = firstName;
		return *this;
	}
	UserBuilder& setMiddleName(std::string firstName) {
		this->middleName = middleName;
		return *this;
	}
	UserBuilder& setSurName(std::string firstName) {
		this->surName = surName;
		return *this;
	}

	User build() {
		return User(firstName, middleName, surName);
	}
};

void BuilderPattern::run() {

	User u = User::UserBuilder().setFirstName(std::string("John")).build();
	std::cout << u;
}
