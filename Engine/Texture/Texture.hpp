#ifndef D1454A8E_6768_48B1_86AC_CB9FD7A6B7B5
#define D1454A8E_6768_48B1_86AC_CB9FD7A6B7B5

#include "../../stb_image.h"
#include "../Utils/OpenGLInclude.hpp"
#include <string>
#include <iostream>

class Texture
{
private:
    uint8_t *data{nullptr};
public:
    int width{0}, height{0}, channels{0};
    uint32_t gl_bitmap_index;

public:
    Texture(const std::string& path_to);
};


#endif /* D1454A8E_6768_48B1_86AC_CB9FD7A6B7B5 */
