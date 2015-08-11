
#pragma once

//if we're on Windows
#ifdef _WIN32
  //things that are applicable to win32 and win64
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#ifdef _WIN64
   //things that are win64 specific

#endif

#elif __APPLE__
  //MAC side of things!
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
  //ios simulator
#elif TARGET_OS_PHONE
  //ios device
#elif TARGET_OS_MAC
  //other MacOS desktop defines
#endif
#endif

#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <map>

namespace core {
  class AppCore;
  class SysAudio;
  class SysFont;
  class SysSprite;
  class SysTimer;
}
