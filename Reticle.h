#ifndef _RETICLE_H_
#define _RETICLE_H_

#include "Object.h"

#define RETICLE_CHAR '+'

class Reticle : public df::Object {

public:
	Reticle();
	int draw(void);
	int eventHandler(const df::Event* p_e);
};
#endif

