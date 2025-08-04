/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:17:45 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/21 12:59:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void	search_and_replace(std::string str, std::string s1, std::string s2);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "error, wrong params" << std::endl;
		return (0);
	}

	Replace	file(argv[1], argv[2], argv[3]);
	file.replace();
	return (0);
}


