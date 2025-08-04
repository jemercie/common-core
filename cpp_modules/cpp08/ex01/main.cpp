/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:35:59 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/23 16:36:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sppp = Span(5);
	std::vector<int> veccc = sp.getVec();
	sppp.addNumber(veccc.begin(), veccc.end());

	std::cout << "print sp :" << std::endl;
	sp.printVectorContent();

	std::cout << "print sppp :" << std::endl;
	sppp.printVectorContent();

	Span	eee(1000000);

	try {
		std::cout << "shortest span: " << eee.shortestSpan() << std::endl;
		std::cout << "longest span: " << eee.longestSpan() << std::endl;
	}
	catch (std::exception &err){
		std::cout << err.what();
	}
	try {
		for (int i = -50000; i < 50000; i++){
			eee.addNumber(i);
		}
	}
	catch(std::exception &err) {
		std::cout << err.what();
	}
	try {
	std::cout << "shortest span: " << eee.shortestSpan() << std::endl;
	std::cout << "longest span: " << eee.longestSpan() << std::endl;
	}
	catch (std::exception &err){
		std::cout << err.what();
	}

	return (0);
}
