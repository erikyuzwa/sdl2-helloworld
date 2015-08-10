
#include "SysFont.h"

namespace core {
	SysFont::SysFont(){

	}

	SysFont::~SysFont(){

		shutdown();

		SDL_assert(fontsMap.empty());
		
	}

	int SysFont::loadFont(string keyName, string filePath, int fontSize) {

		TTF_Font* newFont;
		newFont = TTF_OpenFont(filePath.c_str(), fontSize);

		if (newFont == NULL) {
			printf("error initializing or loading font %s - error %s\n", filePath, TTF_GetError());
			return -1;
		}

		fontsMap[keyName] = newFont;
		
		return 0;
	}

	void SysFont::unloadAllFonts() {

		for(map<string, TTF_Font*>::iterator i = fontsMap.begin(); i != fontsMap.end(); ++i){
			TTF_CloseFont(i->second);
			i->second = 0;
		}

		fontsMap.clear();

	}

	TTF_Font* SysFont::getFont(string keyName) {
		return fontsMap[keyName];
	}

	int SysFont::startup() {

		if( TTF_Init() < 0 ) { 
			printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ); 
			return -1;
		}

		unloadAllFonts();

		return 0;
	}

	void SysFont::shutdown() {

		unloadAllFonts();

		TTF_Quit();

	}
}