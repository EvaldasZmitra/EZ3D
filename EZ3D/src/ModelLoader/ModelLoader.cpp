#include "ModelLoader.h"

void ModelLoader::LoadModel(const std::string& file)
{
    auto importer = Assimp::Importer();
    auto modelScene = importer.ReadFile(
        file, 
        aiProcess_MakeLeftHanded | 
        aiProcess_FlipWindingOrder | 
        aiProcess_FlipUVs | 
        aiProcess_PreTransformVertices |
        aiProcess_CalcTangentSpace |
        aiProcess_GenSmoothNormals |
        aiProcess_Triangulate |
        aiProcess_FixInfacingNormals |
        aiProcess_FindInvalidData |
        aiProcess_ValidateDataStructure | 0

    );
    for (int i = 0; i < modelScene->mNumMeshes; i++)
    {
        auto mesh = modelScene->mMeshes[i];
    }
}