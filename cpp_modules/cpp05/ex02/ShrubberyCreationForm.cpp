/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:42:51 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 11:43:06 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " execute " << this->getName() << std::endl;

    std::string filename = this->_target + "_shrubbery";
    std::ofstream file;
    file.open(filename.c_str());
    if (!file.is_open())
       throw Bureaucrat::FormExecutionError();
    file << "        *                    *                    *            " << std::endl;
    file << "       ***                  ***                  ***           " << std::endl;
    file << "      *****                *****                *****          " << std::endl;
    file << "     *******              *******              *******         " << std::endl;
    file << "      *****                *****                *****          " << std::endl;
    file << "     *******              *******              *******         " << std::endl;
    file << "    *********            *********            *********        " << std::endl;
    file << "   ***********          ***********          ***********       " << std::endl;
    file << "  *************        *************        *************      " << std::endl;
    file << "       ***                  ***                  ***           " << std::endl;
    file << "       ***                  ***                  ***           " << std::endl;
    file << "       ***                  ***                  ***           " << std::endl;
    file.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void) rhs;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm("Shrubbery creation form", 25, 5), _target(rhs._target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation form", 25, 5), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}