
#include "SysSprite.h"

namespace core {

	SysSprite::SysSprite() {

		data = NULL;

	}

	SysSprite::~SysSprite() {

		unloadImage();
		
	}

	int SysSprite::loadImage(string filePath, SDL_Renderer* renderer) {

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load( filePath.c_str() ); 
		if ( loadedSurface == NULL ) { 
			printf( "Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError() );
			return -1;
		} else { 
			//Create texture from surface pixels 
			data = SDL_CreateTextureFromSurface( renderer, loadedSurface ); 

			//Get rid of old loaded surface 
			SDL_FreeSurface( loadedSurface );
			
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