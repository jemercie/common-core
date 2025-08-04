/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:30:02 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:47 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T>
bool	easyfind(T param, int nb)
{
	if (find(param.begin(), param.end(), nb) != param.end())
		return (0);
	std::cout << "number " << nb << " not found." << std::endl;
	return (1);
}

#endif
