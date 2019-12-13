#include "CardSpell.h"
#include "Card.h"
#include "Location.h"
#include "utility.h"
#include "Player.h"
#include "LogManager.h"

CardSpell::CardSpell() {
	spell_description = "Draw one card";
	setType("Card");
	setCardType("Spell");
	setText("Draw one card");
}
CardSpell::CardSpell(std::string new_spell) {
	spell_description = new_spell;
	setType("Card");
	setCardType("Spell");
	setText(new_spell);
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
	LM.writeLog("Play Card Spell");
	if (getClickable() == false)
		return;
	setPlayed(true);

	// Play spell

	Player* player = dynamic_cast <Player*> (findMe("Player"));
	if (getText() == "Draw one card") {
		if(player->canDraw())
			player->drawCard();
	}
	else 
	if (getText() == "Heal") {
		player->heal();
	}

	player->discardCard(this);
	return;
}
