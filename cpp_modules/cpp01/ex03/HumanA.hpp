/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:10:30 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/19 16:11:42 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &newWeapon);
		~HumanA();

		std::string const &getName() const;
		void		attack();

	private:
		Weapon 		&weapon;
		std::string	_name;
};

#endif
