//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Star.h"
#include "GameStart.h"

// Load game resources.
void loadResources(void) {
	// Load sprites
	//RM.loadSprite("sprites/saucer-spr.txt", "saucer");
	//RM.loadSprite("sprites/ship-spr.txt", "ship");
	RM.loadSprite("sprites/card-spr.txt", "card");
	//RM.loadSprite("sprites/card-strike-spr.txt", "card-strike");
	//RM.loadSprite("sprites/explosion-spr.txt", "explosion");
	RM.loadSprite("sprites/gameover-spr.txt", "gameover");
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	//RM.loadSprite("sprites/game-win-spr.txt", "game-win");

	RM.loadMusic("sounds/start-music.wav", "start music");
}
// Populate game world with some objects.
void populateWorld(void) {
	// Create some Stars.
	for (int i = 0; i < 16; i++)
		new Star;

	// Enable player to pause game.
	//new df::Pause(df::Keyboard::F10);

	// Spawn GameStart object.
	new GameStart();
}
int main(int argc, char *argv[]) {

  // Start up game manager.
  if (GM.startUp())  {
    LM.writeLog("Error starting game manager!");
    GM.shutDown();
    return 0;
  }

  // Set flush of logfile during development (when done, make false).
  LM.setFlush(true);

  // Show splash screen.
  df::splash();


  // Load game resources.
  loadResources();

  // Populate game world with some objects.
  populateWorld();

  GM.run();

  // Shut everything down.
  GM.shutDown();
}

