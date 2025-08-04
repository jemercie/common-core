/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:47:43 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/20 17:51:22 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <cstdlib>

template<typename T>
class Array
{
    public:

        Array<T>(unsigned int size) : _tab(NULL), _size(size)
        {
            if (size > 0)
                this->_tab = new T[size]; 
        }

        Array<T>() : _tab(NULL), _size(0){
        }

        Array<T> &operator=(Array <T> const & rhs)
        {
            this->_size = rhs._size;
            if (this->_tab != NULL)
                delete [] this->_tab;
            if (rhs._tab != NULL)
            {
                this->_tab = new T[this->_size];
                for (unsigned int i = 0; i < rhs._size; i++){
                    this->_tab[i] = rhs._tab[i];
                }
            }
            return (*this);
        }

        Array<T>(Array<T> const & src)
        {
            this->_tab = NULL;
            *this = src;
        }

        ~Array<T>(){
            delete [] this->_tab;
        };

        T &operator[](unsigned int index)
        {
            if (index >= this->_size)
                throw WrongIndexException();
            return (this->_tab[index]);
        }

        unsigned int size() const{
            return (this->_size);
        }

        class WrongIndexException : public std::exception{
            const char* what() const throw(){
                return ("Wrong index.");
            }
        };


    private:
        T *_tab;
        unsigned int _size;

};

#endif
