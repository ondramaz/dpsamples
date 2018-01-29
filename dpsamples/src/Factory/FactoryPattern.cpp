/*
 * FactoryPattern.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: ondra
 */

#include "FactoryPattern.h"
#include <list>
#include <iostream>

FactoryPattern::FactoryPattern() {
}

FactoryPattern::~FactoryPattern() {
}

class Room
{
	public:
		Room() {}
};

class MagicRoom : public Room
{
public:
		MagicRoom() : Room() { cout << "Create magic room.\n";  }
};

class OrdinaryRoom : public Room
{
public:
		OrdinaryRoom() : Room() { cout << "Create ordinary room.\n";  }
};

class MazeGame
{
	list<Room> roomList;

public:

	MazeGame();
	virtual ~MazeGame();

	void initRooms();
	virtual Room makeRoom() = 0;
};


MazeGame::MazeGame()
{
}

MazeGame::~MazeGame()
{

}

void MazeGame::initRooms()
{
	roomList.push_front(makeRoom());
	roomList.push_front(makeRoom());
	roomList.push_front(makeRoom());
}


class OrdinaryMazeGame : public MazeGame
{
	virtual Room makeRoom()
	{
		return OrdinaryRoom();
	}
};

class MagicMazeGame : public MazeGame
{
	virtual Room makeRoom()
	{
		return MagicRoom();
	}
};


void FactoryPattern::run() {
	MagicMazeGame magicGame;
	magicGame.initRooms();
	OrdinaryMazeGame ordinaryGame;
	ordinaryGame.initRooms();
}
