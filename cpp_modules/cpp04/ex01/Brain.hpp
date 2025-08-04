/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:28:31 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:40:44 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(Brain const & src);
		~Brain();

		std::string	getIdea(int i) const;
		void		setIdea(std::string idea);
		int				index;

		Brain		&operator=(Brain const &rhs);

	protected:
		std::string		ideas[100];


};

#endif
