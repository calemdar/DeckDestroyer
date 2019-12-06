#include "CardSpell.h"
#include "Card.h"
#include "Location.h"

CardSpell::CardSpell() {
	spell_description = "Draw one card";
	setType("Spell");
	setText("Draw one Card");
}
CardSpell::CardSpell(std::string new_spell) {
	spell_description = "Draw one card";
	setType("Spell");
	setText("Draw one Card");
}

// Setters
void CardSpell::setSpell(std::string new_spell) {
	spell_description = new_spell;
}

// Getters
std::string CardSpell::getSpell() const {
	return spell_description;
}

// Play Defend card
void CardSpell::play() {
	// Play spell
}