
#include "SysTimer.h"

namespace core {
	SysTimer::SysTimer() {

		// initialize the variables
		ticks = 0;
		pausedTicks = 0;
		paused = false;
		running = false;

	}

	SysTimer::~SysTimer() {

	}

	void SysTimer::run() {
		
		// get the current clock time
		ticks = SDL_GetTicks();
		pausedTicks = 0;
		
		// start the timer
		running = true;

		// unpause the timer
		paused = false;
	}

	void SysTimer::stop() {
		// stop the timer
		running = false;

		// unpause the timer
	    paused = false;

		// clear tick variables
		ticks = 0;
		pausedTicks = 0;
	}

	void SysTimer::pause() {
		// if the timer is running and isn't already paused
		if ( running && !paused ) {
			// pause the timer
			paused = true;

			// calculate the paused ticks
			pausedTicks = SDL_GetTicks() - ticks;
			ticks = 0;
		}
	}

	void SysTimer::unpause() {
		// if the timer is running and paused
		if ( running && paused ) {
			// unpause the timer
			paused = false;

			// reset the starting ticks
			ticks = SDL_GetTicks() - pausedTicks;

			// reset the paused ticks
			pausedTicks = 0;
		}
	}

	Uint32 SysTimer::getTicks() {
		// the actual timer time
		Uint32 time = 0;

		// if the timer is running
		if ( running ) {
			// if the timer is paused
			if ( paused ) {
				// return the number of ticks when the timer was paused
				time = pausedTicks;
			} else {
				// return the current time minus the start time
				time = SDL_GetTicks() - ticks;
			}
		}

		return time;
	}

	bool SysTimer::isRunning() {
		// timer is running and paused or unpaused
		return running;
	}

	bool SysTimer::isPaused() {
		// timer is running and paused
		return paused && running;
	}
}
