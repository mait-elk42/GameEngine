/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:13:24 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 13:07:40 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <GameEngine/Vector3.hpp>

class Transform{
private:
public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	Vector3 pivot;
	Transform();
	Transform(Vector3 position, Vector3 rotation, Vector3 scale, Vector3 pivot);
	~Transform();
};

#endif