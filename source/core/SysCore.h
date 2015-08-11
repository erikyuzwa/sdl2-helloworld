
#pragma once

#include "SysHeaders.h"
#include "SysTimer.h"
#include "SysAudio.h"
#include "SysFont.h"
#include "SysSprite.h"

/**
* AppCore
* This object is a suggestion for maintaining the lower-level communication with SDL2. 
* Building your objects on top of this object, allows you to (try) and seperate
* your application away from SDL2. The benefit here is being able to update SDL2 components
* without needing to rework your entire application.
*/
namespace core {

	class SysCore {
    
	protected:
		/** display width */
		int           w;
    
		/** display height */
		int           h;
    
		/** SDL2 window pointer */
		SDL_Window*   mainWindow;
    
		/** SDL2 renderer pointer */
		SDL_Renderer* mainRenderer;

		/** a system timer to track fps */
		SysTimer frameTimer;

		/** a lightweight core object to wrap SDL_Mixer functionality */
		SysAudio* mainAudio;

		/** a lightweight core object to wrap SDL_TTF functionality */
		SysFont* mainFont;
    
	public:
		/**
		 * Constructor
		 */
		SysCore();
    
		/**
		 * Destructor
		 */
		virtual ~SysCore();
    
	public:
		/** startup and initialize our SDL2 base */
		int startup();
    
		/** run the main event loop which also draws */
		int update();
    
		/** shut everything down and cleanup */
		void shutdown();
    
		/** exposed function for handling your own startup and object creation */
		virtual int startupApp() = 0;
    
		/** exposed function for handling your own update and render loop */
		virtual void updateApp(Uint32 delta) = 0;
    
		/** exposed function for handling your own shutdown and cleanup */
		virtual void shutdownApp() = 0;
	};

}

