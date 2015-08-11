
#pragma once 

#include "SysHeaders.h"

using namespace std;


namespace core {


	/**
	* This is an extremely lightweight wrapper around the SDL_Texture object.
	*/
	class SysTextLabel {
	public:
		SDL_Texture* data;
	public:
		SysTextLabel();
		~SysTextLabel();
	};

	/**
	* This is an object that is meant to be a lightweight wrapper around the SDL_TTF library
	* which handles accessing True Type Font data. Similar to @SysAudio, we track all our
	* TTF_Font data in a hashmap for easier management.
	*
	* There's a few things to manage when working with TTF in SDL2. We have 2 types
	* of cases for drawing text:
	* 1. static text (think a "label") - text which never changes. Such as your "level" or "score"
	*   types of text. Your actual score or level might change constantly, but the actual label never
	*   will.
	* 2. dynamic text - text which is constantly being updated. To continue the idea of a "score" label
	*   and actual value, the score value will be changing constantly.
	*/
	class SysFont {

		/** Hashmap for tracking our True Type Font data */
		map<string, TTF_Font*> fontsMap;

		SDL_Renderer* renderer;

	public:
		/**
		* Constructor
		*/
		SysFont(SDL_Renderer* renderer);

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

		void setRenderer(SDL_Renderer* value);

		SysTextLabel* generateTextLabel(string keyName, string keyValue, SDL_Color keyColor);

	};
}
