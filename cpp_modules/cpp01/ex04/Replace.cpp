/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:25:18 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/19 16:36:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void	Replace::replace() 
{
	std::string	str;	

	if (this->openFiles() < 0)
		return ;
	while (1)
 	{
		std::getline(this->_infile, str);
		search_and_modify(str);
		if (!this->_infile.eof())
			this->_outfile.write("\n", 1);
		else
			break;
	}
	this->closeFiles();
}

void	Replace::search_and_modify(std::string &str)
{
	std::size_t	found = 0;

	found = str.find(_s1);
	if (this->_s1.empty() || found==std::string::npos)
	{
		this->_outfile.write(str.c_str(), str.length());
		return;
	}
	while(found!=std::string::npos)
	{
		this->_outfile.write(str.c_str(),found);
		if (!this->_s2.empty())
			_outfile.write(this->_s2.c_str(),this->_s2.length());
		str.erase(0, (found + this->_s1.length()));
		found = str.find(_s1);
	}
	if (!str.empty())
		this->_outfile.write(str.c_str(), str.length());
	return;
}

int	Replace::openFiles()
{
    this->_infile.open(this->_filename);
    if (!this->_infile.is_open())
	{
    	std::cout << "A problem occured while opening the infile." << std::endl;
	    return (-1);
	}
	std::string outfile = this->_filename + (std::string)".replace";
    this->_outfile.open(outfile.c_str());
    if (!this->_outfile.is_open())
	{
    	std::cout << "A problem occured while opening the outfile." << std::endl;
	    return (-1);
	}
	return (0);
}

void	Replace::closeFiles()
{
	this->_infile.close();
}

Replace::Replace(char *filename, char *s1,char *s2)
{
	this->_filename = filename;
	this->_s1 = s1;
	this->_s2 = s2;
}

Replace::~Replace()
{
}
