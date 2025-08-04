/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:43:47 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 11:48:35 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
    public :
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm();

        void    execute(Bureaucrat const & executor) const;

    private :
        const std::string   _target;
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

};


#endif
