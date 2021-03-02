/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/02 18:48:39 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
// #include <stack>
// #include <vector>
#include <iterator>
#include "list_iterator.hpp"

int main(void)
{
	// ft::list<int> a(10, 456);
	// // a.push_back(0);
	// // a.push_back(1);
	// // a.push_back(2);
	// // a.push_back(3);
	// // a.push_back(4);
	// // a.push_back(5);
	// ft::list<int>::iterator it = a.begin();
	// ft::list<int>::iterator it2 = it;
	// it2++;
	// it2++;
	// it2++;

	// for (it = a.begin(); it != it2; it++)
	// 	std::cout << a.size() << " " << *it << std::endl;
	
	// it2++;
	// it2++;
	// it2++;
	// a.erase(it, it2);
	
	std::list<int> b;
	std::list<int>::iterator it3 = b.begin();
	
	b.assign(5, 678);
	for (it3 = b.begin(); it3 != b.end(); it3++)
		std::cout << *it3 << std::endl;
	it3 = b.begin();
	it3++;
	std::cout << "*********" << std::endl;
	b.assign(it3, b.end());
	for (it3 = b.begin(); it3 != b.end(); it3++)
		std::cout << *it3 << std::endl;
	return 0;
}