/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:09:35 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:40:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();

		void		makeSound() const;
		std::string getType() const;
		
		Cat			&operator=(Cat const &rhs);

		void			setIdea(std::string idea);	
		std::string		getIdea(int i) const;

	protected:
		std::string type;

	private:
		Brain *brainnn;

};

#endif
