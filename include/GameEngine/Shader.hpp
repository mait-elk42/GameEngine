/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:42:08 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/11 07:42:08 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <string>

#define LOG(v) std::cout << v << std::endl;

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class ShaderProgram {
private:
	GLuint program;
public:
	ShaderProgram();
	~ShaderProgram();
	void	AttachShader(GLuint ShaderType, std::string source_code);
	void Use();
};

#endif