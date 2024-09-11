/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:30:13 by eandre            #+#    #+#             */
/*   Updated: 2024/09/11 14:02:00 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float y_, const float x_);
		Point(const Point &other_point);
		Point	&operator=(const Point &other_Point);
		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
		~Point();
	private:
		Fixed const y;
		Fixed const x;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif