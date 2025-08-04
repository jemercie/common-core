/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:13 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/24 17:02:53 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename MutantStack::container_type::iterator iterator;
        typedef typename MutantStack::container_type::const_iterator const_iterator;

        iterator begin() { return (this->c.begin()); };
        iterator end() { return (this->c.end()); };

        const_iterator begin() const { return (this->c.begin()); };
        const_iterator end() const { return (this->c.end()); };

    private:

};

#endif
