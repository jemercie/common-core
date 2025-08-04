/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:08:55 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 12:11:04 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

static float get_area(Point const a, Point const b, Point const c);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   abc_area = get_area(a, b, c); 
    float   abp_area = get_area(a, b, point);
    float   pbc_area = get_area(point, b, c); 
    float   apc_area = get_area(a, point, c); 
 
    return (abc_area == (abp_area + pbc_area + apc_area));
}


static float get_area(Point const a, Point const b, Point const c)
{
	float area;
	float x1 = a.get_x_y(1);
	float y1 = a.get_x_y(0); 
	float x2 = b.get_x_y(1);
	float y2 = b.get_x_y(0);
	float x3 = c.get_x_y(1);
	float y3 = c.get_x_y(0);

	area = ((x1 *(y2 - y3)) + x2*(y3 - y1) + x3*(y1 - y2)) / 2;
	if (area < 0)
		area *= -1;
	return (area);
}
