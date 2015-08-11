
#include "AppCore.h"

namespace core {

	AppCore::AppCore() {
    
		mainWindow = NULL;
		mainRenderer = NULL;
		w = 800;
		h = 600;

		mainAudio = NULL;
		mainFont = NULL;
    
	}

	AppCore::~AppCore() {
    
		SDL_assert(mainRenderer == NULL);
		SDL_assert(mainWindow == NULL);
		
	}

	int AppCore::startup() {
    
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			printf("error initializing SDL : %s\n", SDL_GetError());
			return -1;
		}
    
		mainWindow = SDL_CreateWindow( "this could be YOUR title! - press ESC to quit",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			w, h,
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
		if (mainWindow == NULL) {
			printf("error initializing SDL_Window: %s\n", SDL_GetError());
			return -2;
		}
    
		mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (mainRenderer == NULL) {
			printf("error initializing SDL_Renderer: %s\n", SDL_GetError());
			return -3;
		}

		// make sure we start up some of our subsystems
		Uint32 imageFlags = IMG_INIT_PNG;
		if(!(IMG_Init(imageFlags) & imageFlags)){
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			return -4;
		}

		mainFont = new SysFont(mainRenderer);
		if(mainFont->startup() < 0){
			printf( "SysFont could not initialize - no font support for this session");
			return -5;
		}

 	    // attempt to load and initialize our SDL_Mixer lightweight wrapper. Change
		// this if you feel different, but if we encounter an error initializing
		// audio, we should still be able to play a game (just with no audio of course)
		mainAudio = new SysAudio();
		if (mainAudio->startup() < 0) {
			printf( "SysAudio could not initialize - no sound or music for this session");
		}
    
		// TODO - in your own extended object, handle initialization
		if (startupApp() < 0) {
			printf("error initializing app\n");
			return -10;
		}
    
		return 0;
	}

	int AppCore::update() {
    
		SDL_Event e;
    
		bool done = false;

		int frameCount = 0;

		float avgFps = 0.0f;

		frameTimer.run();
    
		// While application is running
		while( !done ) {
			// Handle events on queue
			while( SDL_PollEvent( &e ) != 0 ) {
				// User requests quit by closing the window
				if ( e.type == SDL_QUIT ) {
					done = true;
				} else if( e.type == SDL_KEYDOWN ) {
					// also quit on the ESC key
					if( e.key.keysym.sym == SDLK_ESCAPE ) {
						done = true;
					}
				}
			}

			// update our fps calculation
			avgFps = frameCount / ( frameTimer.getTicks() / 1000.0f);
			// an upper bound guard
			if (avgFps > 2000) {
				avgFps = 0;
			}
        
			// clear screen to blue
			SDL_SetRenderDrawColor( mainRenderer, 0x00, 0x00, 0xFF, 0xFF );
			SDL_RenderClear( mainRenderer );
        
			// TODO - in your own extended object, handle update and rendering
			updateApp(frameTimer.getTicks());
        
			// render everything to the screen
			SDL_RenderPresent( mainRenderer );
    
			// carryover of SDL1.2 hack for making sure app doesn't starve OS
			SDL_Delay(100);

			// increase our frame counter
			++frameCount;
		}
    
		return 0;
	}

	void AppCore::shutdown() {
    
		// TODO in your own extended object, handle shutdown and cleanup
		shutdownApp();

		// cleanup our audio subsystem
		if(mainAudio != NULL){
			mainAudio->shutdown();
			delete mainAudio;
			mainAudio = NULL;
		}

		// cleanup our font subsystem
		if (mainFont != NULL) {
			mainFont->shutdown();
			delete mainFont;
			mainFont = NULL;
		}
    
	    // cleanup and destroy our SDL_Renderer and SDL_Window objects
		SDL_DestroyRenderer(mainRenderer);
		SDL_DestroyWindow(mainWindow);
		mainRenderer = NULL;
		mainWindow = NULL;

        // cleanup the SDL_Image subsystem
		IMG_Quit();
		
		// cleanup any remaining SDL core objects
		SDL_Quit();

		
    
	}

}
