/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAO.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:15:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/12 08:15:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/VAO.hpp>

VAO::VAO()
{

}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &this->ID);
}

VAO	&VAO::Generate(int n)
{
	glGenVertexArrays(n, &this->ID);
	return (*this);
}

VAO	&VAO::Bind()
{
	glBindVertexArray(this->ID);
	return (*this);
}
