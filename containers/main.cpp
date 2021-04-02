/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/01 18:24:34 by pvivian          ###   ########.fr       */
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
//#include "redBlackTree.hpp"
#include <map>
#include "map_iterator.hpp"
#include "map.hpp"

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

int main(void)
{
// 	ft::redBlackTree<int, int> bst;
//   bst.insert(std::pair<int, int> (1, 55));
//   bst.insert(std::pair<int, int> (2, 40));
//   bst.insert(std::pair<int, int> (3, 65));
//   bst.insert(std::pair<int, int> (4, 60));
//   bst.insert(std::pair<int, int> (5, 75));
//   bst.insert(std::pair<int, int> (6, 57));
//   bst.insert(std::pair<int, int> (7, 60));
//   bst.insert(std::pair<int, int> (8, 75));
//   bst.insert(std::pair<int, int> (9, 57));
//   bst.insert(std::pair<int, int> (10, 60));
//   bst.insert(std::pair<int, int> (11, 75));
//   bst.insert(std::pair<int, int> (12, 57));

//   bst.print(bst.getRoot(), "", true);
//   std::cout << std::endl
//      << "After deleting" << std::endl;
//   bst.deleteNode(6);
//   bst.deleteNode(4);
//   bst.deleteNode(12);
//   bst.print(bst.getRoot(), "", true);

// std::vector<const int> test(5, 5);
// ft::vector<const int> test1(5,5);
// std::list<const int> test2(5, 5);
// ft::list<const int> test3(5,5);

// std::cout << test[0] << " " << test1[0] << std::endl;
// 	while(1)
// 	{
// 		;
// 	}

	// std::map<int,int> stdMap;
	// stdMap.insert(std::pair<int, int> (1, 55));
	// stdMap.insert(std::pair<int, int> (2, 40));
	// stdMap.insert(std::pair<int, int> (3, 65));
	// stdMap.insert(std::pair<int, int> (4, 60));
	// stdMap.insert(std::pair<int, int> (5, 75));
	// stdMap.insert(std::pair<int, int> (6, 57));
	// stdMap.insert(std::pair<int, int> (7, 60));
	// stdMap.insert(std::pair<int, int> (8, 75));
	// stdMap.insert(std::pair<int, int> (9, 57));
	// stdMap.insert(std::pair<int, int> (10, 60));
	// stdMap.insert(std::pair<int, int> (11, 75));
	// stdMap.insert(std::pair<int, int> (13, 57));

	// std::map<int, int>::iterator it;
	// std::map<int, int>::reverse_iterator rit;

	// stdMap.erase(stdMap.begin(), stdMap.end());
	// for (it = stdMap.begin(); it != stdMap.end(); it++)
	// 	std::cout << it->first << std::endl;
	
	// for (it = stdMap.end(); it != stdMap.begin(); --it)
	// 	std::cout << it->first << std::endl;
	// it = stdMap.end();
	// std::cout << it->second << std::endl;
	// rit = stdMap.rend();
	// std::cout << rit->first << std::endl;


	ft::map<int,int> ftMap;
	ftMap.insert(std::pair<int, int> (1, 55));
	ftMap.insert(std::pair<int, int> (2, 40));
	ftMap.insert(std::pair<int, int> (3, 65));
	ftMap.insert(std::pair<int, int> (4, 60));
	ftMap.insert(std::pair<int, int> (5, 75));
	ftMap.insert(std::pair<int, int> (6, 57));
	ftMap.insert(std::pair<int, int> (7, 60));
	ftMap.insert(std::pair<int, int> (8, 75));
	ftMap.insert(std::pair<int, int> (9, 57));
	ftMap.insert(std::pair<int, int> (10, 60));
	ftMap.insert(std::pair<int, int> (11, 75));
	ftMap.insert(std::pair<int, int> (13, 57));
	// ftMap.insert(std::pair<int, int> (14, 55));
	// ftMap.insert(std::pair<int, int> (15, 40));
	// ftMap.insert(std::pair<int, int> (16, 65));
	// ftMap.insert(std::pair<int, int> (17, 60));
	// ftMap.insert(std::pair<int, int> (18, 75));
	// ftMap.insert(std::pair<int, int> (19, 57));
	// ftMap.insert(std::pair<int, int> (20, 60));
	// ftMap.insert(std::pair<int, int> (21, 75));
	// ftMap.insert(std::pair<int, int> (22, 57));
	// ftMap.insert(std::pair<int, int> (23, 60));
	// ftMap.insert(std::pair<int, int> (24, 75));
	// ftMap.insert(std::pair<int, int> (25, 57));
	
	
	ft::map<int, int>::iterator it;
	// // ft::map<int, int>::reverse_iterator rit;
	
	// it = ftMap.end();
	// --it;
	// --it;
	// ftMap.insert(it, std::pair<int, int> (26, 57));
	
	ftMap.erase(1);
	// it = ftMap.begin();
	// ftMap.erase(it);
	// for (it = ftMap.begin(); it != ftMap.end(); it++)
	// 	std::cout << it->first << std::endl;
	
	// ftMap.erase(ftMap.begin(), ftMap.end());
	
	
	
	// ft::redBlackTree<int, int> tree;
	// tree.insert(std::pair<int, int> (1, 55));
	// tree.insert(std::pair<int, int> (2, 40));
	// tree.insert(std::pair<int, int> (3, 65));
	// tree.insert(std::pair<int, int> (4, 60));
	// tree.insert(std::pair<int, int> (5, 75));
	// tree.insert(std::pair<int, int> (6, 57));
	// tree.insert(std::pair<int, int> (7, 60));
	// tree.insert(std::pair<int, int> (8, 75));
	// tree.insert(std::pair<int, int> (9, 57));
	// tree.insert(std::pair<int, int> (10, 60));
	// tree.insert(std::pair<int, int> (11, 75));
	// tree.insert(std::pair<int, int> (14, 57));
	// tree.print(tree.getRoot(), "", true);
	

	for (it = ftMap.begin(); it != ftMap.end(); it++)
		std::cout << it->first << std::endl;
	// it = ftMap.end();
	// for (--it; it != ftMap.begin(); --it)
	// 	std::cout << it->first << std::endl;

	// it = ftMap.end();
	// std::cout << it->first << std::endl;
	// rit = ftMap.rend();
	// std::cout << rit->first << std::endl;
	return 0;
}