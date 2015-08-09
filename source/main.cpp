
/**
 * main entry point for our application. Create our AppCore object, 
 * then initialize, run and cleanup our SDL2 base layer.
 *
 * note to devs: Don't update this entry point as much as possible. 
 * Extend from the AppCore and build your game from there.
 */
#include "AppCore.h"

int main(int argc, char** argv){
    
    AppCore* appCore = new AppCore();
    auto returnVal = 0;
    
    returnVal = appCore->startup();
    if (returnVal < 0) {
        goto CLEANUP_AND_EXIT;
    }
    
    returnVal = appCore->update();
    
//yup for realz. I use it to annoy the purists. :)
CLEANUP_AND_EXIT:
    if (appCore != NULL) {
        appCore->shutdown();
        delete appCore;
    }

	return returnVal;
}