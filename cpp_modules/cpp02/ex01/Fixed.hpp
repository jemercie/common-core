/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:54:28 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 11:36:55 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:

		Fixed();
		Fixed(Fixed const & src);
		Fixed(const float nb);
		Fixed(const int nb);
		~Fixed();

		Fixed & operator=(Fixed const& rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int	_nb;
		static const int _fracBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
