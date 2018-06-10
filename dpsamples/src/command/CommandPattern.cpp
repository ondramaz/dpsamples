#include "CommandPattern.h"

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

CommandPattern::CommandPattern() {
}

CommandPattern::~CommandPattern() {
}

enum Direction {
	LEFT, RIGHT, UP, DOWN
};

class GameActor {
	int x, y;
	Direction direction;

public:
	GameActor() :
			x(0), y(0), direction(UP) {
	}
	void mov();
	void movBack();
	void left();
	void right();
	friend ostream& operator <<(ostream &stream, GameActor &actor) {
		stream << "(" << actor.x << "," << actor.y << ")" << " "
				<< actor.direction << endl;
		return stream;
	}

};

void GameActor::mov() {
	switch (direction) {
	case LEFT:
		--x;
		break;
	case RIGHT:
		++x;
		break;
	case UP:
		++y;
		break;
	case DOWN:
		--y;
		break;
	}
}

void GameActor::movBack() {
	switch (direction) {
	case LEFT:
		++x;
		break;
	case RIGHT:
		--x;
		break;
	case UP:
		--y;
		break;
	case DOWN:
		++y;
		break;
	}
}

void GameActor::left() {
	switch (direction) {
	case LEFT:
		direction = DOWN;
		break;
	case RIGHT:
		direction = UP;
		break;
	case UP:
		direction = LEFT;
		break;
	case DOWN:
		direction = RIGHT;
		break;
	}
}

void GameActor::right() {
	switch (direction) {
	case LEFT:
		direction = UP;
		break;
	case RIGHT:
		direction = DOWN;
		break;
	case UP:
		direction = RIGHT;
		break;
	case DOWN:
		direction = LEFT;
		break;
	}
}

class Cmd {
public:
	virtual ~Cmd() {
	}
	virtual void execute(GameActor &actor) = 0;
	virtual void undo(GameActor &actor) = 0;
	virtual void redo(GameActor &actor) = 0;
};

class MoveCommand: public Cmd {
public:
	virtual void execute(GameActor &actor) {
		actor.mov();
	}

	virtual void undo(GameActor &actor) {
		actor.movBack();
	}

	virtual void redo(GameActor &actor) {
		actor.mov();
	}

};

class LeftCommand: public Cmd {
public:
	virtual void execute(GameActor &actor) {
		actor.left();
	}
	virtual void undo(GameActor &actor) {
		actor.right();
	}

	virtual void redo(GameActor &actor) {
		actor.left();
	}

};

class RightCommand: public Cmd {
public:
	virtual void execute(GameActor &actor) {
		actor.right();
	}
	virtual void undo(GameActor &actor) {
		actor.left();
	}

	virtual void redo(GameActor &actor) {
		actor.right();
	}

};

class Game {
	std::vector<unique_ptr<Cmd>> cmdList;
	std::vector<unique_ptr<Cmd>>::iterator it;
public:
	Game() {
		it = cmdList.end();
	}
	void run();
private:
};

void Game::run() {
	GameActor gameActor;

	while (true) {

		cout << "Enter command: (m)ove, l(eft), (r)ight, (u)ndo, r(e)do";
		string cmd;
		cin >> cmd;

		if (cmd == "u") {       // undo
			if (it != cmdList.begin()) {
				--it;
				(*it)->undo(gameActor);
			}
		} else if (cmd == "e") {  // redo
			if (it != cmdList.end()) {
				(*it)->redo(gameActor);
				++it;
			}
		} else {
			Cmd *newCmd = nullptr;
			if (cmd == "m") {
				newCmd = new MoveCommand();
			} else if (cmd == "l") {
				newCmd = new LeftCommand();
			} else if (cmd == "r") {
				newCmd = new RightCommand();
			}

			if (newCmd == nullptr)
				break;

			newCmd->execute(gameActor);
			cmdList.emplace_back(newCmd);
			it = cmdList.end();
		}
		cout << gameActor;
	}
}

void CommandPattern::run() {
	Game g;
	g.run();
}
