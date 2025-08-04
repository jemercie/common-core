/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:45:33 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 11:46:24 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &rhs);
        ~PresidentialPardonForm();

        void    execute(Bureaucrat const & executor) const;

    private :
        const std::string   _target;
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

};



#endif
