
#include "SysSprite.h"

namespace core {

	SysSprite::SysSprite() {
		data = NULL;
	}

	SysSprite::~SysSprite() {

		unloadImage();
		
		SDL_assert(data == NULL);	
	}

	int SysSprite::loadImage(string filePath, SDL_Renderer* renderer) {

		// attempt to load image data from given path into an SDL_Surface object
		SDL_Surface* tempSurface = IMG_Load( filePath.c_str() ); 
		if ( tempSurface == NULL ) { 
			printf( "Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError() );
			return -1;
		} else { 
			// translate our loaded data into a normalized format
			data = SDL_CreateTextureFromSurface( renderer, tempSurface );

			// free our temporary image data 
			SDL_FreeSurface( tempSurface );
			
			if ( data == NULL ) {
		       printf( "Unable to create texture from %s! SDL Error: %s\n", filePath.c_str(), SDL_GetError() ); 
			   return -2;
			} 	
		} 

		return 0;
	}

	SDL_Texture* SysSprite::getImageData() {
		return data;
	}

	void SysSprite::unloadImage() {
		if (data != NULL) {
			SDL_DestroyTexture(data);
			data = NULL;
		}
	}
}