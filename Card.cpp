#include "Card.h"
#include "Sprite.h"
#include "EventView.h"
#include "WorldManager.h"

Card::Card() {
	name = "Basic Name";
	cost = 1;
	text = "This is a very basic card that does nothing";
	type = "Spell";
	color = DEFAULT_CARD_COLOR;
	location = DECK;
}
Card::Card(std::string new_name, int new_cost, std::string new_type, std::string new_text) {
	name = new_name;
	cost = new_cost;
	type = new_type;
	text = new_text;
	color = DEFAULT_CARD_COLOR;
	location = DECK;
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
std::string Card::getType() const {
	return type;
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

	
	return;
}