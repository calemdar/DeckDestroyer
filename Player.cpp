#include <algorithm>  // for shuffle
#include "Player.h"
#include "Card.h"
#include "Location.h"
#include "LogManager.h"
#include "Windows.h"
#include <Clock.h>
#include <Vector.h>


Player::Player() {

	// Basic card
	permanent_deck.clear();
	deck.clear();
	hand.clear();
	discard.clear();

	// Populate deck by default
	for (int i = 0; i < 5; i++) {
		Card* c = new Card;
		addCard(c);
	}

	df::Clock mytimer = df::Clock();
	mytimer.delta();

	for (int i = 0; i < 5; i++) {
		//while (mytimer.split() < 500);
		drawCard();
		mytimer.delta();
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
	int x = 20;
	int y = 45;
	int i = deck.size();
	new_card->setCardPosition(x+i, y-i);
	new_card->setVisible(true);

	permanent_deck.push_back(new_card);
	deck.push_back(new_card);
}

// Draw card from deck into hand
Card* Player::drawCard() {
	// Get last element 
	Card* drawn = deck[(deck.size() - 1)];
	int x = 50;
	int y = 45;
	int i = hand.size();

	//drawn->moveTo(df::Vector(x + 5 * i, y - i));
	drawn->setVelocity(df::Vector(1,0));
	//drawn->doPathFollowing();

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
