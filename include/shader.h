#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader{
    private:
        unsigned int m_Program{0};

        std::string openFile(std::string path);
    public:
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
        ~Shader();

        unsigned int getLocation(std::string varName);

        void setVec2(unsigned int varLocation, float v1, float v2);
        void use();
};

#endif // SHADER_H
