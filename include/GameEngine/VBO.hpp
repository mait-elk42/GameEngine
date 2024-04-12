/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VBO.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:12:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/12 08:12:44 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VBO_H
#define VBO_H

#include <iostream>
#include <string>

#define LOG(v) std::cout << v << std::endl;

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class VBO {
private:
	GLuint	ID;
public:
	VBO();
	~VBO();
	VBO	&Generate(int n);
	VBO	&Bind(GLenum target);
	VBO	&InitBuffer(GLenum target, GLsizeiptr size, void * data, GLenum usage);
	VBO	&SendData(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void *pointer);
};

#endif