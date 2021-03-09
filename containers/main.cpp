/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/09 18:46:02 by pvivian          ###   ########.fr       */
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

int main(void)
{
	ft::vector<int> vec(4, 42);
	// ft::vector<int> vec(vec2);

	// ft::vector<int>::iterator it = vec.begin();
	// for (it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << vec.size() << " " << *it << std::endl;


	// std::vector<int> a(4, 42);
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	
	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;

	// a.push_back(7);
	// std::cout << a.size() << " " << a.capacity() << std::endl;
	
	// std::vector<int>::iterator it2;
	// std::vector<int>::iterator it2 = a.begin();
	// for (it2 = a.begin(); it2 != a.end(); it2++)
		// std::cout << a.size() << " " << *it2 << std::endl;
	std::cout << "end" << std::endl;
	
	return 0;
}