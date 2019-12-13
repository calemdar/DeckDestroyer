#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include "Object.h"
#include "Sprite.h"
#include "Location.h"
#include "Card.h"
#include "Health.h"
#include "Event.h"
#include "Reticle.h"
#include "ViewObject.h"

// Defaults
const int MANA_DEFAULT = 4;

class Player : public df::Object {
private:
	std::vector<Card*> hand;
	std::vector<Card*> permanent_deck;
	std::vector<Card*> deck;
	std::vector<Card*> discard;

	Health health;
	Reticle reticle;
	df::ViewObject mana;

public:
	Player();

	// Add cards to permanent deck
	void addCard(Card* new_card);

	// display Card at (x,y)
	void displayCard(Card* card, int x, int y);

	// Draw card from deck into hand
	Card* drawCard();

	// Draw card from deck into hand
	bool canDraw();

	// Draw upto 5 card from deck into hand
	void draw5Cards();

	// Move played card to the discard pile
	void discardCard(Card* card);

	// Shuffle cards
	std::vector<Card*> shuffle(std::vector<Card*> cards);

	int Player::eventHandler(const df::Event* p_e);

	// Getters
	std::vector<Card*> getPermanentDeck();
	std::vector<Card*> getDeck();
	std::vector<Card*> getHand();
	std::vector<Card*> getDiscard();
	df::ViewObject* getMana();
	df::ViewObject* getHealth();
};
#endif
