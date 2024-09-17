/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:30:08 by eandre            #+#    #+#             */
/*   Updated: 2024/09/17 13:46:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//(1/2) * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))

#include "../include/Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area;
	area = a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y());
	if (area < 0)
		return (area * Fixed(-1.0f) * Fixed(0.5f));
	return (area * Fixed(0.5f));
}

Fixed crossProduct(Point a, Point b)
{
    return (a.get_x() * b.get_y() - a.get_y() * b.get_x());
}

bool is_point_on_triangle_side(Point a, Point b, Point c, Point point)
{
	if ((point.get_x() == a.get_x() && point.get_y() == a.get_y())
	|| (point.get_x() == b.get_x() && point.get_y() == b.get_y()) 
	|| (point.get_x() == c.get_x() && point.get_y() == c.get_y()))
        return true;

    Fixed	cross_a = crossProduct(Point(Fixed(a.get_y() - point.get_y()).toFloat(), Fixed(a.get_x() - point.get_x()).toFloat())
	, Point(Fixed(b.get_y() - point.get_y()).toFloat(), Fixed(b.get_x() - point.get_x()).toFloat()));
    Fixed	cross_b = crossProduct(Point(Fixed(b.get_y() - point.get_y()).toFloat(), Fixed(b.get_x() - point.get_x()).toFloat())
	, Point(Fixed(c.get_y() - point.get_y()).toFloat(), Fixed(c.get_x() - point.get_x()).toFloat()));
    Fixed	cross_c = crossProduct(Point(Fixed(c.get_y() - point.get_y()).toFloat(), Fixed(c.get_x() - point.get_x()).toFloat())
	, Point(Fixed(a.get_y() - point.get_y()).toFloat(), Fixed(a.get_x() - point.get_x()).toFloat()));

    return (cross_a == 0 && cross_b == 0 && cross_c == 0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_main_triangle;
	Fixed	area_first_triangle;
	Fixed	area_second_triangle;
	Fixed	area_third_triangle;
	Fixed	combined_area;

	area_main_triangle =  area(a, b, c);
	area_first_triangle = area(point, b, c);
	area_second_triangle = area(a, point, c);
	area_third_triangle = area(a, b, point);
	combined_area = area_first_triangle + area_second_triangle + area_third_triangle;
	return (combined_area == area_main_triangle && !is_point_on_triangle_side(a, b, c, point));
}