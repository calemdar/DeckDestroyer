#ifndef _CARDATTACK_H_
#define _CARDATTACK_H_

#include "Location.h"
#include "Card.h"

class CardAttack : public Card {
private:
	int damage;
	Location location;
	CardAttack();
	CardAttack(int new_damage);
	void setDamage(int new_damage);
	int getDamage() const;
	void play();
};
#endif // !_CARDATTACK_H_
