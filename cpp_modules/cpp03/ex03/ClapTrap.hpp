/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:47:23 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:16:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# define HEALTH 1
# define ENERGY 2
# define AD 3
# define NO_TARGET 4
# define IS_DEAD 5
# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define WHITE "\033[0m"

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();
		
		void			attack(const std::string & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		void			setAD(unsigned int amount);
		void			setNewName(std::string name);
		std::string		getName() const;
		unsigned int	getStats(int i) const;

		ClapTrap &operator=(ClapTrap const &src);

	protected:

		std::string		_name;
		int	_health;
		int	_energy;
		int	_ad;

		void			error(int ERR, std::string str);
};


#endif
