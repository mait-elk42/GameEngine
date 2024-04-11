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

#include <GameEngine/GPUMemory.hpp>

GPUMemory::GPUMemory()
{
	
}

GPUMemory::~GPUMemory()
{
    glDeleteVertexArrays(1, &VAO_ID);
    glDeleteBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

GPUMemory &GPUMemory::GenVAO()
{
	glGenVertexArrays(1, &this->VAO_ID);
	return (*this);
}

GPUMemory &GPUMemory::GenVBO()
{
	glGenBuffers(1, &this->VBO_ID);
	return (*this);
}

GPUMemory &GPUMemory::BindVAO()
{
	glBindVertexArray(this->VAO_ID);
	return (*this);
}

GPUMemory &GPUMemory::BindVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->VAO_ID);
	return (*this);
}

void	GPUMemory::SetData(GLsizeiptr size, void * data, GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void GPUMemory::SetAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void * pointer)
{
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}