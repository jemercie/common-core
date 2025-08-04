/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:32 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:48:15 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap();

		std::string	getDiamondName() const;
		void		whoAmI();

		using ScavTrap::attack;		

	DiamondTrap &operator=(DiamondTrap const &src);

	protected:

		using FragTrap::_health;
		using ScavTrap::_energy;
		using FragTrap::_ad;

	private:
		std::string _d_name;


};

#endif
