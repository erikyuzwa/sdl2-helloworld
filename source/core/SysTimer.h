
#pragma once

#include "SysHeaders.h"

/**
* This is a core object for acting as a timer for use in animations, events, etc.
* Nothing special but can come in handy for trying to time specific actions
* or whatever.
*
* a timer can generally be in one of three states: 
*  1. running and paused
*  2. running and not paused
*  3. stopped
*/
namespace core {

	class SysTimer {

		public:
			/**
			* Constructor 
			*/
			SysTimer();

			/**
			* Destructor
			*/
			~SysTimer();

			/** reset and start our internal timer */
			void run();

			/** stop our internal timer */
			void stop();

			/** pause our internal timer */
			void pause();

			/** unpause and resume our internal timer */
			void unpause();

			/** retrieve our internal tick count */
			Uint32 getTicks();

			/** is our timer running? */
			bool isRunning();

			/** is our timer paused? */
			bool isPaused();

		private:
			/** the clock time of our running timer */
			Uint32 ticks;

			/** the tick count stored when our timer was paused */
			Uint32 pausedTicks;

			/** false if our timer is active, true otherwise */
			bool paused;

			/** true if our timer is running, false otherwise */
			bool running;
	};
}


