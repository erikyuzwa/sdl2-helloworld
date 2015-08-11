
#include "SysFont.h"

namespace core {

	SysTextLabel::SysTextLabel(){
		data = NULL;
	}

	SysTextLabel::~SysTextLabel(){

		if (data != NULL) {
			SDL_DestroyTexture(data);
		}
		
		SDL_assert(data == NULL);
	}

	SysFont::SysFont(SDL_Renderer* value) : renderer(value) {

	}

	SysFont::~SysFont(){

		shutdown();

		SDL_assert(fontsMap.empty());
		
	}

	int SysFont::loadFont(string keyName, string filePath, int fontSize) {

		TTF_Font* newFont;
		newFont = TTF_OpenFont(filePath.c_str(), fontSize);

		if (newFont == NULL) {
			printf("error initializing or loading font %s - error %s\n", filePath.c_str(), TTF_GetError());
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

	void SysFont::setRenderer(SDL_Renderer* value){
		renderer = value;
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

	SysTextLabel* SysFont::generateTextLabel(string keyName, string keyValue, SDL_Color keyColor){

		SysTextLabel* newLabel = new SysTextLabel();

		//step 1. create a temporary SDL_Surface using our given params
		SDL_Surface* tempLabel = TTF_RenderText_Solid(getFont(keyName), keyValue.c_str(), keyColor);
		if (tempLabel == NULL){
			printf("error creating label %s, using font %s\n", keyValue.c_str(), keyName.c_str());
			if (newLabel != NULL) {
				delete newLabel;
				return NULL;
			}
		}

		//step 2. use our SDL_Renderer to properly convert
		newLabel->data = SDL_CreateTextureFromSurface(renderer, tempLabel);

		//step 3. free our temporary surface
		SDL_FreeSurface(tempLabel);

		return newLabel;

	}

}