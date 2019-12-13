#include <algorithm>  // for shuffle
#include "Player.h"
#include "Card.h"
#include "CardAttack.h"
#include "CardSpell.h"
#include "CardDefend.h"
#include "Location.h"
#include "LogManager.h"
#include "Windows.h"
#include <Clock.h>
#include "Vector.h"
#include "Reticle.h"
#include "utility.h"
#include <WorldManager.h>


Player::Player() {

	setSprite("player");
	setType("Player");
	setPosition(df::Vector(30, 20));

	reticle = Reticle();
	health.setViewString("Player Health");
	health.setType("Player Health");
	health.setLocation(df::TOP_LEFT);

	mana.setViewString("Mana");
	mana.setValue(MANA_DEFAULT);
	mana.setLocation(df::TOP_CENTER); \
	mana.setColor(df::CYAN);

	// Basic card
	permanent_deck.clear();
	deck.clear();
	hand.clear();
	discard.clear();

	// Add cards to player
	
	for (int i = 0; i < 3; i++) {
		//CardAttack* attack = new CardAttack();
		// Populate deck by default
		//addCard(attack);

		CardDefend* def = new CardDefend();
		// Populate deck by default
		addCard(def);
		CardAttack* attack1 = new CardAttack(5);
		CardAttack* attack2 = new CardAttack(10);
		CardSpell* spell = new CardSpell("Draw one card");
		CardAttack* attack3 = new CardAttack(20);
		CardSpell* heal = new CardSpell("Heal");

		attack1->setSprite("card");
		attack2->setSprite("card-smash");
		spell->setSprite("cardDraw");
		attack3->setSprite("card-charge");
		heal->setSprite("cardHeal");
		
		attack1->setCost(1);
		attack2->setCost(2);
		attack3->setCost(4);

		spell->setCost(1);
		heal->setCost(2);
		
		addCard(attack1);
		addCard(attack2);
		addCard(spell);
		addCard(attack3);
		addCard(heal);
	}
	
	
	CardDefend* def1 = new CardDefend(); 
	CardDefend* def2 = new CardDefend();

	def1->setCost(2);
	def2->setCost(2);

	addCard(def1);
	addCard(def2);

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
df::ViewObject* Player::getHealth() {
	return &health;
}
df::ViewObject* Player::getMana() {
	return &mana;
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

	// remove from deck
	deck.pop_back();

	int x = 50;
	int y = 45;

	int i = hand.size();
	bool flag = false;


	for (int i = 0;i < hand.size();i++) {
		if (hand[i]->getPlayed()==true) {
			hand[i] = drawn;
			displayCard(drawn, x + 25 * i, y);
			flag = true;
			break;
		}
	}
	if (flag == false) {
		displayCard(drawn, x + 25 * i, y);

		// add to hand
		hand.push_back(drawn);
	}

	LM.writeLog("Drew card with name %s", drawn->getName().c_str());


	return drawn;
}

void Player::draw5Cards()
{
	LM.writeLog("DRAW up to 5 cards. Fill empty spots!");

	// delete displayed cards
	for (int i = 0; i < hand.size(); i++) {
		Card* card = hand[i];
		if (card->getPlayed()) {
			if (deck.size() > 0) {
				drawCard();
			}
			else{
				for (int j = i + 1;j < hand.size();j++) {
					hand[j - 1] = hand[j];
				}
				hand.pop_back();
				i--;
			}
		}
	}

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
	return (int(deck.size()) > 0);
}

// Move played card to the discard pile
void Player::discardCard(Card* card) {
	LM.writeLog("Discard card with name %s", card->getName().c_str());

	// add to discard pile
	int x = 50;
	int y = 45;

	card->setCardPosition(1, 1);
	card->setVisible(false);

	Card* newcard;
	if (card->getCardType() == "Attack") {
		newcard = new  CardAttack();
	}else
	if (card->getCardType() == "Spell") {

		if (card->getText() == "Draw one card") {
			newcard = new  CardSpell("Draw one card");
			newcard->setSprite("cardDraw");
		}else
		if (card->getText() == "Heal") {
			newcard = new  CardSpell("Heal");
			newcard->setSprite("cardHeal");
		}
	}else
	if (card->getText() == "Blocks %d health.") {
		newcard = new  CardDefend();
		newcard->setSprite("card-block");
	}

	discard.push_back(newcard);
	displayCard(newcard, x + 25 * 5 + discard.size(), y - discard.size() - 2);
	newcard->setClickable(false);
}

void Player::heal(){
	df::ViewObject* player_health = dynamic_cast <df::ViewObject*> (findMe("Player Health"));
	int tmp_health = player_health->getValue();
	player_health->setValue(tmp_health + 5);
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

