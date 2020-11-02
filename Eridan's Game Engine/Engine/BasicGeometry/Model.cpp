#include "Model.h"

Model::~Model()
{
}

void Model::loadModel(std::string const& patch)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(patch, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if (!scene)
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}

	const aiScene* pScene = scene;

	for (unsigned int i = 0; i < pScene->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[i];
		
		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			
			Vertex vertex;
			vertex.Position.x = mesh->mVertices[i].x;
			vertex.Position.y = mesh->mVertices[i].y;
			vertex.Position.z = mesh->mVertices[i].z;

			if (mesh->HasNormals())
			{
				vertex.Normal.x = mesh->mNormals[i].x;
				vertex.Normal.y = mesh->mNormals[i].y;
				vertex.Normal.z = mesh->mNormals[i].z;
			}
			else
			{
				vertex.Normal = glm::vec3(0.0f, 0.0f, 0.0f);
			}
			vertex.TexCoords = glm::vec2(0.f, 0.f);

			vertices.push_back(vertex);
		}

		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace face = mesh->mFaces[i];

			for (unsigned int j = 0; j < face.mNumIndices; j++)
			{
				indices.push_back(face.mIndices[j]);
			}
		}
		

	}

	CreateEntity();
}

void Model::processModel(aiNode* node, const aiScene* scene)
{
	
}

void Model::attachModel(aiMesh* mesh)
{
	
}


