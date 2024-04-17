/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:16:29 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 13:07:47 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/Transform.hpp>

Transform::Transform()
{
	this->position = { 0.0f, 0.0f, 0.0f };
	this->rotation = { 0.0f, 0.0f, 0.0f };
	this->scale = { 1.0f, 1.0f, 1.0f };
	this->pivot = { 0.0f, 0.0f, 0.0f };
}

Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale, Vector3 pivot)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	this->pivot = pivot;
}

Transform::~Transform()
{
	
}
