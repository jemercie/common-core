/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:44:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 11:49:00 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const & executor) const;

    private :
        const std::string   _target;
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

};

#endif
