/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:33:58 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/12 10:11:49 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string.h>
# include <iomanip>
# include <cstdlib>
# include <regex.h>
# include <sstream>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string getFirstName(void) const;
	 	std::string getLasttName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
		void    	setFirstName(std::string buf);
		void	    setLastName(std::string buf);
		void	    setNickname(std::string buf);
		void	    setPhoneNumber(std::string buf);
		void    	setDarkestSecret(std::string buf);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
