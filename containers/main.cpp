/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/12 23:30:05 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include "list_iterator.hpp"
#include <limits>
#include "vector.hpp"
#include "vector_iterator.hpp"

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

template <class Container>
void print_container (std::string testName, Container cont)
{
	std::cout << testName;
	for (typename Container::iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

int main(void)
{
	ft::vector<int> ftVector1(10, 21);
	ft::vector<int> ftVector2(10, 42);
	
	// std::vector<int> stdVector1(50, 21);
	// std::vector<int> stdVector2(20, 42);

	ft::vector<int>::iterator ftIterator;
	// std::vector<int>::iterator stdIterator;
	
	ftIterator = ftVector1.begin();
	// stdIterator = stdVector1.begin();
	
	ftVector1.insert(ftIterator, 565);
	// stdVector1.insert(stdIterator, 565);

	print_container("Insert", ftVector1);
	
	return 0;
}