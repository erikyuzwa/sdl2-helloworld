
#pragma once 

#include "stdafx.h"

using namespace std;

/**
* This is an object that is meant to be a lightweight wrapper around the SDL_TTF library
* which handles accessing True Type Font data. Similar to @SysAudio, we track all our
* TTF_Font data in a hashmap for easier management.
*/
namespace core {
	class SysFont {

		/** Hashmap for tracking our True Type Font data */
		map<string, TTF_Font*> fontsMap;

	public:
		/**
		* Constructor
		*/
		SysFont();

		/**
		* Destructor
		*/
		~SysFont();

		/** general startup function */
		int startup();

		/** general shutdown and cleanup function */
		void shutdown();

		/** attempt to load the given True Type Font data from filePath,
		* and stuff it into a Hashmap using the given keyName. Optionally,
		* you can specify a font point size
		*/
		int loadFont(string keyName, string filePath, int fontSize = 24);

		/** function for cleaning up and unloading all our font data */
		void unloadAllFonts();

		/** accessor function for retrieving the TTF_Font data stored
		* in the Hashmap under the given keyName 
		*/
		TTF_Font* getFont(string keyName);
	};
}
