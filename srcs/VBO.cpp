/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VBO.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:15:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/12 08:15:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/VBO.hpp>

VBO::VBO()
{

}

VBO::~VBO()
{

}

VBO	&VBO::Generate(int n)
{
	glGenBuffers(n, &this->ID);
	return (*this);
}

VBO	&VBO::Bind(GLenum target)
{
	glBindBuffer(target, this->ID);
	return (*this);
}

VBO	&VBO::InitBuffer(GLenum target, GLsizeiptr size, void * data, GLenum usage)
{
	glBufferData(target, size, data, usage);
	return (*this);
}

VBO	&VBO::SendData(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void *pointer)
{
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
	return (*this);
}

