/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/18 21:14:06 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft::redBlackTree<int, int> bst;
  bst.insert(std::pair<int, int> (1, 55));
  bst.insert(std::pair<int, int> (2, 40));
  bst.insert(std::pair<int, int> (3, 65));
  bst.insert(std::pair<int, int> (4, 60));
  bst.insert(std::pair<int, int> (5, 75));
  bst.insert(std::pair<int, int> (6, 57));
  bst.insert(std::pair<int, int> (7, 60));
  bst.insert(std::pair<int, int> (8, 75));
  bst.insert(std::pair<int, int> (9, 57));
  bst.insert(std::pair<int, int> (10, 60));
  bst.insert(std::pair<int, int> (11, 75));
  bst.insert(std::pair<int, int> (12, 57));

  bst.print(bst.getRoot(), "", true);
  std::cout << std::endl
     << "After deleting" << std::endl;
  bst.deleteNode(6);
  bst.deleteNode(4);
  bst.deleteNode(12);
  bst.print(bst.getRoot(), "", true);
	
	return 0;
}