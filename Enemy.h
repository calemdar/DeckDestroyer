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

class Enemy : public df::Object {
private:
	Health enemy_health;
	int attack_damage;
public:
	Enemy();

	// Does damage to the player
	int doDamage();

	// Getters
	Health getHealth() const;
	int getDamage() const;
};
#endif