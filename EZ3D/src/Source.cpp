#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "EventHandler/EventHandler.h"
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "Mesh/Mesh.h"
#undef main

int main(int argc, char* argv[])
{
    auto window = Window();
	auto render = Renderer();
	auto eventHandler = EventHandler();

	while (!eventHandler.ShouldQuit())
	{
		eventHandler.Update();
		render.Render();
		window.Update();
	}
    return 0;
}