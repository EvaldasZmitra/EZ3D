#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "EventHandler/EventHandler.h"
#include "AssetManager/AssetManager.h"
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "Mesh/Mesh.h"
#include <iostream>
#include <fstream>
#undef main

int main(int argc, char* argv[])
{
    auto window = Window();
	auto render = Renderer();
	auto eventHandler = EventHandler();

	auto assetManager = AssetManager();
	auto _model = Model(assetManager.MeshStore["CubeMesh"], assetManager.ShaderStore["Shader1"]);
	render.AddModel(_model);

	while (!eventHandler.ShouldQuit())
	{
		eventHandler.Update();
		render.Render();
		window.Update();
	}
    return 0;
}