#include "Card.h"
#include "Sprite.h"
#include "EventView.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventKeyboard.h"

Card::Card() {
	name = "Basic Name";
	cost = 1;
	text = "This is a very basic card that does nothing";
	color = DEFAULT_CARD_COLOR;
	location = Location::DECK;

	setSprite("card");
	setSolidness(df::SOFT);

	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);
	registerInterest(df::MSE_EVENT);


	setType("Card");
}
void Card::setCardPosition(int x,int y) {
	df::Vector p(x, y);
	setPosition(p);
}
Card::Card(std::string new_name, int new_cost, std::string new_type, std::string new_text) {
	name = new_name;
	cost = new_cost;
	text = new_text;
	color = DEFAULT_CARD_COLOR;
	setType(new_type);
	location = Location::DECK;
}

// Setters
void Card::setName(std::string new_name) {
	name = new_name;
}
void Card::setCost(int new_cost) {
	cost = new_cost;
}
void Card::setText(std::string new_text) {
	text = new_text;
}
void Card::setColor(df::Color new_color) {
	color = new_color;
}
void Card::setLocation(Location new_location) {
	location = new_location;
}

// Getters
std::string Card::getName() const {
	return name;
}
int Card::getCost() const {
	return cost;
}
std::string Card::getText() const {
	return text;
}
df::Color Card::getColor() const {
	return color;
}
Location Card::getLocation() const{
	return location;
}

void Card::play() {
	// play card 
	LM.writeLog("Basic Card played");
	
	return;
}
