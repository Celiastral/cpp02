/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:30:08 by eandre            #+#    #+#             */
/*   Updated: 2024/09/15 18:49:00 by eandre           ###   ########.fr       */
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

bool isPointOnTriangleSide(Point p1, Point p2, Point p3, Point p)
{
	if ((p.get_x() == p1.get_x() && p.get_y() == p1.get_y())
	|| (p.get_x() == p2.get_x() && p.get_y() == p2.get_y()) 
	|| (p.get_x() == p3.get_x() && p.get_y() == p3.get_y()))
        return true;

    Fixed	cp1 = crossProduct(Point(Fixed(p1.get_y() - p.get_y()).toFloat(), Fixed(p1.get_x() - p.get_x()).toFloat())
	, Point(Fixed(p2.get_y() - p.get_y()).toFloat(), Fixed(p2.get_x() - p.get_x()).toFloat()));
    Fixed	cp2 = crossProduct(Point(Fixed(p2.get_y() - p.get_y()).toFloat(), Fixed(p2.get_x() - p.get_x()).toFloat())
	, Point(Fixed(p3.get_y() - p.get_y()).toFloat(), Fixed(p3.get_x() - p.get_x()).toFloat()));
    Fixed	cp3 = crossProduct(Point(Fixed(p3.get_y() - p.get_y()).toFloat(), Fixed(p3.get_x() - p.get_x()).toFloat())
	, Point(Fixed(p1.get_y() - p.get_y()).toFloat(), Fixed(p1.get_x() - p.get_x()).toFloat()));

    return (cp1 == 0 && cp2 == 0 && cp3 == 0);
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
	return (combined_area == area_main_triangle && !isPointOnTriangleSide(a, b, c, point));
}