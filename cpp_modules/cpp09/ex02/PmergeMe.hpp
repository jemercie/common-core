/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:29:57 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/04 11:45:43 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <regex.h>
# include <sys/types.h>
# include <string>
# include <cstdlib>
# include <sys/time.h>
# include <cstring>
# include <algorithm>

class	PmergeMe
{
	public:
		/*		PmergeMe.cpp					*/

		PmergeMe(int argc, char **argv);
		class WrongInputException : public std::exception{
			const char* what() const throw();
		};
		~PmergeMe();

	private:

		/*		PmergeMe.cpp						*/
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &rhs);
		bool	_ParseInputAndFillContainers(char **argv);

		/*		SortVector.cpp						*/
		void    _SortVector();
		void	_SortRecursivelyFirstVectorHalf(int args);
		void    _SortWBinarySearchInsertionSecondVectorHalf();
		void    _BinarySearchInsertionVec(int nb, int start, int end);

		/*		SortDeque.cpp						*/
		void    _SortDeque();
		void    _SortRecursivelyFirstDequeHalf(int args);
		void    _SortWBinarySearchInsertionSecondDequeHalf();
		void    _BinarySearchInsertionDeq(int nb, int start, int end);

		std::string							getInput() const;
		int									getOdd() const;
		std::vector<int>					getSortedNb() const; // faire les getters en template urf
		std::vector<std::pair<int, int> >	getStoredNb() const;

		std::vector<std::pair<int, int> >	_vecPairedNbrs;
		std::vector<int>					_vecSortedNbrs;
		std::deque<std::pair<int, int> >	_deqPairedNbrs;
		std::deque<int>						_deqSortedNbrs;

		std::vector<int>					_jacobsthal;
		int									_odd;
		int									_argc;

};


#endif
