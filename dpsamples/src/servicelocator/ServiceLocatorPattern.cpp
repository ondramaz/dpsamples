#include "ServiceLocatorPattern.h"

#include <iostream>

ServiceLocatorPattern::ServiceLocatorPattern() {
}

ServiceLocatorPattern::~ServiceLocatorPattern() {
}

class Audio {
public:
	virtual ~Audio() {
	}
	virtual void playSound(int soundID) = 0;
	virtual void stopSound(int soundID) = 0;
	virtual void stopAllSounds() = 0;
};

class ConsoleAudio: public Audio {
public:
	virtual void playSound(int soundID) {
		cout << "Play sound using console audio api...\n";
	}

	virtual void stopSound(int soundID) {
		cout << "Stop sound using console audio api...\n";
	}

	virtual void stopAllSounds() {
		cout << "Stop all sounds using console audio api...\n";
	}
};

class LoggedAudio: public Audio {
public:
	LoggedAudio(Audio &wrapped) :
			wrapped_(wrapped) {
	}

	virtual void playSound(int soundID) {
		log("Play sound\n");
		wrapped_.playSound(soundID);
	}

	virtual void stopSound(int soundID) {
		log("Stop sound\n");
		wrapped_.stopSound(soundID);
	}

	virtual void stopAllSounds() {
		log("Stop all sounds\n");
		wrapped_.stopAllSounds();
	}

private:
	void log(const char* message) {
		cout << "Log:" << message;
	}

	Audio &wrapped_;
};

class Locator {
public:
	static Audio* getAudio() {
		return service_;
	}

	static void provide(Audio* service) {
		service_ = service;
	}

private:
	static Audio* service_;
};

Audio *Locator::service_;

void ServiceLocatorPattern::run() {

	ConsoleAudio *audio = new ConsoleAudio();
	Locator::provide(audio);

	Locator::getAudio()->playSound(1);

	// Decorate the existing service.
	Audio *service = new LoggedAudio(*Locator::getAudio());

	// Swap it in.
	Locator::provide(service);

	Locator::getAudio()->playSound(2);

	delete audio;
}

