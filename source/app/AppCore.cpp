
#include "AppCore.h"

AppCore::AppCore() {
    
    mainWindow = NULL;
    mainRenderer = NULL;
    w = 800;
    h = 600;
    
}

AppCore::~AppCore() {
    
    
}

int AppCore::startup() {
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("error initializing SDL : %s\n", SDL_GetError());
        return -1;
    }
    
    mainWindow = SDL_CreateWindow( "SDL2 - helloworld - press ESC to quit",
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
    
    //TODO - in your own extended object, handle initialization
    if (startupApp() < 0){
        printf("error initializing app\n");
        return -4;
    }
    
    return 0;
}

int AppCore::update() {
    
    SDL_Event e;
    
    bool done = false;
    
    //While application is running
    while( !done ) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit by closing the window
            if ( e.type == SDL_QUIT ) {
                done = true;
            } else if( e.type == SDL_KEYDOWN ) {
                //also quit on the ESC key
                if( e.key.keysym.sym == SDLK_ESCAPE ) {
                    done = true;
                }
            }
        }
        
        //clear screen to blue
        SDL_SetRenderDrawColor( mainRenderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderClear( mainRenderer );
        
        //TODO - in your own extended object, handle update and rendering
        updateApp();
        
        //render everything to the screen
        SDL_RenderPresent( mainRenderer );
    
        //carryover of SDL1.2 hack for making sure app doesn't starve OS
        SDL_Delay(100);
    }
    
    return 0;
}

void AppCore::shutdown() {
    
    //TODO in your own extended object, handle shutdown and cleanup
    shutdownApp();
    
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    mainRenderer = NULL;
    mainWindow = NULL;
    
    SDL_Quit();
    
}