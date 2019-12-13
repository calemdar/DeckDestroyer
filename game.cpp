//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "Card.h"
#include "CardAttack.h"
#include "CardDefend.h"
#include "CardSpell.h"
#include "Health.h"
#include "Reticle.h"
#include "Player.h"
#include "Star.h"
#include "GameStart.h"
#include "Enemy.h"


void testCards() {
	

	CardAttack* attack = new CardAttack();
	Health health = Health();
	Reticle p = Reticle();
	Player* player = new Player();
	Enemy* enemy = new Enemy();

	attack->setName("Strike");
	attack->setText("Does 5 damage");
	attack->setSprite("strike");
	attack->setPosition(df::Vector(20,40));
	attack->play();

	player->setSprite("player");
	player->setPosition(df::Vector(30,20));
}

void setUpWorld() {
	WM.setBoundary(df::Box(df::Vector(0, 0), 200, 200));
	WM.setView(df::Box(df::Vector(0, 0), 200, 200));
}

// Load game resources.
void loadResources(void) {
	// Load sprites
	RM.loadSprite("sprites/card-spr.txt", "card");
	RM.loadSprite("sprites/cardDraw-spr.txt", "cardDraw");
	RM.loadSprite("sprites/player-spr.txt", "player");
	RM.loadSprite("sprites/enemy-spr.txt", "enemy1");
	RM.loadSprite("sprites/enemy-dead-spr.txt", "enemy1-dead");
	RM.loadSprite("sprites/enemy2-spr.txt", "enemy2");
	RM.loadSprite("sprites/enemy2-dead-spr.txt", "enemy2-dead");

	RM.loadSprite("sprites/gameover-spr.txt", "gameover");
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");

	RM.loadMusic("sounds/start-music.wav", "start music");
}
// Populate game world with some objects.
void populateWorld(void) {
	// Create some Stars.
	//for (int i = 0; i < 16; i++)
	//	new Star;

	// Enable player to pause game.
	//new df::Pause(df::Keyboard::F10);

	// Spawn GameStart object.
	new GameStart;
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

  // Load assets
  //setUpWorld();

  //testCards();

  // Load game resources.
  loadResources();

  // Populate game world with some objects.
  populateWorld();

  GM.run();

  // Shut everything down.
  GM.shutDown();
}

