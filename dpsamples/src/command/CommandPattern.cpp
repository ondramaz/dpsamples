#include "CommandPattern.h"

#include <iostream>
#include <vector>
using namespace std;

CommandPattern::CommandPattern()
{
    //ctor
}

CommandPattern::~CommandPattern()
{
    //dtor
}


enum Direction
{
    LEFT, RIGHT, UP, DOWN
};

class GameActor
{
    int x,y;
    Direction direction;

public:
    GameActor() : x(0), y(0), direction(UP) {}
    void mov();
    void movBack();
    void left();
    void right();
    friend ostream& operator << (ostream &stream,GameActor &actor)
    {
     stream << "(" << actor.x << "," << actor.y << ")" << " " << actor.direction << endl;
     return stream;
    }

};


void GameActor::mov()
{
    switch (direction)
    {
        case LEFT: --x;  break;
        case RIGHT: ++x; break;
        case UP: ++y;    break;
        case DOWN: --y; break;
    }
}

void GameActor::movBack()
{
    switch (direction)
    {
        case LEFT: ++x;  break;
        case RIGHT: --x; break;
        case UP: --y;    break;
        case DOWN: ++y; break;
    }
}


void GameActor::left()
{
 switch (direction)
    {
        case LEFT: direction = DOWN;  break;
        case RIGHT: direction = UP; break;
        case UP: direction = LEFT;    break;
        case DOWN: direction = RIGHT; break;
    }
}

void GameActor::right()
{
 switch (direction)
    {
        case LEFT: direction = UP;  break;
        case RIGHT: direction = DOWN; break;
        case UP: direction = RIGHT;    break;
        case DOWN: direction = LEFT; break;
    }

}


class Cmd
{
public:
  virtual ~Cmd() {}
  virtual void execute(GameActor &actor) = 0;
  virtual void undo(GameActor &actor) = 0;
  virtual void redo(GameActor &actor) = 0;
};


class MoveCommand : public Cmd
{
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

class LeftCommand : public Cmd
{
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

class RightCommand : public Cmd
{
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


class Game
{
    std::vector<Cmd*> cmdList;
    std::vector<Cmd*>::iterator it;
public:
    Game() { it = cmdList.end();}
    void run();
private:

    void discard();
};


void Game::run()
{
    GameActor gameActor;

    while (true) {

        cout << "Enter command: (m)ove, l(eft), (r)ight, (u)ndo, r(e)do";
    	string cmd;
        cin >> cmd;

        if (cmd == "u") {       // undo
            if (it != cmdList.begin())
            {
                --it;
                (*it) -> undo(gameActor);
            }
        }
        else if (cmd == "e") {  // redo
            if (it != cmdList.end()) {
                (*it) -> redo(gameActor);
                ++it;
            }
        }
        else
        {
            discard();
            Cmd *newCmd = nullptr;
            if (cmd == "m") {
                newCmd = new MoveCommand();
            }
            else if (cmd == "l")
            {
                newCmd = new LeftCommand();
            }
            else if (cmd == "r") {
                newCmd = new RightCommand();
            }

            newCmd->execute(gameActor);
            cmdList.push_back(newCmd);
            it = cmdList.end();
        }
        cout << gameActor;
    }
}


    void Game::discard()
    {
        for (std::vector<Cmd*>::iterator it2 = it;it2 != cmdList.end();++it2)
            delete *it2;
        cmdList.erase(it,cmdList.end());

    }

void CommandPattern::run()
{
    Game g;
    g.run();
}
