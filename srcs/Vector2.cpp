/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:17:19 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 16:07:33 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/Vector2.hpp>

Vector2::Vector2()
{

}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::operator +=(Vector2 v)
{
	this->x += v.x;
	this->y += v.y;
}

Vector2::~Vector2()
{

}
