#ifndef _TURN_H_
#define _TURN_H_

#include"ViewObject.h"
#include "WorldManager.h"

enum TurnPointer {
	PLAYER,
	ENEMY,
};

class Turn : public df::ViewObject {
public:
	TurnPointer turn;
	Turn();
	// ends turn, changes turn pointer
	void endTurn();

};
#endif
