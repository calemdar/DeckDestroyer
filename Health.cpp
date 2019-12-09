// Engine includes.
#include "DisplayManager.h"
#include "GameManager.h"		

// Game includes.
//#include "game.h"
#include "Health.h"
#include "GameWin.h"

Health::Health() {
	setViewString(HEALTH_STRING);
	setColor(df::YELLOW);
	setValue(STARTING_HEALTH);
	setType("Health");
}

// Handle event.
// Return 0 if ignored, else 1.
int Health::eventHandler(const df::Event* p_e) {

	// Call parent handler.
	if (df::ViewObject::eventHandler(p_e)) {
		if (getViewString() == "Player Health" && getValue() < 1)
			df::GameManager::getInstance().setGameOver();

		if (getViewString() == "Enemy Health" && getValue() < 1) {
			new GameWin();
		}
			
	}

	// If we get here, event not handled.
	return 0;
}