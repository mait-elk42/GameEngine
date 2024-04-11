/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAO.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:26:02 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/11 13:26:02 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GPUMEMORY_HPP
#define GPUMEMORY_HPP

#include <iostream>
#include <string>

#define LOG(v) std::cout << v << std::endl;

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class GPUMemory {
private:
public:
	GLuint	VBO_ID;
	GLuint	VAO_ID;
	GPUMemory();
	~GPUMemory();
	GPUMemory	&GenVAO();
	GPUMemory	&GenVBO();
	GPUMemory	&BindVAO();
	GPUMemory	&BindVBO();
	void		SetData(GLsizeiptr size, void * data, GLenum usage);
	void		SetAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void * pointer);
};

#endif