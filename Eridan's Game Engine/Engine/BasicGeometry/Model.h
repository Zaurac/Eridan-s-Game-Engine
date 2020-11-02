#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <vector>
#include "Engine/Renderer/OpenGL/Entity.h"

class Model : public Entity
{
public:
	Model(const char *path)
	{
		loadModel(path);
	};
	virtual ~Model();

private:
	void loadModel(std::string const &patch);
	void processModel(aiNode* node, const aiScene* scene);
	void attachModel(aiMesh *mesh);
};