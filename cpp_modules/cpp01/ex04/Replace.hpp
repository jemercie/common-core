/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:25:46 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/19 16:36:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

class Replace
{
	public:
		Replace(char *filename_in, char *s1,char *s2);
		~Replace();

		void	replace();
		void	search_and_modify(std::string &str);
		int		openFiles();
		void	closeFiles();

	private:
		std::ifstream	_infile;
		std::ofstream	_outfile;
		char			*_filename;
		std::string		_s1;
		std::string		_s2;
};

#endif
