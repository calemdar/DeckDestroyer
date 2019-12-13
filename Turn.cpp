#include "Turn.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Enemy.h"
#include "Player.h"
#include "LogManager.h"
#include "utility.h"

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
	Enemy* enemy = dynamic_cast <Enemy*> (findMe("Enemy"));
	Player* player = dynamic_cast <Player*> (findMe("Player"));


	if (turn == TurnPointer::PLAYER) {
		turn = TurnPointer::ENEMY;
		enemy->doDamage();
		setValue(0);
	}
	else if (turn == TurnPointer::ENEMY) {
		turn = TurnPointer::PLAYER;
		player->draw5Cards();
		setValue(1);
	}
}
