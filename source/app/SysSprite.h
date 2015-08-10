
#pragma once

#include "stdafx.h"

using namespace std;

/**
* This is meant to be a lightweight wrapper around loading image data. At some point, we could add
* more to this object such as basic dimensions for collision detection, etc. For now, it's a wrapper
* around image data.
*/
namespace core {
	class SysSprite {

	protected:
		/** object for storing our loaded image data */
		SDL_Texture* data;

	public:
		/**
		* Constructor
		*/
		SysSprite();

		/**
		* Destructor
		*/
		~SysSprite();

		/** attempting to load the image data from the given filePath,
		* using the SDL_Renderer to store our texture data
		*/
		int loadImage(string filePath, SDL_Renderer* renderer);

		/** unload and cleanup our stored image data */
		void unloadImage();

		/** retrieve our stored image data for this Sprite */
		SDL_Texture* getImageData();
	};
}

