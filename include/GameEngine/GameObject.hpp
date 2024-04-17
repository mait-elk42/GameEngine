/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:12:39 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 09:49:09 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <GameEngine/Transform.hpp>

class GameObject {
private:
public:
	Transform transform;
	GameObject();
	GameObject(Transform transform);
	~GameObject();
};

#endif