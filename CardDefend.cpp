#include "CardDefend.h"
#include "Enemy.h"
#include "utility.h"
#include "Player.h"

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
	setPlayed(true);

	// Negate enemy damage
	Enemy* enemy = dynamic_cast <Enemy*> (findMe("Enemy"));
	enemy->setDamage(0);

	Player* player = dynamic_cast <Player*> (findMe("Player"));

	player->discardCard(this);
	LM.writeLog("Defend Card played");
	return;
}