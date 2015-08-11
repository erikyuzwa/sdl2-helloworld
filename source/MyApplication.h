
#pragma once

#include "AppCore.h"

using namespace core;

/**
* This is the Application object that developers using this small package will start with. Every effort is being made to handle
* all the lower level SDL2 lifting in the base core::AppCore object. You need to just implement the virtual functions 
* declared here.
*/
class MyApplication : public AppCore {

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

	/** exposed function for handling your own update and render loop */
	virtual void updateApp(Uint32 delta);

	/** exposed function for handling your own shutdown and cleanup */
	virtual void shutdownApp();

};
