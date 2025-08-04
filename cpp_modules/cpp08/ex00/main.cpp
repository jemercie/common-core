/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:29:14 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/22 17:58:02 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main (void)
{
	std::vector<int>	vec;

	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(11);
	vec.push_back(13);
	vec.push_back(17);

	easyfind(vec, 3);
	easyfind(vec, 4);
	easyfind(vec, 17);
	easyfind(vec, 354654);

	return (0);
}
