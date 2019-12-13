#include "Enemy.h"
#include "Object.h"
#include "Health.h"
#include "EventView.h"
#include "EventOut.h"
#include "EventStep.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "GameWin.h"
#include "utility.h"
#include "ViewObject.h"

Enemy::Enemy() {
	enemy_health = Health();
	enemy_health.setValue(ENEMY_HEALTH);
	enemy_health.setLocation(df::TOP_RIGHT); 
	enemy_health.setViewString("Enemy Health");
	enemy_health.setType("Enemy Health");
	attack_damage = BASE_DAMAGE;

	sprite_iterator = 0;

	// add enemy sprites in order. first normal sprite, then dead sprite
	sprite_names.clear();
	sprite_names.push_back("enemy1");
	sprite_names.push_back("enemy1-dead");
	sprite_names.push_back("enemy2");
	sprite_names.push_back("enemy2-dead");

	setSprite(sprite_names[sprite_iterator]);
	setPosition(df::Vector(150, 20));
	setType("Enemy");

	// Event Handling
	registerInterest(df::STEP_EVENT);
	registerInterest(df::OUT_EVENT);
}

// Set damage 
void Enemy::setDamage(int new_damage) {
	attack_damage = new_damage;
}
// Do damage
int Enemy::doDamage() {
	// Send "view" event to Heath HUD indicating damage.
	if (attack_damage > 0) {
		df::ViewObject* player_health = dynamic_cast <df::ViewObject*> (findMe("Player Health"));
		int tmp_health = player_health->getValue();
		player_health->setValue(tmp_health - attack_damage);
	}
	else {
		setDamage(BASE_DAMAGE);
	}

	//df::EventView ev("Player Health", -getDamage(), true);
	//WM.onEvent(&ev);
	//LM.writeLog("Event sent -%d Damage", getDamage());
	return attack_damage;
}

// Getters
Health* Enemy::getHealth() {
	return &enemy_health;
}
int Enemy::getDamage() const {
	return attack_damage;
}

// called when enemy health reaches 0
void Enemy::die() {
	// change to dead sprite

	sprite_iterator++;

	if (sprite_names.size() > sprite_iterator) {
		
		enemy_health.setColor(df::RED);
		setSprite(sprite_names[sprite_iterator]);
		setVelocity(df::Vector(0, 2));
		setAltitude(1);
		LM.writeLog("Enemy is dead");
	}
}

void Enemy::changeEnemy() {
	// change to the next sprite
	sprite_iterator++;
	LM.writeLog("Sprite Iterator: %d", sprite_iterator);

	if (sprite_names.size() > sprite_iterator) {
		enemy_health.setValue(ENEMY_HEALTH);
		enemy_health.setColor(df::YELLOW);
		setPosition(df::Vector(150, 20));
		setSprite(sprite_names[sprite_iterator]);
		setVelocity(df::Vector(0, 0));
		LM.writeLog("Enemy Changed");
	}
	else {
		// No enemies left set game over
		new GameWin;
	}

}

int Enemy::eventHandler(const df::Event* p_e) {

	//LM.writeLog("Enemy got event to handle");
	if (p_e->getType() == df::OUT_EVENT) {
		changeEnemy();
		return 0;
	}
	/*
	else if (p_e->getType() == df::VIEW_EVENT) {
		
		if (enemy_health.getValue() < 1) {
			die();
			LM.writeLog("die() is called for enemy");
			return 0;
		}

	}
	*/
	// error if it got here
	return -1;
}