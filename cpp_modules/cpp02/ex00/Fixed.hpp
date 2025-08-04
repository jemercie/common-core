/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:54:28 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/22 11:15:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const& rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int	nb;
		static const int static_const_nb = 8;
};

#endif
