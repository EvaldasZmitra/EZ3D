#include "EventHandler.h"

void EventHandler::Update()
{
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			_shouldQuit = true;
			break;

		case SDL_EventType::SDL_KEYDOWN:
			break;

		default:
			break;
		}
	}
}
