#include "CardDefend.h"
#include "Enemy.h"
#include "utility.h"
#include "Player.h"
#include "EventView.h"

CardDefend::CardDefend() {
	block = 1;
	setType("Card");
	setText("Blocks %d health.");
	setSprite("card-block");
}
CardDefend::CardDefend(int new_block) {
	block = new_block;
	setType("Card");
	setText("Blocks %d health.");
	setSprite("card-block");
}

// Setters
void CardDefend::setBlock(int new_block) {
	block = new_block;
}

// Getters
int CardDefend::getBlock() const {
	return block;
}

// Play Defend card
void CardDefend::play() {

	if (getClickable() == false)
		return;

	Player* player = dynamic_cast <Player*> (findMe("Player"));
	Enemy* enemy = dynamic_cast <Enemy*> (findMe("Enemy"));

	if (getCost() <= player->getMana()->getValue()) {
		setPlayed(true);

		// Negate enemy damage
		enemy->setDamage(0);

		// use mana
		df::EventView e_mana("Mana", -getCost(), true);
		df::Event* e_mana_ptr = dynamic_cast <df::Event*> (&e_mana);
		player->getMana()->eventHandler(e_mana_ptr);

		player->discardCard(this);
		LM.writeLog("Defend Card played");
	}
	return;
}