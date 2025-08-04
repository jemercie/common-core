/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:28:31 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/28 17:32:51 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "AAnimal.hpp"

class Brain
{
	public:
		Brain();
		Brain(Brain const & src);
		~Brain();

		std::string	getIdea(int i) const;
		void		setIdea(std::string idea);

		Brain		&operator=(Brain const &rhs);
		
	protected:
		int				index;
		std::string		ideas[100];


};

#endif
