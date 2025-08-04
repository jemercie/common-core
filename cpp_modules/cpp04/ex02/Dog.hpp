/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:09:35 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:51:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();

		void		makeSound() const;
		std::string getType() const;

		Dog			&operator=(Dog const &rhs);

		void			setIdea(std::string idea);	
		std::string		getIdea(int i) const;

	protected:
		std::string type;

	private:
		Brain *brainnn;

};


#endif
