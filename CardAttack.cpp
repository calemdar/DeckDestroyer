#include "CardAttack.h"
#include "EventView.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "Player.h"
#include "utility.h"
#include "Enemy.h"
#include "Health.h"


CardAttack::CardAttack() {
	damage = 1;
	setType("Card");
	setCardType("Attack");
}
CardAttack::CardAttack(int new_damage) {
	damage = new_damage;
	setType("Card");
	setCardType("Attack");
	setText("Does %d damage.");
}

// Setters
void CardAttack::setDamage(int new_damage) {
	damage = new_damage;
	setType("Card");
	setCardType("Attack");
	setText("Does %d damage.");
}

// Getters
int CardAttack::getDamage() const{
	return damage;
}

// Play card 
void CardAttack::play() {
	if (getClickable() == false)
		return;
	

	Player* player = dynamic_cast <Player*> (findMe("Player"));
	Enemy* enemy = dynamic_cast <Enemy*> (findMe("Enemy"));
	
	if (getCost() <= player->getMana()->getValue()) {
		setPlayed(true);
		// Do damage
		// Send "view" event to Heath HUD indicating damage.
		Health* enemy_health = enemy->getHealth();
		df::EventView ev("Enemy Health", -getDamage(), true);
		df::EventView e_mana("Mana", -getCost(), true);
		df::Event* e_ptr = dynamic_cast <df::Event*> (&ev);
		df::Event* e_mana_ptr = dynamic_cast <df::Event*> (&e_mana);
		enemy_health->eventHandler(e_ptr);
		player->getMana()->eventHandler(e_mana_ptr);

		if (enemy_health->getValue() <= 0) {
			enemy->die();


			int handSize = player->getHand().size();
			for (int i = 0; i < handSize; i++) {
				Card* c = player->getHand()[i];
				if (c->getPlayed() == false) {
					c->setClickable(false);
				}
			}
		}

		//df::EventView ev("Enemy Health", - getDamage(), true);
		//WM.onEvent(&ev);
		//LM.writeLog("Event sent -%d Damage", getDamage());
		player->discardCard(this);
		LM.writeLog("Attack Card played");
	}
	return;
}
