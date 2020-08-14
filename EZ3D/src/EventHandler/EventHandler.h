#pragma once
#include <SDL.h>

class EventHandler
{
public:
	void Update();
	bool ShouldQuit() {
		return _shouldQuit;
	}

private:
	SDL_Event _event = SDL_Event();
	bool _shouldQuit = false;
};

