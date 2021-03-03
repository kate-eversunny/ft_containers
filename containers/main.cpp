/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/03 18:37:50 by pvivian          ###   ########.fr       */
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
	ft::list<int> a;
	a.assign(11, 4);
	a.assign(12, 3);
	ft::list<int>::iterator it = a.begin();
	// ft::list<int>::iterator it2 = it;
	// it2++;
	// it2++;
	// it2++;
	
	for (it = a.begin(); it != a.end(); it++)
		std::cout << a.size() << " " << *it << std::endl;
	it = a.end();
	std::cout << a.size() << " " << *it << std::endl;

	// ft::list<int> b;
	// b.push_back(90);
	// b.push_back(90);
	// ft::list<int>::iterator it = b.begin();
	// it++;
	// b.insert(it, 10, 80);
	// b.insert(it, 999);
	// b.insert(b.begin(), a.begin(), a.end());
	// b.swap(a);
	// it = b.begin();
	// for (it = b.begin(); it != b.end(); it++)
	// 	std::cout << b.size() << " " << *it << std::endl;
	// std::cout << "end" << std::endl;

	// std::list<int> c;
	// std::list<int>::iterator it3 = c.begin();
	// std::list<int>::iterator it4 = it3;
	// c.insert(it3, 5, 5);
	// c.assign(5, 678);
	// it4++;
	// it4++;
	// c.assign(it3, it4);
	
	// for (it3 = c.begin(); it3 != c.end(); it3++)
	// 	std::cout << *it3 << std::endl;
	// it3 = b.begin();
	// it3++;
	// std::cout << "*********" << std::endl;
	// b.assign(it3, b.end());
	// for (it3 = b.begin(); it3 != b.end(); it3++)
	// 	std::cout << *it3 << std::endl;
	return 0;
}