#include "Enemy.h"
#include "Object.h"
#include "Health.h"
#include "EventView.h"
#include "WorldManager.h"
#include "LogManager.h"

Enemy::Enemy() {
	enemy_health = Health();
	enemy_health.setValue(ENEMY_HEALTH);
	enemy_health.setLocation(df::TOP_RIGHT); 
	enemy_health.setViewString("Enemy Health");

	attack_damage = 10;

	setSprite("enemy");
	setPosition(df::Vector(150, 20));
}

// Do damage
int Enemy::doDamage() {
	// Send "view" event to Heath HUD indicating damage.
	df::EventView ev("Player Health", -getDamage(), true);
	WM.onEvent(&ev);
	LM.writeLog("Event sent -%d Damage", getDamage());
	return attack_damage;
}

// Getters
Health Enemy::getHealth() const {
	return enemy_health;
}
int Enemy::getDamage() const {
	return attack_damage;
}