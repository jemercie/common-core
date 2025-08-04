/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/18 16:07:45 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:		
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void		announce(void);
		void		setName(std::string newName);
		std::string	getName(void) const;


	private:
		std::string _name;

};

	/* FUNCTIONS */

Zombie *zombieHorde(int N, std::string name);

#endif
