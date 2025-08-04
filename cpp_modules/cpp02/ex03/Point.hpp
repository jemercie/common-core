/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:26:40 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 12:09:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

class Point
{
	public:

		Point();
		Point(float const x, float const y);
		Point(Point const & src);
		~Point();

		Point	& operator=(Point const& rhs);

		float	get_x_y(bool xy) const;

	private:
		float	_x;
		float	_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
