#ifndef _CARDATTACK_H_
#define _CARDATTACK_H_

#include "Location.h"
#include "Card.h"

class CardAttack : public Card {
private:
	int damage;

public:
	CardAttack();
	CardAttack(int new_damage);

	// Setters
	void setDamage(int new_damage);
	

	// Getters
	int getDamage()const;

	Location location;

	void play();
};
#endif // !_CARDATTACK_H_
