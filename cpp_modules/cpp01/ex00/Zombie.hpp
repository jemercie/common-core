/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:43:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/18 15:43:18 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

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

void	randomChump(std::string);
Zombie	*newZombie(std::string name);

#endif
