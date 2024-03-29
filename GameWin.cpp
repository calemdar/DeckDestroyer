#include "GameWin.h"
#include "Card.h"
#include "Location.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"

GameWin::GameWin() {
	RM.loadSprite("sprites/game-win-spr.txt", "game-win");
	RM.loadMusic("sounds/game-win.wav", "win music");
	setType("GameWin");
	setSprite("game-win");
	setPosition(df::Vector(100, 30));
	//registerInterest(df::KEYBOARD_EVENT);  // Play start music.
	p_music = RM.getMusic("win music");
	playMusic();

	const df::ObjectList obj_under_pointer = WM.getAllObjects();

	LM.writeLog("Start Removing all objects!");
	if (!obj_under_pointer.isEmpty()) {
		// Found an object	
		df::ObjectListIterator li = df::ObjectListIterator(&obj_under_pointer);
		li.first();
		LM.writeLog("Object List Size: %d", obj_under_pointer.getCount());
		while (!li.isDone()) {
			LM.writeLog("Object Found %s", li.currentObject()->getType().c_str());
			if (li.currentObject()->getType() == "Card"
				|| li.currentObject()->getType() == "Player"
				|| li.currentObject()->getType() == "Enemy") {
				WM.markForDelete(li.currentObject());
			}
			li.next();
		}
	}
}

// Play start music.	
void GameWin::playMusic() {
	p_music->play(false);
}
