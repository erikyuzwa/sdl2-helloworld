
#pragma once

#include "stdafx.h"

using namespace std;

/**
* This is an object that is meant to be a lightweight wrapper for SDL_Mixer.
* We don't actually need to do all that much. We are tracking our sound effects
* and music data within 2 STL hashmaps. Hashmaps are awesome. 
*/
namespace core {
	class SysAudio {

	protected:
	  /** Hashmap for tracking our sound effects */
      map<string, Mix_Chunk*> soundsMap;

	  /** Hashmap for tracking our music */
      map<string, Mix_Music*> musicMap;

	  /** is our sound hardware actually enabled? */
	  bool isEnabled;

	  /** our main volume level */
	  Uint32 volume;

	public:
		/**
		* Constructor
		*/
		SysAudio();

		/**
		* Destructor 
		*/
		~SysAudio();

		/** general startup function */
		int startup();

		/** general shutdown and cleanup function */
		void shutdown();

		/** attempt to load the sound effect data from the given 
		* filePath, and stuff it into the hashmap using the keyName
		*/
		int loadSound(string keyName, string filePath);

		/** attempt to play the sound effect using the given keyName */
		void playSound(string keyName);

		/** attempt to load the music data from the given filePath,
		* and stuff it into the hashmap using the keyName */
		int loadMusic(string keyName, string filePath);

		/** attempt to play the music using the given keyName */
		void playMusic(string keyName);

		/** get our main volume level */
		Uint32 getVolume();

		/** set our main volume level */
		void setVolume(Uint32 value);

		/** function for cleaning up and unloading all our sound data */
		void unloadAllSounds();

		/** function for cleaning up and unloading all our music data */
		void unloadAllMusic();
	};
}
