/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_and_identify.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:19 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/16 14:47:19 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_AND_IDENTIFY_HPP
# define GENERATE_AND_IDENTIFY_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Base.hpp"
# include <cstdlib>
# include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif