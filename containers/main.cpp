/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/05 20:41:54 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
// #include <stack>
// #include <vector>
#include <iterator>
#include "list_iterator.hpp"

// for remove_if
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// for unique
template<class T>
struct is_near {
  bool operator() (T first, T second)
  { return (first-second<0); }
};

int main(void)
{
	ft::list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	ft::list<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_front(99);
	a.push_front(1);
	ft::list<int>::iterator it = a.begin();
	
	if (a < b)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	
	// a.reverse();
	// b.reverse();
	// for (it = a.begin(); it != a.end(); it++)
	// 	std::cout << a.size() << " " << *it << std::endl;
	// std::cout << std::endl;
	// for (it = b.begin(); it != b.end(); it++)
	// 	std::cout << b.size() << " " << *it << std::endl;
	std::cout << "end\n" << std::endl;
	std::list<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	std::list<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(99);
	c.push_front(1);
	if (c < d)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	// std::list<int>::iterator it3 = c.begin();
	// c.merge(d);
	// for (it3 = c.begin(); it3 != c.end(); it3++)
	// 	std::cout << c.size() << " " << *it3 << std::endl;
	
	return 0;
}