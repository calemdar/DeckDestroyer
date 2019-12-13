#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "Object.h"
#include "Card.h"
#include "Location.h"
#include "ResourceManager.h"
#include "ViewObject.h"


class GameOver : public df::Object {
public:
	GameOver();
	df::Music* p_music;
	void playMusic();
};

#endif