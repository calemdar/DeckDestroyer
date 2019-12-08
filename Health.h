#ifndef _HEALTH_H_
#define _HEALTH_H_

#include "Event.h"
#include "ViewObject.h"

// Global Defaults
#define STARTING_HEALTH 100
#define HEALTH_STRING "Health"


class Health : public df::ViewObject {

public:
	Health();
	int eventHandler(const df::Event* p_e);
	
};

#endif // !_HEALTH_H_