#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>
#include <vector>
#include "Object.h"
#include "Location.h"
#include "Card.h"
#include "Health.h"
#include "Event.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "ViewObject.h"

// Enemy base damage
const int BASE_DAMAGE = 10;

class Enemy : public df::Object {
private:
	Health enemy_health;
	int attack_damage;
	std::vector<std::string> sprite_names,sprite_path;
	int sprite_iterator;
public:
	Enemy();

	// Does damage to the player
	int doDamage();
	void setDamage(int new_damage);
	// Getters
	Health* getHealth();
	int getSpriteIterator();
	int getDamage() const;
	// Called when enemy health reaches 0
	void die();
	// Event Handler return 0 if no problem
	int eventHandler(const df::Event* p_e);
	// Spawns new enemy
	void changeEnemy();
};
#endif