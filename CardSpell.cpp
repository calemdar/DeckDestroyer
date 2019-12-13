#include "CardSpell.h"
#include "Card.h"
#include "Location.h"
#include "utility.h"
#include "Player.h"
#include "LogManager.h"
#include "EventView.h"

CardSpell::CardSpell() {
	spell_description = "Draw one card";
	setType("Card");
	setCardType("Spell");
	setText("Draw one card");
}
CardSpell::CardSpell(std::string new_spell) {
	spell_description = "Draw one card";
	setType("Card");
	setCardType("Spell");
	setText("Draw one card");
}

// Setters
void CardSpell::setSpell(std::string new_spell) {
	spell_description = new_spell;
}

// Getters
std::string CardSpell::getSpell() const {
	return spell_description;
}

// Play spell
void CardSpell::play() {
	
	if (getClickable() == false)
		return;
	

	// Play spell

	Player* player = dynamic_cast <Player*> (findMe("Player"));

	if (getCost() <= player->getMana()->getValue()) {
		LM.writeLog("Play Card Spell");
		setPlayed(true);
		if (getText() == "Draw one card") {
			if (player->canDraw())
				player->drawCard();
		}
		// use mana
		df::EventView e_mana("Mana", -getCost(), true);
		df::Event* e_mana_ptr = dynamic_cast <df::Event*> (&e_mana);
		player->getMana()->eventHandler(e_mana_ptr);

		player->discardCard(this);
	}
	return;
}