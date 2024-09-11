/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:30:06 by eandre            #+#    #+#             */
/*   Updated: 2024/09/11 14:10:13 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : y(Fixed()), x(Fixed())
{}

Point::Point(const float y_, const float x_) : y(Fixed(y_)), x(Fixed(x_))
{}

Point::~Point()
{}

Point &Point::operator=(const Point &other_Point)
{
	this->~Point();
	new (this) Point(other_Point.x.toFloat(), other_Point.y.toFloat());
	return (*this);
}

Point::Point(const Point &other_point)
{
	*this = other_point;
}

Fixed	Point::get_x(void) const
{
	return (this->x);
}

Fixed	Point::get_y(void) const
{
	return (this->y);
}