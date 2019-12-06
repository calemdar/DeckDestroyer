#ifndef _CARDDEFEND_H_
#define _CARDDEFEND_H_

#include "Card.h"
#include "Location.h"

class  CardDefend : public Card {
private:
	int block;
	

public:
	CardDefend();
	CardDefend(int new_block);
	
	// Setters
	void setBlock(int new_block);
	
	// Getters
	int getBlock() const;

	// Play Defend card
	void play();

};


#endif