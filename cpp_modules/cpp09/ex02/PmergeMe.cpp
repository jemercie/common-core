/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:40:12 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/04 11:45:38 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int GetNextNb(char *str);
static void printBefore(char **argv);
static int getNextJacobsthalNb();

PmergeMe::PmergeMe(int argc, char **argv): _odd(-1), _argc(argc)
{
	if (argc <= 2 || !this->_ParseInputAndFillContainers(argv))
		throw WrongInputException();
    this->_jacobsthal.push_back(0);
    for(int i = 0; i < 31; i++){
        this->_jacobsthal.push_back(getNextJacobsthalNb());
    }
    this->_SortVector();
    this->_SortDeque();
}

bool	PmergeMe::_ParseInputAndFillContainers(char **argv)
{

    int i = 1;
    int nb1 = 0;
    int nb2 = 0;

    std::pair<int, int> pair1;
    std::pair<int, int> pair2;
    for (; (i < this->_argc) && (i+1 < this->_argc);)
    {
        nb1 = GetNextNb(argv[i]);
        nb2 = GetNextNb(argv[i + 1]);
        i+=2;
        if (nb1 > -1 && nb2 > -1)
        {
            if (nb1 < nb2)
            {
                pair1 = std::make_pair(nb1, nb2);
                pair2 = std::make_pair(nb1, nb2);
            }
            else
            {
                pair1 = std::make_pair(nb2, nb1);
                pair2 = std::make_pair(nb2, nb1);
            }
            this->_vecPairedNbrs.push_back(pair1);
            this->_deqPairedNbrs.push_back(pair2);
        }
        else
            return (0);
    }
    if (argv[i])
    {
        nb1 = GetNextNb(argv[i]);
        if (nb1 > 0)
        {
            this->_odd = nb1;
            this->_argc-=1;
        }
        else
            return (0);
    }
    printBefore(argv);
    return (1);
}

static int GetNextNb(char *str)
{
    long int check = 0;

        check = std::atol(str);
        if (check < 0 || check > 2147483647)
            return (-1);
    return (static_cast<int>(check));
}

static void printBefore(char **argv)
{
    int i;

    std::cout << "Before: ";
    for(i = 1; argv[i] && i < 5; i++){
        std::cout << argv[i] << " ";
    }
    if (argv[i] && !argv[i + 1])
        std::cout << argv[i];
    else if (argv[i])
        std::cout << "[...]";
    std::cout << std::endl;
}

static int getNextJacobsthalNb()
{
    static int prevprev = 0;
    static int prev = 1;
    static int nb = 0;

    nb = prev + prevprev * 2;
    prevprev = prev;
    prev = nb;
    return (nb);
}

const char *PmergeMe::WrongInputException::what() const  throw()
{
	return ("Wrong input, it must contain only positive integers.\n");
}

PmergeMe::~PmergeMe()
{
}

