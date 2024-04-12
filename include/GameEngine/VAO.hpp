/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAO.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:12:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/12 08:12:44 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAO_H
#define VAO_H


#include <iostream>
#include <string>

#define LOG(v) std::cout << v << std::endl;

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class VAO {
private:
	GLuint	ID;
public:
	VAO();
	~VAO();
	VAO	&Generate(int n);
	VAO	&Bind();
};

#endif