/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:17:19 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/17 16:07:22 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
	float x;
	float y;
	Vector2();
	Vector2(float x, float y);
	void operator +=(Vector2 v);
	~Vector2();
};

#endif