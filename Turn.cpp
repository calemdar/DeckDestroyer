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
		if (enemy->getSpriteIterator() == 2) {
			// EAT THE CARD
			int flag = false;
			int eatCard = rand() % 5;
			int handSize = player->getHand().size();
			for (int i = 0;i < handSize;i++) {
				LM.writeLog("EAT IT!!!!!");
				Card* card = player->getHand()[i];
				if (card->getPlayed() == false && card->getEaten()==false) {
					flag = true;
					if (eatCard == 0) {
						player->discardCard(card, true);
						break;
					}
					eatCard--;
				}
				if (i == handSize - 1) {
					if (flag == false)
						break;
					i = -1;
				}
			}
		}
		setValue(0);
	}
	else if (turn == TurnPointer::ENEMY) {
		turn = TurnPointer::PLAYER;
		player->getMana()->setValue(4);
		player->draw5Cards();
		setValue(1);
	}
}
