#include "AssetManager.h"

AssetManager::AssetManager()
{
	std::ifstream i("Resources/scene.json");
	nlohmann::json j;
	i >> j;

	auto modelLoader = ModelLoader();
	for (auto meshKV : j["Meshes"].items())
	{
		auto meshKey = meshKV.key();
		auto meshValue = meshKV.value();
		auto meshFileName = meshValue["FilePath"].get<std::string>();
		auto mesh = modelLoader.LoadModel(meshFileName);
		MeshStore.insert({ meshKey, mesh });
	}

	for (auto materialKV : j["Materials"].items())
	{
		auto materialKey = materialKV.key();
		auto materialValue = materialKV.value();
		auto shaderName = materialValue["Shader"].get<std::string>();
		auto shader = ShaderStore[shaderName];
		auto material = new Material(shader);

		for (auto textureName : materialValue["Textures"].items())
		{
			auto textureNameStr = textureName.value().get<std::string>();
			auto texture = TextureStore[textureNameStr];
		}
	}

	for (auto textureKV : j["Textures"].items())
	{
		auto textureKey = textureKV.key();
		auto textureValue = textureKV.value();
		auto textureFile = textureValue["FilePath"].get<std::string>();
		auto texture = new Texture(textureFile);
		TextureStore.insert({ textureKey, texture });
	}

	for (auto shaderKV : j["Shaders"].items())
	{
		auto shaderKey = shaderKV.key();
		auto shaderValue = shaderKV.value();

		auto shaderFragmentFile = shaderValue["FragmentPath"].get<std::string>();
		auto shaderVertexFile = shaderValue["VertexPath"].get<std::string>();
	
		auto shader = new Shader();
		auto vShader = ReadText(shaderVertexFile);
		auto fShader = ReadText(shaderFragmentFile);
		shader->AddShader(fShader, GL_FRAGMENT_SHADER);
		shader->AddShader(vShader, GL_VERTEX_SHADER);
		shader->Compile();

		shader->AddTexture(TextureStore["Brick_Diffuse"], "myTextureSampler");
		shader->AddTexture(TextureStore["Brick_Normals"], "myNormalSampler");

		ShaderStore.insert({ shaderKey, shader });
	}

	for (auto entity : j["Entities"])
	{
	}
}

std::string AssetManager::ReadText(const std::string& file)
{
	std::ifstream t(file);
	std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	return str;
}
