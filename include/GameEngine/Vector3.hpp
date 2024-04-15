/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:17:19 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/15 12:25:33 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vector3 {
public:
	double x;
	double y;
	double z;
	Vector3();
	Vector3(double x, double y, double z);
	~Vector3();
};

#endif