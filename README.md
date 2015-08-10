# sdl2-helloworld
basic SDL2 project template for working on PC and MacOSX

Calling this a "hello world" is probably an insulting disservice to "Hello World" programs
everywhere, but it's a basic attempt at trying to help you bring some sanity into starting
cross platform development with SDL2.

The basic idea to this approach is a project structure that can be opened, edited and
debugged in the Visual Studio IDE as well as XCode -- without major folder surgery.

You might notice the CMake files within the structure. While not yet complete, I'm
working to add CMake support to this project as well.

# WHY?
Listen, it's hard enough getting a game put together without everyone wasting their precious
time and life energy on the annoying bits of getting started. My goal is to conquer the 
universe, recite all 8 mantras and restore order to the galaxy. If that's not enough, I 
want a testable, repeatable basic project structure that I can brainlessly copy and 
paste on any new SDL2 project. I want to only stress about this configuration stuff 
ONCE.

##As a (certified) Dudeist Priest, I want the same for you.##

## Platforms Supported
* windows
* macosx

## Building on Windows
* open Visual Studio IDE 
* open the visual studio project in `build\windows\<your_visual_studio_version>`
* build and debug in the IDE

## Building on MacOSX
* open XCode (6.4+)
* open the `build\mac\helloworld.xcodeproj`
* build and run from the IDE

## Developers Guide
Nothing fancy needed. Pretend I'm also waving my hands while mentioning `DRY principles`. Copy this entire
project folder structure as your app. As long as your putting everything in a different top-level folder,
then you'll never need to edit or modify the Visual Studio and XCode IDE project files. 
`Thank the Maker, this oil bath is going to feel so good.`

`As I find time and / or hear of interest, I may create small sample projects to demonstrate how this template
will work. Please reach me at @eyuzwa on the Twitters to voice your support.`

* Create your awesome class definitions in the source/app folder
* At the very least, extend the `core::AppCore` object
* Provide overrides for the `core::AppCore::startupApp()`, `core::AppCore::updateApp()` and `core::AppCore::shutdownApp()` functions

## Acknowledgements and Thanks
* the entire SDL2 community that tirelessly works on preserving / extending SDL2
* the LazyFoo tutorials for some of the SDL2 sticking points
* GB Games for his great SDL2 / developer focused content
* Sir Dupre for sacrificing himself and allowing his ashes to be fused with the Chaos Serpent.

## Version History
* 0.3.1 updated with SysTimer object
* 0.3.0 updated with SysAudio, SysFont, SysSprite objects
* 0.2.0 added support for VS2010
* 0.1.0 initial release

## License

The MIT License (MIT)

Copyright (c) 2015 Erik Yuzwa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.






