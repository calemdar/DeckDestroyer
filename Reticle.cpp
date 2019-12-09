// Engine includes.
#include "EventMouse.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "Card.h"
#include "LogManager.h"
#include "Turn.h"

// Game includes.
#include "Reticle.h"

Reticle::Reticle() {
	setType("Reticle");
	setSolidness(df::SPECTRAL);
	setAltitude(df::MAX_ALTITUDE); // Make Reticle in foreground.

	// Reticle moves with mouse, so register.
	registerInterest(df::MSE_EVENT);

	// Start reticle in center of window.
	df::Vector p(WM.getBoundary().getHorizontal() / 2,
		WM.getBoundary().getVertical() / 2);
	setPosition(p);
}

// Handle event.
// Return 0 if ignored, else 1.
int Reticle::eventHandler(const df::Event* p_e) {

	if (p_e->getType() == df::MSE_EVENT) {
		const df::EventMouse* p_mouse_event = dynamic_cast <const df::EventMouse*> (p_e);
		// Check what clicked on
		if (p_mouse_event->getMouseAction() == df::CLICKED) {
			df::Vector mouse_pos = p_mouse_event->getMousePosition();
			const df::ObjectList obj_under_pointer = WM.objectsAtPosition(mouse_pos);
			LM.writeLog("Mouse clicked");

			if (!obj_under_pointer.isEmpty()) {
				// Found an object
				df::ObjectListIterator li = df::ObjectListIterator(&obj_under_pointer);
				li.first();
				LM.writeLog("Object List Size: %d", obj_under_pointer.getCount());
				while (!li.isDone()) {
					LM.writeLog("Object Found %s", li.currentObject()->getType().c_str());
					if (li.currentObject()->getType() == "Card") {
						Card* clicked_card = dynamic_cast <Card*> (li.currentObject());
						LM.writeLog("Object is a card");

						clicked_card->play();
						break;
					}
					if (li.currentObject()->getType() == "Turn") {
						Turn* turn_button = dynamic_cast <Turn*> (li.currentObject());
						turn_button->endTurn();
					}
					li.next();
				}
			}
		}
		
		if (p_mouse_event->getMouseAction() == df::MOVED) {
			// Change location to new mouse position.
			setPosition(p_mouse_event->getMousePosition());
			return 1;
		}
	}

	// If get here, have ignored this event.
	return 0;
}

// Draw reticle on window.
int Reticle::draw() {
	return DM.drawCh(getPosition(), RETICLE_CHAR, df::RED);
}
