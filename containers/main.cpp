/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/21 20:52:23 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sstream>
#include "list.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
#include <queue>
#include <utility>
#include "list_iterator.hpp"
#include <limits>
#include "vector.hpp"
#include "vector_iterator.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "redBlackTree.hpp"
#include <map>
#include "map_iterator.hpp"
#include "map.hpp"
# include "reverse_iterator.hpp"

// for remove_if
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// for unique
template<class T1>
struct is_near {
  bool operator() (T1 first, T1 second)
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

bool mycomparison (int first, int second) { return (first % 2) < (second % 2); }

int main(void)
{
		std::vector<int> vect1;
		std::vector<int> vect2;
		for (int i = 0; i < 10; i++) { vect1.push_back(rand() % 100); }
		for (int i = 0; i < 10; i++) { vect2.push_back(rand() % 100); }

		std::list<int> ls1(vect1.begin(), vect1.end());
		std::list<int> ls2(vect2.begin(), vect2.end());
		ls1.sort();
		ls2.sort();

		ft::list<int> myls1(vect1.begin(), vect1.end());
		ft::list<int> myls2(vect2.begin(), vect2.end());
		myls1.sort();
		myls2.sort();

		ls1.merge(ls2);
		myls1.merge(myls2);

	print_container("std1", ls1);
	print_container("my1 ", myls1);

	ls2.assign(vect1.begin(), vect1.end());
	myls2.assign(vect1.begin(), vect1.end());
	ls2.sort();
	myls2.sort();
	
	ls1.merge(ls2, mycomparison);
	myls1.merge(myls2, mycomparison);
	
	print_container("std1", ls1);
	print_container("my1 ", myls1);


	return 0;
}