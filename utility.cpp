#include "utility.h"
#include "Player.h"
#include "ObjectList.h"
#include "WorldManager.h"

df::Object* findMe(std::string objectType) {
	df::ObjectList obj = WM.getAllObjects();
	df::ObjectListIterator li = df::ObjectListIterator(&obj);
	Player* player;
	li.first();
	while (!li.isDone()) {
		if (li.currentObject()->getType() == objectType) {
			return (li.currentObject());
		}
		li.next();
	}
	return NULL;
}