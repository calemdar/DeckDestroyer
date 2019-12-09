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
}

// Do damage
int Enemy::doDamage() {
	// Send "view" event to Heath HUD indicating damage.
	df::EventView ev("Health", -getDamage(), true);
	WM.onEvent(&ev);
	LM.writeLog("Event sent -%d Damage", getDamage());
}

// Getters
Health Enemy::getHealth() const;
int Enemy::getDamage() const;