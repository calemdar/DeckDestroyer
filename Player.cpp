#include <algorithm>  // for shuffle
#include "Player.h"
#include "Card.h"
#include "CardAttack.h"
#include "Location.h"
#include "LogManager.h"
#include "Windows.h"
#include <Clock.h>
#include "Vector.h"
#include "Reticle.h"
#include <WorldManager.h>


Player::Player() {

	setSprite("player");
	setType("player");
	setPosition(df::Vector(30, 20));
	reticle = Reticle();
	health.setViewString("Player Health");
	health.setLocation(df::TOP_LEFT);

	// Basic card
	permanent_deck.clear();
	deck.clear();
	hand.clear();
	discard.clear();

	for (int i = 0; i < 10; i++) {
		CardAttack* attack = new CardAttack();
		// Populate deck by default
		addCard(attack);
	}

	df::Clock mytimer = df::Clock();
	mytimer.delta();

	draw5Cards();
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
	new_card->setCardPosition(x+i, y-i-2);
	new_card->setVisible(true);
	new_card->setClickable(false);

	permanent_deck.push_back(new_card);
	deck.push_back(new_card);
}
void Player::displayCard(Card* card, int x, int y) {

	card->setPosition(df::Vector(x, y));
	card->setClickable(true);
}

// Draw card from deck into hand
Card* Player::drawCard() {
	// Get last element 
	Card* drawn = deck[(deck.size() - 1)];
	int x = 50;
	int y = 45;

	int i = hand.size();

	displayCard(drawn, x + 25 * i, y);

	//drawn->doPathFollowing();

	LM.writeLog("Drew card with name %s", drawn->getName().c_str());

	// add to hand
	hand.push_back(drawn);

	// remove from deck
	deck.pop_back();
	return drawn;
}

void Player::draw5Cards()
{
	LM.writeLog("DRAW 5 CARDS!!!");
	// delete displayed cards
	for (int i = 0; i < hand.size(); i++) {
		Card* card = hand[i];
		if (card->getPlayed()) {
			LM.writeLog("CARD %d WAS PLAYED!!!",i);
			for (int j = i + 1;j < hand.size();j++) {
				hand[j - 1] = hand[j];
			}
			hand.pop_back();
			i--;
		}
		else {
			LM.writeLog("Card not played, will be moved");
		}
	}

	LM.writeLog("DRAW not played %d CARDS!!!",int(hand.size()));

	// redraw not played cards
	for (int i = 0; i < hand.size(); i++) {
		int x = 50;
		int y = 45;

		int ii = i;
		displayCard(hand[i], x + 25 * ii, y);
	}

	// draw new cards up to 5
	while (canDraw() && hand.size() < 5) {
		drawCard();
	}
}

bool Player::canDraw() {
	return (deck.size() > 0);
}

// Move played card to the discard pile
void Player::discardCard(Card* card) {
	// Get last element 
	LM.writeLog("Discard card with name %s", card->getName().c_str());

	// add to discard pile
	int x = 50;
	int y = 45;

	card->setCardPosition(0, 0);
	card->setVisible(false);

	Card* newcard = new Card();
	discard.push_back(newcard);
	displayCard(newcard, x + 25 * 5 + discard.size(), y - discard.size() - 2);
	newcard->setClickable(false);
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

