#include "GameWin.h"
#include "Card.h"
#include "Location.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"

GameWin::GameWin() {
	setType("GameWin");
	setSprite("game-win");
	setPosition(df::Vector(100, 30));
	//registerInterest(df::KEYBOARD_EVENT);  // Play start music.
	//p_music = RM.getMusic("start music");
	//playMusic();

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
				|| li.currentObject()->getType() == "player"
				|| li.currentObject()->getType() == "enemy") {
				WM.markForDelete(li.currentObject());
			}
			li.next();
		}
	}	
}
