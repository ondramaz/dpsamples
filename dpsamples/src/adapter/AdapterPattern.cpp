/*
 * AdapterPattern.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: ondra
 */

#include "AdapterPattern.h"
#include <iostream>

using namespace std;

AdapterPattern::AdapterPattern() {
}

AdapterPattern::~AdapterPattern() {
}

class AudioPlayer {
public:
	virtual void play() = 0;
	virtual ~AudioPlayer() {
	}
};

class OldAudioPlayer {
	string song;

public:
	OldAudioPlayer(string song) :
			song(song) {
	}
	void oldPlay(int volume) {
		cout << "Playing song: " << song << " at volume: " << volume << "\n";
	}
};

class PlayerAdapter: public AudioPlayer, private OldAudioPlayer {
	int volume;
public:

	PlayerAdapter(string song, int volume) :
			OldAudioPlayer(song), volume(volume) {
	}

	void play() {
		oldPlay(volume);
	}
};

void AdapterPattern::run() {
	AudioPlayer *player = new PlayerAdapter(string("Ach synku"), 50);
	player->play();
	delete player;
}
