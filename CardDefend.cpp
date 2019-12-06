#include "CardDefend.h"

CardDefend::CardDefend() {
	block = 1;
	setType("Defend");
	setText("Does %d damage.");
}
CardDefend::CardDefend(int new_block) {
	block = new_block;
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
	// Add block to health
}