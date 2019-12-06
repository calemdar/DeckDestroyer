#ifndef _CARDSPELL_H_
#define _CARDSPELL_H_

#include "Card.h"
#include "Location.h"

class  CardSpell : public Card {
private:
	std::string spell_description;


public:
	CardSpell();
	CardSpell(std::string new_spell);

	// Setters
	void setSpell(std::string new_spell);

	// Getters
	std::string getSpell() const;

	// Play Defend card
	void play();

};


#endif