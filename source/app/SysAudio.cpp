
#include "SysAudio.h"

namespace core {
	SysAudio::SysAudio(){

		isEnabled = false;
		volume = 0;

	}

	SysAudio::~SysAudio(){

		SDL_assert(soundsMap.empty());

		SDL_assert(musicMap.empty());

	}

	void SysAudio::unloadAllSounds(){

		//reset our maps
		for(map<string, Mix_Chunk*>::iterator i = soundsMap.begin(); i != soundsMap.end(); ++i){
			Mix_FreeChunk(i->second);
			i->second = 0;
		}

		soundsMap.clear();

	}

	void SysAudio::unloadAllMusic(){

		//reset our maps
		for(map<string, Mix_Music*>::iterator i = musicMap.begin(); i != musicMap.end(); ++i){
			Mix_FreeMusic(i->second);
			i->second = 0;
		}

		musicMap.clear();

	}

	int SysAudio::startup() {

		unloadAllSounds();

		unloadAllMusic();

		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
			printf("error initializing audio system - %s\n", SDL_GetError());
			isEnabled = false;
			return -1;
		}
			
		
		isEnabled = true;
		
		return 0;
	}

	void SysAudio::shutdown(){

		//free all of our audio
		unloadAllSounds();


		unloadAllMusic();

		//shutdown system
		Mix_CloseAudio();

	}

	int SysAudio::loadSound(string keyName, string filePath){

		if (!isEnabled) {
			return -2;
		}

		Mix_Chunk* newSound = Mix_LoadWAV(filePath.c_str());
		if(newSound == NULL){
			printf("error initializing or loading sound %s\n", filePath);
			return -1;
		}

		//now put it in our std::map
		soundsMap[keyName] = newSound;

		return 0;
	}

	void SysAudio::playSound(string keyName){

		if(soundsMap[keyName] != NULL){
			Mix_PlayChannel(-1, soundsMap[keyName], 0);
		}


	}

	int SysAudio::loadMusic(string keyName, string filePath){

		if (!isEnabled) {
			return -2;
		}

		Mix_Music* newMusic = Mix_LoadMUS(filePath.c_str());
		if(newMusic == NULL){
			printf("error initializing or loading music %s\n", filePath);
			return -1;
		}

		//now put it in our std::map
		musicMap[keyName] = newMusic;

		return 0;
	}

	void SysAudio::playMusic(string keyName){

		//play the music
		if(musicMap[keyName] != NULL){
			Mix_PlayMusic( musicMap[keyName], -1);
		}
		
	}

	Uint32 SysAudio::getVolume(){
		return volume;
	}

	void SysAudio::setVolume(Uint32 value){
		volume = value;
	}
}