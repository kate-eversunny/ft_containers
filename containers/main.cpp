/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/15 16:13:59 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
#include <queue>
#include "list_iterator.hpp"
#include <limits>
#include "vector.hpp"
#include "vector_iterator.hpp"
#include "stack.hpp"
#include "queue.hpp"


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
	ft::queue<int,ft::list<int> > new_queue;
	ft::queue<int,ft::list<int> > new_queue2;
	bool res = new_queue == new_queue2;
	std::cout << res << std::endl;
	new_queue.push(99);
	new_queue.push(12);
	new_queue.push(10);

	res = new_queue != new_queue2;
	std::cout << res << std::endl;

	new_queue.pop();
	
	res = new_queue < new_queue2;
	std::cout << res << std::endl;

	std::cout << "std" << std::endl;

	std::queue<int,std::list<int> > std_queue;
	std::queue<int,std::list<int> > std_queue2;
	bool res2 = std_queue == std_queue2;
	std::cout << res2 << std::endl;
	std_queue.push(99);
	std_queue.push(12);
	std_queue.push(10);

	res2 = std_queue != std_queue2;
	std::cout << res2 << std::endl;

	std_queue.pop();
	
	res2 = std_queue < std_queue2;
	std::cout << res2 << std::endl;
	
	return 0;
}