/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:48:33 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 09:49:31 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/GameObject.hpp>

GameObject::GameObject()
{
	
}

GameObject::GameObject(Transform transform)
{
	this->transform = transform;
}

GameObject::~GameObject()
{
	
}