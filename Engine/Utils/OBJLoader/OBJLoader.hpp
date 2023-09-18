#ifndef C34DE1C7_92A8_4F60_8B9C_3D94D37750BF
#define C34DE1C7_92A8_4F60_8B9C_3D94D37750BF

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../../../glm/glm.hpp"

class OBJLoader
{
public:
    static bool FromFile(const std::string& path_to_file, std::vector<float> *out_vbo_data, size_t *out_indicies);
public:
    OBJLoader(){};
    ~OBJLoader(){};
};


#endif /* C34DE1C7_92A8_4F60_8B9C_3D94D37750BF */
