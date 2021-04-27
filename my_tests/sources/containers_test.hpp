/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers_test.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:45:56 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/27 18:17:25 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_TEST_HPP
# define CONTAINERS_TEST_HPP

# include <iostream>
# include <iomanip>
# include <cstdio>
# include <cstdlib>
# include <exception>

/* Include std containers and adapters */

# include <list>
# include <vector>
# include <map>
# include <stack>
# include <queue>

/* Include ft containers and adapters */

# include "list.hpp"
# include "list_iterator.hpp"
# include "vector.hpp"
# include "vector_iterator.hpp"
# include "map.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "allocator.hpp"
# include "stack.hpp"
# include "queue.hpp"

/* Define macros for coloured output */

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define PURPLE			"\x1b[35m"
# define LIGHT_BLUE		"\x1b[36m"
# define WHITE			"\x1b[37m"
# define NORMAL			"\x1b[0m"

/* Test functions prototypes for each container and adapter */

void		list_test(void);
void		map_test(void);
void		queue_test(void);
void		stack_test(void);
void		vector_test(void);

/* General comparing function */

template <typename T>
void	compareValues(int const & testNmb, T const & stdValue, T const & ftValue, std::string const & testName)
{
	int len = testName.length();
	
	std::cout << LIGHT_BLUE << std::setw(2) << testNmb << ". ";
	std::cout << testName << " ";
	for (int i = 0; (i + len) < 80; i++)
		std::cout << ".";
	std::cout << " " << NORMAL;
	
	if (stdValue == ftValue)
	{
		std::cout << GREEN << "OK" << NORMAL << std::endl;
		// std::cout << std::setw(86) << "Answer: " << stdValue << std::endl;
	}
	else
	{
		std::cout << RED << "WRONG" << NORMAL << std::endl;
		std::cout << std::setw(86) << "Expected answer: " << stdValue << std::endl;
		std::cout << std::setw(86) << "Your answer: " << ftValue << std::endl;
	}	
}

template <class Value>
bool ft_compare(const Value& val1, const Value& val2) { return val1 == val2; }

template <typename T1, typename T2>
void	compareContainers(int const & testNmb, const T1 & stdCont, const T2 & ftCont, std::string const & testName)
{
	int len = testName.length();
	typename T1::const_iterator sIt = stdCont.begin();
	typename T2::const_iterator fIt = ftCont.begin();
	
	std::cout << LIGHT_BLUE << std::setw(2) << testNmb << ". ";
	std::cout << testName << " ";
	for (int i = 0; (i + len) < 80; i++)
		std::cout << ".";
	std::cout << " " << NORMAL;
	
	for (; sIt != stdCont.end() && fIt != ftCont.end(); sIt++, fIt++)
	{
		if (!ft_compare(*sIt, *fIt))
		{
			std::cout << RED << "WRONG" << NORMAL << std::endl;
			return;
		}
	}
	if (sIt == stdCont.end() && fIt != ftCont.end())
	{
		std::cout << RED << "WRONG" << NORMAL << std::endl;
			return;
	}
	std::cout << GREEN << "OK" << NORMAL << std::endl;
}

/* Support functions */

template <class Container>
void print_container (std::string testName, Container cont)
{
	std::cout << testName;
	for (typename Container::iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

// for remove_if
template <class T>
struct ft_is_odd {
  bool operator() (const T& value) { return (value%2) ==1 ; }
};

// for unique
template<class T>
struct ft_is_near {
  bool operator() (T first, T second)
  { return (first-second < 1); }
};

// for merge
template<class T>
bool mycomparison (T first, T second)
{ return ( first < second ); }

// for sort
template<class T>
bool mycomparison2 (T first, T second)
{ return ( first > second ); }

#endif