#include "CardAttack.h"
#include "EventView.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "Player.h"
#include "utility.h"


CardAttack::CardAttack() {
	damage = 1;
}
CardAttack::CardAttack(int new_damage) {
	damage = new_damage;
	setType("Attack");
	setText("Does %d damage.");
}

// Setters
void CardAttack::setDamage(int new_damage) {
	damage = new_damage;
	setType("Attack");
	setText("Does %d damage.");
}

// Getters
int CardAttack::getDamage() const{
	return damage;
}

// Play card 
void CardAttack::play() {
	if (getClickable() == false)
		return;
	setPlayed(true);

	// Do damage
	// Send "view" event to Heath HUD indicating damage.
	df::EventView ev("Enemy Health", - getDamage(), true);
	WM.onEvent(&ev);
	LM.writeLog("Event sent -%d Damage", getDamage());

	Player* player = dynamic_cast <Player*> (findMe("player"));

	player->discardCard(this);
	return;
}