#include "Texture2DLoaderOpenGL.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Engine/Stb/stb_image.h"

Texture2DLoaderOpenGL::Texture2DLoaderOpenGL()
{
}

Texture2DLoaderOpenGL::~Texture2DLoaderOpenGL()
{
}

Texture2D Texture2DLoaderOpenGL::LoadTexture(const char* texturePath)
{
    Texture2D texture = Texture2D();
   
    glGenTextures(1, &texture.texture);
    glBindTexture(GL_TEXTURE_2D, texture.texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* data;
    data = stbi_load(texturePath, &texture.width, &texture.height, &texture.nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "ERROR::LOADING::IMAGE" << std::endl;
    }

    stbi_image_free(data);
    return texture;
}
