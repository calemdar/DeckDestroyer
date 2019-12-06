#ifndef _CARDATTACK_H_
#define _CARDATTACK_H_

#include "Location.h"
#include "Card.h"

class CardAttack : public Card {
private:
	int damage;
	Location location;
};
#endif // !_CARDATTACK_H_
