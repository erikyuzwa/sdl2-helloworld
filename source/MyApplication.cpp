
#include "MyApplication.h"

MyApplication::MyApplication() : SysCore() {

	//TODO handle any constructor initialization here

}

MyApplication::~MyApplication() {

	//TODO handle any (final) cleanup here
}

int MyApplication::startupApp() {

	//TODO initialize and create any dynamic objects on the heap

	return 0;
}

int MyApplication::handleInputKeys(SDL_Event* keyboardEvent){

    //TODO handle any keyboard event keys - return -1 to also quit
	return 0;
}

void MyApplication::updateApp(Uint32 delta) {

	//TODO update our game world and render it

}

void MyApplication::shutdownApp() {

	//TODO cleanup and release objects that are taking up dynamic heap

}