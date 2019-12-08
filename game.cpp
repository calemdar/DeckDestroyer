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



void loadSprites() {
	RM.loadSprite("sprites/card-spr.txt", "strike");
}

void testCards() {
	

	CardAttack attack = CardAttack(5);
	Health health = Health();
	Reticle p = Reticle();

	attack.setName("Strike");
	attack.setText("Does 5 damage");
	attack.setSprite("strike");
	attack.setPosition(df::Vector(20,10));
	attack.play();
	

	GM.run();

	
}

void setUpWorld() {
	WM.setBoundary(df::Box(df::Vector(0, 0), 200, 200));
	WM.setView(df::Box(df::Vector(0, 0), 100, 100));
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
  loadSprites();
  setUpWorld();

  testCards();

  // Shut everything down.
  GM.shutDown();
}

