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

class Player : public df::Object {
private:
	std::vector<Card*> hand;
	std::vector<Card*> permanent_deck;
	std::vector<Card*> deck;
	std::vector<Card*> discard;

	Health health;

public:
	Player();

	// Add cards to permanent deck
	void addCard(Card* new_card);

	// Draw card from deck into hand
	Card* drawCard();

	// Play Card, put it in the discard pile
	void playCard();

	// Shuffle cards
	std::vector<Card*> shuffle(std::vector<Card*> cards);

	int Player::eventHandler(const df::Event* p_e);

	// Getters
	std::vector<Card*> getPermanentDeck();
	std::vector<Card*> getDeck();
	std::vector<Card*> getHand();
	std::vector<Card*> getDiscard();



};
#endif