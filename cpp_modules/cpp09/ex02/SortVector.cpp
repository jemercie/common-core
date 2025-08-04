/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:56:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/06 17:03:12 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    PmergeMe::_SortVector()
{
    struct timeval start, end;
    size_t i = 0;
    if (this->_vecPairedNbrs.empty())
        return;

    gettimeofday(&start, NULL);
    this->_SortRecursivelyFirstVectorHalf(0);
    this->_SortWBinarySearchInsertionSecondVectorHalf();
    gettimeofday(&end, NULL);

    std::cout << "After: ";
    for(; (this->_argc <= 6 && i < this->_vecSortedNbrs.size()) || (this->_argc > 6 && i < 4); i++){
        std::cout << this->_vecSortedNbrs[i] << " ";
    }
    if (this->_argc > 6)
        std::cout << "[...]";
    std::cout << std::endl << "Time to process a range of " << this->_argc - 1 << " elements with std::vector : ";
    std::cout << (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec) << " µs." << std::endl;
}

void    PmergeMe::_SortWBinarySearchInsertionSecondVectorHalf()
{
    std::vector<std::pair<int, int> >::iterator it = this->_vecPairedNbrs.begin();
    std::vector<int>::iterator it_next_end;
    std::vector<int>::iterator tmp;
    int next_end;
    int prev = 0;
    int index = 0;
    int j;

    for (; it != this->_vecPairedNbrs.end(); index++)
    {
        j = this->_jacobsthal[index];
        if (j > static_cast<int>(this->_vecPairedNbrs.size() - 1))
            j = this->_vecPairedNbrs.size() - 1;
        for(; j >= prev; it++, j--)
        {
            tmp = this->_vecSortedNbrs.begin();
            it_next_end = find(this->_vecSortedNbrs.begin(), this->_vecSortedNbrs.end(), this->_vecPairedNbrs[j].second);
            for(next_end = 0; tmp != it_next_end; tmp++, next_end++){
            }
            this->_BinarySearchInsertionVec(this->_vecPairedNbrs[j].first, 0, next_end);
        }
        prev = this->_jacobsthal[index] + 1;
    }
    if (this->_odd >= 0)
        this->_BinarySearchInsertionVec(this->_odd, 0, this->_vecSortedNbrs.size());
}

void    PmergeMe::_BinarySearchInsertionVec(int nb, int start, int end)
{
    int mid = end - start;

    if (mid > 1)
    {
        mid = mid / 2 + mid % 2;
        if (nb >= this->_vecSortedNbrs[start + mid])
            this->_BinarySearchInsertionVec(nb, start + mid, end);
        else 
            this->_BinarySearchInsertionVec(nb, start, start + mid);
    }
    else
    {
        if (nb > this->_vecSortedNbrs[start + mid])
            mid += 1;
        else if (nb < this->_vecSortedNbrs[0])
            mid = 0;
        this->_vecSortedNbrs.insert(find(this->_vecSortedNbrs.begin(), this->_vecSortedNbrs.end(), this->_vecSortedNbrs[start + mid]), nb);
    }
}

void    PmergeMe::_SortRecursivelyFirstVectorHalf(int args)
{
    std::vector<std::pair<int, int> >::iterator it = this->_vecPairedNbrs.begin();
    int i = 0;
    static int big = 2147483647;
    int index = 0;
    int nb = 0;

    for(i = 0; it != this->_vecPairedNbrs.end();it++, i++){
        if (this->_vecPairedNbrs[i].second >= nb && this->_vecPairedNbrs[i].second <= big)
        {
            nb = this->_vecPairedNbrs[i].second;
            index = i;
        }
    }
    big = nb;
    std::pair<int, int> tmp = std::make_pair(this->_vecPairedNbrs[index].first, this->_vecPairedNbrs[index].second);
    this->_vecPairedNbrs.erase(this->_vecPairedNbrs.begin() + index);
    if (args < (this->_argc-2)/2)
        this->_SortRecursivelyFirstVectorHalf(args + 1);
    this->_vecPairedNbrs.push_back(tmp);
    this->_vecSortedNbrs.push_back(tmp.second);
}
