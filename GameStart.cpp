#include "GameStart.h"
#include "GameManager.h"
#include "Points.h"
#include "Player.h"
#include "ResourceManager.h"
#include <EventKeyboard.h>
#include "Enemy.h"
#include "Turn.h"

GameStart::GameStart() {
	setType("GameStart");
	setSprite("gamestart");
	setLocation(df::CENTER_CENTER);
	registerInterest(df::KEYBOARD_EVENT);  // Play start music.
	p_music = RM.getMusic("start music");
	playMusic();
}

// Play start music.
void GameStart::playMusic() {
	p_music->play();
}

int GameStart::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*) p_e;
		switch (p_keyboard_event->getKey()) {
		case df::Keyboard::P: 	// play
			start();
			break;
		case df::Keyboard::Q:	// quit
			GM.setGameOver();
			break;
		default:
			break;
		}
		return 1;
	}
	return 0;
}

void GameStart::start() {
	// Create card.
	Enemy* enemy = new Enemy;
	Player* p = new Player;
	Turn* turn = new Turn;

	RM.unloadSprite("sprites/gamestart-spr.txt");

	// When game starts, become inactive.
	setActive(false);
	// Pause start music.
	//p_music->pause();
}

// Override default draw so as not to display "value".
int GameStart::draw() {
	return df::Object::draw();
}