/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:50:03 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 16:43:21 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Ice.hpp"
# include "Cure.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(ICharacter const & src);
		~Character();

		Character & operator=(ICharacter const & src);
		std::string const & getName() const;

		AMateria	*getPtr4Unequip(int idx);

		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);

	private:
		std::string	_name;
		AMateria 	*materia[4];

};


#endif
