#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include "Object.h"
#include "Sprite.h"
#include "Location.h"

// DEFAULTS
const df::Color DEFAULT_CARD_COLOR = df::Color::GREEN;


class Card : public df::Object {
	
private:
	std::string name;			// Card name
	int cost;					// Card cost to play
	std::string text;			// Card text explaining card effect
	df::Color color;			// Card Color
	Location location;

public:
	Card();
	Card(std::string new_name, int new_cost, std::string new_type, std::string new_text);
	void setCardPosition(int x,int y);
	// Setters
	void setName(std::string new_name);
	void setCost(int new_cost);
	void setText(std::string new_text);
	void setColor(df::Color new_color);
	void setLocation(Location new_location);

	// Getters
	std::string getName() const;
	int getCost() const;
	std::string getText() const;
	df::Color getColor() const;
	Location getLocation() const;
	
	virtual void play();
};

#endif // !_CARD_H_
