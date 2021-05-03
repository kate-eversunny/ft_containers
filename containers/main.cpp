/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/05/03 16:59:37 by pvivian          ###   ########.fr       */
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

static std::pair<int, int> vect_map1[20] =  {std::make_pair(50, 1),
							std::make_pair(25, 2), 
								std::make_pair(8, 3), std::make_pair(35, 4),
									std::make_pair(1, 5), std::make_pair(12, 6),
									std::make_pair(30, 7), std::make_pair(40, 8),
							std::make_pair(75, 9),
								std::make_pair(60, 10), std::make_pair(90, 11),
									std::make_pair(55, 12), std::make_pair(70, 13),
									std::make_pair(80, 14), std::make_pair(100, 15),
							std::make_pair(25, 2), 
								std::make_pair(8, 3), std::make_pair(35, 4),
								std::make_pair(8, 3), std::make_pair(35, 4)};

static std::pair<std::string, int> vect_map3[20] =  { std::make_pair("one", 1), std::make_pair("two", 2), std::make_pair("three", 3),
								std::make_pair("four", 4), std::make_pair("five", 5), std::make_pair("six", 6),
								std::make_pair("seven", 71), std::make_pair("eight", 81), std::make_pair("nine", 91),
								std::make_pair("seven", 72), std::make_pair("eight", 82), std::make_pair("nine", 92),
								std::make_pair("ten", 101), std::make_pair("eleven", 111), std::make_pair("twelve", 12),
								std::make_pair("ten", 102), std::make_pair("eleven", 112),
								std::make_pair("thirteen", 13), std::make_pair("fourteen", 14), std::make_pair("fifteen", 15) };
static std::vector<std::pair<int, int> > g_map1(vect_map1, vect_map1 + 20);
static std::vector<std::pair<std::string, int> > g_map3(vect_map3, vect_map3 + 20);

void erase_single_test() {
		{
			std::map<int, int> mp(g_map1.begin(), g_map1.end());
			ft::map<int, int> my_mp(g_map1.begin(), g_map1.end());
			
			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());

			mp.erase(++mp.begin());
			my_mp.erase(++my_mp.begin());

			mp.erase(--mp.end());
			my_mp.erase(--my_mp.end());

			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());
	

			std::pair<std::map<int, int>::iterator, bool> pr = mp.insert(std::make_pair(64, 1));
			std::pair<ft::map<int, int>::iterator, bool> my_pr = my_mp.insert(std::make_pair(64, 1));
	

			std::map<int, int>::iterator it = pr.first;
			ft::map<int, int>::iterator my_it = my_pr.first;
			mp.erase(it);
			my_mp.erase(my_it);

			it = mp.find(35);
			my_it = my_mp.find(35);
			mp.erase(it);
			my_mp.erase(my_it);


			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());


			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());
			
			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());
			
			mp.erase(--mp.end());
			my_mp.erase(--my_mp.end());
			my_it = my_mp.begin();
			for (; my_it != my_mp.end(); my_it++)
				std::cout << my_it->first << " " << my_it->second << std::endl;

			mp.erase(--mp.end());
			my_mp.erase(--my_mp.end());

			mp.erase(--mp.end());
			my_mp.erase(--my_mp.end());
		}
		{
			std::map<std::string, int> mp(g_map3.begin(), g_map3.end());
			ft::map<std::string, int> my_mp(g_map3.begin(), g_map3.end());

			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());

			mp.erase(++mp.begin());
			my_mp.erase(++my_mp.begin());
			
			mp.erase(++mp.begin());
			my_mp.erase(++my_mp.begin());

			mp.erase(mp.begin());
			my_mp.erase(my_mp.begin());

			mp.erase(--mp.end());
			my_mp.erase(--my_mp.end());

			mp.erase(--mp.end());
			my_mp.erase(--my_mp.end());

			std::pair<std::map<std::string, int>::iterator, bool> pr = mp.insert(std::make_pair("odin", 1));
			std::pair<ft::map<std::string, int>::iterator, bool> my_pr = my_mp.insert(std::make_pair("odin", 1));

			std::map<std::string, int>::iterator it = pr.first;
			ft::map<std::string, int>::iterator my_it = my_pr.first;

			mp.erase(it);
			my_mp.erase(my_it);

			it = mp.find("seven");
			my_it = my_mp.find("seven");
			mp.erase(it);
			my_mp.erase(my_it);

			it = mp.find("three");
			my_it = my_mp.find("three");
			mp.erase(it);
			my_mp.erase(my_it);

			it = mp.find("thirteen");
			my_it = my_mp.find("thirteen");
			mp.erase(it);
			my_mp.erase(my_it);

			it = mp.find("ten");
			my_it = my_mp.find("ten");
			mp.erase(it);
			my_mp.erase(my_it);
		}
	}

int main(void)
{
	erase_single_test();
	return 0;
}