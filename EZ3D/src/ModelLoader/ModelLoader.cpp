#include "ModelLoader.h"

Mesh* ModelLoader::LoadModel(const std::string& file)
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
        aiProcess_ValidateDataStructure
    );
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec3> tangents;
    std::vector<glm::vec3> bitTangents;
    std::vector<glm::vec2> textureCoords;
    std::vector<unsigned int> indices;
    auto mesh = modelScene->mMeshes[0];
    for (int i = 0; i < mesh->mNumVertices; i++)
    {
        auto vertex = mesh->mVertices[i];
        auto textureCoord = mesh->mTextureCoords[0][i];
        auto normal = mesh->mNormals[i];
        auto bitTangent = mesh->mBitangents[i];
        auto tangent = mesh->mTangents[i];

        vertices.push_back(glm::vec3(vertex.x, vertex.y, vertex.z));
        textureCoords.push_back(glm::vec2(textureCoord.x, textureCoord.y));
        normals.push_back(glm::vec3(normal.x, normal.y, normal.z));
        tangents.push_back(glm::vec3(tangent.x, tangent.y, tangent.z));
        bitTangents.push_back(glm::vec3(bitTangent.x, bitTangent.y, bitTangent.z));
    }

    for (int i = 0; i < mesh->mNumFaces; i++)
    {
        auto face = mesh->mFaces[i];
        for (int y = 0; y < face.mNumIndices; y++)
        {
            indices.push_back(face.mIndices[y]);
        }
    }

    auto meshRez = new Mesh();
    meshRez->AddBuffer(0, vertices);
    meshRez->AddBuffer(1, textureCoords);
    meshRez->AddBuffer(2, normals);
    meshRez->AddBuffer(3, tangents);
    meshRez->AddBuffer(4, bitTangents);
    meshRez->AddIndexBuffer(indices);
    return meshRez;
}