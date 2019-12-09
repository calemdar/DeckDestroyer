#include <algorithm>  // for shuffle
#include "Player.h"
#include "Card.h"
#include "Location.h"
#include "LogManager.h"


Player::Player(){
	// Basic card
	permanent_deck.clear();
	deck.clear();
	hand.clear();
	discard.clear();

	for (int i = 0; i < 10; i++) {
		Card* attack = new Card("Strike", 2, "Attack", "Does 5 damage");
		attack->setSprite("strike");
		

		// Populate deck by default
		addCard(attack);
	}
	
	
}

// Getters
std::vector<Card*> Player::getPermanentDeck() {
	return permanent_deck;
}
std::vector<Card*> Player::getDeck() {
	return deck;
}
std::vector<Card*> Player::getHand() {
	return hand;
}
std::vector<Card*> Player::getDiscard() {
	return discard;
}

// Add cards to permanent deck
void Player::addCard(Card* new_card) {
	permanent_deck.push_back(new_card);
	deck.push_back(new_card);
}

// Draw card from deck into hand
Card* Player::drawCard() {
	// Get last element 
	Card* drawn = deck.at(deck.size() - 1);
	LM.writeLog("Drew card with name %s", drawn->getName().c_str());

	// add to hand
	hand.push_back(drawn);

	// remove from deck
	deck.pop_back();
	return drawn;
}

// Play Card, put it in the discard pile
void Player::playCard() {
	// Get last element 
	Card* drawn = deck.at(deck.size() - 1);
	LM.writeLog("Drew card with name %s", drawn->getName().c_str());

	// add to hand
	hand.push_back(drawn);

	// remove from deck
	deck.pop_back();
}

// Shuffle cards
std::vector<Card*> Player::shuffle(std::vector<Card*> cards) {
	std::vector<Card*> temp = cards;
	std::random_shuffle(temp.begin(), temp.end());
	return temp;
}

int Player::eventHandler(const df::Event* p_e) {
	return 0;
}


