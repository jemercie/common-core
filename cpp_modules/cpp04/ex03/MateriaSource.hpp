/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:36 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/02 17:16:36 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{

	public:
		MateriaSource();
		MateriaSource(MateriaSource const & rhsss);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource const &srccc);

		void		learnMateria(AMateria* yy);
		AMateria*	createMateria(std::string const & type);

	protected:
		AMateria	*materia_learned[4];

};

#endif
