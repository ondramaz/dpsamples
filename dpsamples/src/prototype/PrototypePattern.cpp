#include "PrototypePattern.h"

#include <iostream>
#include <memory>

PrototypePattern::PrototypePattern() {
}

PrototypePattern::~PrototypePattern() {
}

class Monster {
public:
	virtual ~Monster() {
	}
	virtual std::unique_ptr<Monster> clone() = 0;

	// Other stuff...
};

class Ghost: public Monster {
public:
	Ghost(int health, int speed) :
			health_(health), speed_(speed) {
	}

	virtual std::unique_ptr<Monster> clone() {
		cout << "Clone ghost: " << health_ << ", " << speed_ << endl;
		return std::unique_ptr<Monster>(new Ghost(health_, speed_));
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

	std::unique_ptr<Monster> spawnMonster() {
		return prototype_->clone();
	}

private:
	Monster* prototype_;
};

void PrototypePattern::run() {

	std::unique_ptr<Monster> ghostPrototype(new Ghost(15, 3));
	std::unique_ptr<Spawner> ghostSpawner(new Spawner(ghostPrototype.get()));
	ghostSpawner->spawnMonster();
}
