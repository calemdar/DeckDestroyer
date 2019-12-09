#include "GameWin.h"
#include "Card.h"
#include "Location.h"
#include "ResourceManager.h"
#include "WorldManager.h"

GameWin::GameWin() {
	setType("GameWin");
	setSprite("game-win");
	setPosition(df::Vector(100, 30));
	//registerInterest(df::KEYBOARD_EVENT);  // Play start music.
	//p_music = RM.getMusic("start music");
	//playMusic();
	
}