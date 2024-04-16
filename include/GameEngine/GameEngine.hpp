/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:04:35 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/10 12:04:35 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP


template<typename T>
class Vector3 {
private:
	T x;
	T y;
	T z;
public:
	Vector3();
	~Vector3();
};

void f()
{
	Vector3<float> v;
}

#include <iostream>
#include <string>
#include <GameEngine/GameContext.hpp>
#include <GameEngine/Shader.hpp>
#include <GameEngine/VAO.hpp>
#include <GameEngine/VBO.hpp>
#include <GameEngine/Vector3.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#endif