/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:17:19 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 16:07:11 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/Vector3.hpp>

Vector3::Vector3()
{

}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::operator +=(Vector3 v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

Vector3::~Vector3()
{

}
