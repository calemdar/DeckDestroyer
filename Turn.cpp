#include "Turn.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Enemy.h"
#include "LogManager.h"

Turn::Turn() {
	setPosition(df::Vector(100, 25));
	setAltitude(0);
	setViewString("End Turn");
	setType("Turn");
	setValue(1);
	turn = TurnPointer::PLAYER;
	
}

// ends turn, changes turn pointer
void Turn::endTurn() {
	df::ObjectList obj = WM.getAllObjects();
	df::ObjectListIterator li = df::ObjectListIterator(&obj);
	Enemy* enemy;
	li.first();
	while (!li.isDone()) {
		if (li.currentObject()->getType() == "enemy") {
			enemy = dynamic_cast <Enemy*> (li.currentObject());
			LM.writeLog("Enemy found");
			break;
		}
		li.next();
	}
	if (turn == TurnPointer::PLAYER) {
		turn = TurnPointer::ENEMY;
		enemy->doDamage();
		setValue(0);
	}
	else if (turn == TurnPointer::ENEMY) {
		turn = TurnPointer::PLAYER;
		setValue(1);
	}
}