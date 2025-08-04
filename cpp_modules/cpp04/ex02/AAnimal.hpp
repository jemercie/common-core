/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:09:35 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/12 10:35:23 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const & src);
		virtual ~AAnimal();

		virtual void		makeSound() const = 0;
		virtual std::string getType() const = 0;

		virtual AAnimal		&operator=(const AAnimal &rhs);

	protected:
		std::string type;

};


#endif
