
#include "shader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>

std::string Shader::openFile(std::string path){
    std::ifstream file(path);
    if(!file.is_open()){
        std::cout << "File does not exists: " << path << std::endl;
        return std::string();
    }
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath){
    m_Program = glCreateProgram();

    unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
    {
        std::string vertexSourceCode = openFile(vertexShaderPath);
        const char* sourceCode = &vertexSourceCode[0];
        glShaderSource(VertexShader, 1, &sourceCode, 0);
        glCompileShader(VertexShader);
    }
    
    unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    {
        std::string fragmentSourceCode = openFile(fragmentShaderPath);
        const char* sourceCode = &fragmentSourceCode[0];
        glShaderSource(FragmentShader, 1, &sourceCode, 0);
        glCompileShader(FragmentShader);
    }
    glAttachShader(m_Program, VertexShader);
    glAttachShader(m_Program, FragmentShader);

    glLinkProgram(m_Program);

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}

Shader::~Shader(){
    glDeleteProgram(m_Program);
}

void Shader::use(){
    glUseProgram(m_Program);
}

unsigned int Shader::getLocation(std::string varName){
  return glGetUniformLocation(m_Program, varName.c_str());
}

void Shader::setVec2(unsigned int varLocation, float v1, float v2){
    glUniform2f(varLocation, v1, v2);
}
