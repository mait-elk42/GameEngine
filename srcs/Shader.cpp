/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:47:14 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/11 07:47:14 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/Shader.hpp>

ShaderProgram::ShaderProgram()
{
	
}

ShaderProgram::~ShaderProgram()
{
	
}

ShaderProgram &ShaderProgram::Create()
{
	this->program = glCreateProgram();
	LOG("\033[32m""SHADER PROGRAM CREATED""\033[0m");
	return (*this);
}

ShaderProgram &ShaderProgram::AttachShaderFromFile(GLuint ShaderType, std::string filename)
{
	std::fstream file(filename);
	std::string tmp;
	std::string filecontent;

	if (!file.is_open())
	{
		LOG ("Cannot Open ShaderFile : " << filename);
		return (*this);
	}
	while (std::getline(file, tmp))
	{
		filecontent.append(tmp);
		filecontent.append("\n");
	}
	LOG("Compiling Shader File : " << filename);
	AttachShader(ShaderType, filecontent);
	return (*this);
}

ShaderProgram &ShaderProgram::AttachShader(GLuint ShaderType, std::string source_code)
{
	GLuint shader = glCreateShader(ShaderType);
	char	*src = (char *)source_code.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		LOG ("\033[31mShader Compilation Failed\n[ \n" << infoLog << "]\033[0m");
		return (*this);
	}
    glAttachShader(this->program, shader);
    glLinkProgram(this->program);
    glDeleteShader(shader);
	LOG ("\033[32m""Shader Compilation Successed""\033[0m");
	return (*this);
}

void ShaderProgram::Use()
{
	glUseProgram(this->program);
}

ShaderProgram::operator GLuint()
{
	return (this->program);
}