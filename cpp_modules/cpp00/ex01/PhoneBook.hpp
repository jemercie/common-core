/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:47:03 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/12 10:27:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include  "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void		ADD(void);
		void		SEARCH(void);
		void		EXIT(void);

	private:
		int			index;
		int			nb;
		Contact		contact[8];

		void		display_contact(void);
};

#endif
