
#pragma once

#include "SysCore.h"

using namespace core;

/**
* This is the Application object that developers using this small package will start with. Every effort is being made to handle
* all the lower level SDL2 lifting in the base core::AppCore object. You need to just implement the virtual functions 
* declared here.
*/
class MyApplication : public SysCore {

public:
	/**
	* Constructor
	*/
	MyApplication();

	/**
	* Destructor
	*/
	~MyApplication();

	/** exposed function for handling your own startup and object creation */
	virtual int startupApp();

	/** exposed function for handling keyboard input events */
	virtual int handleInputKeys(SDL_Event* keyboardEvent);

	/** exposed function for handling your own update and render loop */
	virtual void updateApp(Uint32 delta);

	/** exposed function for handling your own shutdown and cleanup */
	virtual void shutdownApp();

};
