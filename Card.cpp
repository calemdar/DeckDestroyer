#include "Card.h"
#include "Sprite.h"
#include "EventView.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventView.h"
#include "EventKeyboard.h"

Card::Card() {
	name = "Basic Name";
	cost = 1;
	text = "This is a very basic card that does nothing";
	type = "Spell";
	color = DEFAULT_CARD_COLOR;
	location = Location::DECK;

	setSprite("card");

	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);
	registerInterest(df::MSE_EVENT);


	setType("Card");

	df::Vector p(20, WM.getBoundary().getVertical() / 2);
	setPosition(p);
}
Card::Card(std::string new_name, int new_cost, std::string new_type, std::string new_text) {
	name = new_name;
	cost = new_cost;
	type = new_type;
	text = new_text;
	color = DEFAULT_CARD_COLOR;
	location = Location::DECK;
}

// Setters
void Card::setName(std::string new_name) {
	name = new_name;
}
void Card::setCost(int new_cost) {
	cost = new_cost;
}
void Card::setType(std::string new_type) {
	type = new_type;
}
void Card::setText(std::string new_text) {
	text = new_text;
}
void Card::setColor(df::Color new_color) {
	color = new_color;
}

// Getters
std::string Card::getName() const {
	return name;
}
int Card::getCost() const {
	return cost;
}
std::string Card::getType() const {
	return type;
}
std::string Card::getText() const {
	return text;
}
df::Color Card::getColor() const {
	return color;
}

void Card::play() {
	// play card 

	// Send "view" event to Heath HUD indicating damage.
	df::EventView ev("Health", -1, true);
	WM.onEvent(&ev);
	return;
}