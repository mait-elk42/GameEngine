/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:17:19 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/15 12:25:20 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/Vector3.hpp>

Vector3::Vector3()
{

}
Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
	
}