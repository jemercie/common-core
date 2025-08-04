/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:03:16 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/06 17:03:18 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    PmergeMe::_SortDeque()
{
    struct timeval start, end;
    if (this->_vecPairedNbrs.empty())
        return;

    gettimeofday(&start, NULL);
    this->_SortRecursivelyFirstDequeHalf(0);
    this->_SortWBinarySearchInsertionSecondDequeHalf();
    gettimeofday(&end, NULL);

    std::cout << "Time to process a range of " << this->_argc - 1 << " elements with std::deque : ";
    std::cout << (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec) << " µs." << std::endl;
}

void    PmergeMe::_SortWBinarySearchInsertionSecondDequeHalf()
{
    std::deque<std::pair<int, int> >::iterator it = this->_deqPairedNbrs.begin();
    std::deque<int>::iterator it_next_end;
    std::deque<int>::iterator tmp;
    int next_end;
    int prev = 0;
    int index = 0;
    int j;

    for (; it != this->_deqPairedNbrs.end(); index++)
    {
        j = this->_jacobsthal[index];
        if (j > static_cast<int>(this->_deqPairedNbrs.size() - 1))
            j = this->_deqPairedNbrs.size() - 1;
        for(; j >= prev; it++, j--)
        {
            tmp = this->_deqSortedNbrs.begin();
            it_next_end = find(this->_deqSortedNbrs.begin(), this->_deqSortedNbrs.end(), this->_deqPairedNbrs[j].second);
            for(next_end = 0; tmp != it_next_end; tmp++, next_end++){
            }
            this->_BinarySearchInsertionDeq(this->_deqPairedNbrs[j].first, 0, next_end);
        }
        prev = this->_jacobsthal[index] + 1;
    }
    if (this->_odd >= 0)
        this->_BinarySearchInsertionDeq(this->_odd, 0, this->_deqSortedNbrs.size());
}

void    PmergeMe::_BinarySearchInsertionDeq(int nb, int start, int end)
{
    int mid = end - start;

    if (mid > 1)
    {
        mid = mid / 2 + mid % 2;
        if (nb >= this->_deqSortedNbrs[start + mid])
            this->_BinarySearchInsertionDeq(nb, start + mid, end);
        else 
            this->_BinarySearchInsertionDeq(nb, start, start + mid);
    }
    else
    {
        if (nb > this->_deqSortedNbrs[start + mid])
            mid += 1;
        else if (nb < this->_deqSortedNbrs[0])
            mid = 0;
        this->_deqSortedNbrs.insert(find(this->_deqSortedNbrs.begin(), this->_deqSortedNbrs.end(), this->_deqSortedNbrs[start + mid]), nb);
    }
}

void    PmergeMe::_SortRecursivelyFirstDequeHalf(int args)
{
    std::deque<std::pair<int, int> >::iterator it = this->_deqPairedNbrs.begin();
    int i = 0;
    static int big = 2147483647;
    int index = 0;
    int nb = 0;

    for(i = 0; it != this->_deqPairedNbrs.end();it++, i++){
        if (this->_deqPairedNbrs[i].second > nb && this->_deqPairedNbrs[i].second <= big)
        {
            nb = this->_deqPairedNbrs[i].second;
            index = i;
        }
    }
    big = nb;
    std::pair<int, int> tmp = std::make_pair(this->_deqPairedNbrs[index].first, this->_deqPairedNbrs[index].second);
    this->_deqPairedNbrs.erase(this->_deqPairedNbrs.begin() + index);
    if (args < (this->_argc-2)/2)
        this->_SortRecursivelyFirstDequeHalf(args + 1);
    this->_deqPairedNbrs.push_back(tmp);
    this->_deqSortedNbrs.push_back(tmp.second);
}
