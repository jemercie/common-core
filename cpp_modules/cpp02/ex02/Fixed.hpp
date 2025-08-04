/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:54:28 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/26 11:47:10 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed
{
	public:

		Fixed();
		Fixed(Fixed const & src);
		Fixed(const float nb);
		Fixed(int nb);
		~Fixed();

		Fixed & operator=(Fixed const& rhs);

		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		float		operator+(Fixed const & rhs) const;
		float		operator-(Fixed const & rhs) const;
		float		operator*(Fixed const & rhs) const;
		float		operator/(Fixed const & rhs) const;

		Fixed &	operator--(int);
		Fixed &	operator--();
		Fixed &	operator++(int);
		Fixed &	operator++();

		static Fixed		& min(Fixed &nb1, Fixed &nb2);
		static const Fixed	& min(const Fixed &nb1, const Fixed &nb2);

		static Fixed		& max(Fixed &nb1, Fixed &nb2);
		static const Fixed & max(const Fixed &nb1, const Fixed &nb2);

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
