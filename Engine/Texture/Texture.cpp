#include "Texture.hpp"

Texture::Texture(const std::string &path_to)
{
    data = stbi_load(path_to.c_str(), &width, &height, &channels, 0);
    std::cout << height << "\n";
    if(!data)
    {
        std::cout << "Failed to load image!\n";
        return;
    }
    glGenTextures(1, &gl_bitmap_index);
    glBindTexture(GL_TEXTURE_2D, gl_bitmap_index);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    data = nullptr;
}