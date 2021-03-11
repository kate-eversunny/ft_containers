/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/10 20:15:56 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
// #include <stack>
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
	ft::vector<int> ftVector(50, 21);
	std::vector<int> stdVector(50, 21); // add different values with insert

	ft::vector<int>::iterator ftIterator;
	std::vector<int>::iterator stdIterator;

	// ftIterator = ftVector.begin();
	// stdIterator = stdVector.begin();
	
	// ftIterator = ftVector.erase(ftIterator);
	// stdIterator = stdVector.erase(stdIterator);
	
	// ++ftIterator;
	// ++stdIterator;
	
	// ftIterator = ftVector.erase(ftIterator);
	// stdIterator = stdVector.erase(stdIterator);
	
	// ftIterator = ftVector.end();
	// stdIterator = stdVector.end();

	// --ftIterator;
	// --stdIterator;
	
	// ftIterator = ftVector.erase(ftIterator);
	// stdIterator = stdVector.erase(stdIterator);

	// ftIterator = ftVector.begin();
	// stdIterator = stdVector.begin();

	// ++ftIterator;
	// ++stdIterator;
	
	// ftIterator = ftVector.erase(ftIterator, ftIterator + 5);
	// stdIterator = stdVector.erase(stdIterator, stdIterator + 5);

	// ftIterator = ftVector.begin();
	// stdIterator = stdVector.begin();
	
	// ftIterator = ftVector.erase(ftIterator, ftIterator + 5);
	// stdIterator = stdVector.erase(stdIterator, stdIterator + 5);
	// print_container("Erase range 2", ftVector);
	// print_container("Erase range 2", stdVector);
	
	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();
	
	ftIterator = ftVector.erase(ftIterator, ftVector.end());
	stdIterator = stdVector.erase(stdIterator, stdVector.end());

	print_container("Erase range 3", ftVector);
	print_container("Erase range 3", stdVector);

	ftVector.push_back(42);
	ftVector.push_back(42);
	stdVector.push_back(42);
	stdVector.push_back(42);

	print_container("Clear", ftVector);
	print_container("Clear", stdVector);

	ftVector.clear();
	stdVector.clear();

	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();

	
	return 0;
}