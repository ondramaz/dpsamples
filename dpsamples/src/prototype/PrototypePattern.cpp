#include "PrototypePattern.h"

#include <iostream>

PrototypePattern::PrototypePattern() {
	//ctor
}

PrototypePattern::~PrototypePattern() {
	//dtor
}

class Monster {
public:
	virtual ~Monster() {
	}
	virtual Monster* clone() = 0;

	// Other stuff...
};

class Ghost: public Monster {
public:
	Ghost(int health, int speed) :
			health_(health), speed_(speed) {
	}

	virtual Monster* clone() {
		std::cout << "Clone ghost: " << health_ << ", " << speed_ << std::endl;
		return new Ghost(health_, speed_);
	}

private:
	int health_;
	int speed_;
};

class Spawner {
public:
	Spawner(Monster* prototype) :
			prototype_(prototype) {
	}

	Monster* spawnMonster() {
		return prototype_->clone();
	}

private:
	Monster* prototype_;
};

void PrototypePattern::run() {

	Monster* ghostPrototype = new Ghost(15, 3);
	Spawner* ghostSpawner = new Spawner(ghostPrototype);
	ghostSpawner->spawnMonster();

}
