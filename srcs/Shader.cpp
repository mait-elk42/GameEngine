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
	this->program = glCreateProgram();
	LOG("SHADER PROGRAM CREATED");
}

ShaderProgram::~ShaderProgram()
{
	
}

void ShaderProgram::AttachShader(GLuint ShaderType, std::string source_code)
{
	GLuint shader = glCreateShader(ShaderType);
	char	*src = (char *)source_code.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    glAttachShader(this->program, shader);
    glLinkProgram(this->program);
    glDeleteShader(shader);
}

void ShaderProgram::Use()
{
	glUseProgram(this->program);
}