/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:16 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/23 17:45:26 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"
#define VALUE_TYPE int, int

static void constructor(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CONSTRUCTOR ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE>::iterator stdIterator;
	ft::map<VALUE_TYPE>::iterator ftIterator;

	ft::map<VALUE_TYPE> ftmapBlanc;
	std::map<VALUE_TYPE> stdmapBlanc;

	compareValues(testNmb++, stdmapBlanc.size(), ftmapBlanc.size(), "Constructor default map(size)");

	std::map<VALUE_TYPE> temp;
	for (size_t i = 0; i < 20; i++)
		temp.insert(std::make_pair(i, i + 5));

	ft::map<VALUE_TYPE> temp2;
	for (int i = 0; i < 20; i++)
		temp2.insert(std::make_pair(i, i + 5));
	
	std::map<VALUE_TYPE> stdmap(temp.begin(), temp.end());
	ft::map<VALUE_TYPE> ftmap(temp2.begin(), temp2.end());


	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Constructor map(size)");

	compareContainers(testNmb++, stdmap, ftmap, "Constructor map(value)");

	/*		COPY		*/
	ft::map<VALUE_TYPE>ftmapCopy(ftmap);
	std::map<VALUE_TYPE>stdmapCopy(stdmap);
	
	compareValues(testNmb++, stdmapCopy.size(), ftmapCopy.size(), "Constructor copy (size)");
	
	compareContainers(testNmb++, stdmapCopy, ftmapCopy, "Constructor copy (value)");

	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	// getchar();
	// std::system("clear");
	return;
}

static void iterators(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ITERATORS ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE>::iterator stdIterator;
	ft::map<VALUE_TYPE>::iterator ftIterator;


	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 20; i++)
		stdmap.insert(std::make_pair(i, i + 5));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 20; i++)
		ftmap.insert(std::make_pair(i, i + 5));

	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();

	compareValues(testNmb++, stdIterator->first, ftIterator->first, "Begin (key)");
	compareValues(testNmb++, stdIterator->second, ftIterator->second, "Begin (value)");
	
	ftIterator = ftmap.end();
	stdIterator = stdmap.end();

	ftIterator--;
	stdIterator--;
	
	compareValues(testNmb++, stdIterator->first, ftIterator->first, "End (key)");
	compareValues(testNmb++, stdIterator->second, ftIterator->second, "End (value)");

	std::map<VALUE_TYPE>::reverse_iterator stdRevIterator;
	ft::map<VALUE_TYPE>::reverse_iterator ftRevIterator;

	ftRevIterator = ftmap.rbegin();
	stdRevIterator = stdmap.rbegin();

	compareValues(testNmb++, stdRevIterator->first, ftRevIterator->first, "Rbegin (key)");
	compareValues(testNmb++, stdRevIterator->second, ftRevIterator->second, "Rbegin (value)");
	
	ftRevIterator = ftmap.rend();
	stdRevIterator = stdmap.rend();

	--ftRevIterator;
	--stdRevIterator;
	
	compareValues(testNmb++, stdRevIterator->first, ftRevIterator->first, "Rend (key)");
	compareValues(testNmb++, stdRevIterator->second, ftRevIterator->second, "Rend(value)");
	
	compareContainers(testNmb++, stdmap, ftmap, "Iterator (all values)");

	// const iterators - need tests
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	return;
}

static void capacity(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CAPACITY ***                          " << NORMAL << std::endl;

	ft::map<VALUE_TYPE> ftmapBlank;
	std::map<VALUE_TYPE> stdmapBlank;
	compareValues(testNmb++, stdmapBlank.empty(), ftmapBlank.empty(), "Empty (blank)");

	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 20; i++)
		stdmap.insert(std::make_pair(i, i + 15));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 20; i++)
		ftmap.insert(std::make_pair(i, i + 15));
	
	compareValues(testNmb++, stdmap.empty(), ftmap.empty(), "Empty (full)");
	compareValues(testNmb++, stdmap.max_size(), ftmap.max_size(), "Max_size");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;

	return;
}

static void element_access(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 200; i++)
		stdmap.insert(std::make_pair(i, i + 5));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 200; i++)
		ftmap.insert(std::make_pair(i, i + 5));
	
	compareValues(testNmb++, stdmap[100], ftmap[100], "Operator[]1");
	compareValues(testNmb++, stdmap[200], ftmap[200], "Operator[]2");
	compareContainers(testNmb++, stdmap, ftmap, "Operator[] (all values)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	// getchar();
	// std::system("clear");
	return;
}

static void modifiers(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Modifiers ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 200; i++)
		stdmap.insert(std::make_pair(i, i + 15));

	std::map<VALUE_TYPE> temp;
	for (size_t i = 1000; i < 1200; i++)
		temp.insert(std::make_pair(i, i + 15));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 200; i++)
		ftmap.insert(std::make_pair(i, i + 15));
	

	ft::map<VALUE_TYPE>::iterator ftIterator;
	std::map<VALUE_TYPE>::iterator stdIterator;
	
// insert

	ftmap.insert(std::make_pair(300, 222226));
	stdmap.insert(std::make_pair(300, 222226));
	
	compareContainers(testNmb++, stdmap, ftmap, "Insert1 (value)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert1 (size)");

	ftIterator = ftmap.end();
	stdIterator = stdmap.end();
	
	ftmap.insert(ftIterator, std::make_pair(301, 222226));
	stdmap.insert(stdIterator, std::make_pair(301, 222226));

	compareContainers(testNmb++, stdmap, ftmap, "Insert2 (value)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert2 (size)");
	
	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();
	
	ftmap.insert(ftIterator, std::make_pair(302, 222226));
	stdmap.insert(stdIterator, std::make_pair(302, 222226));

	compareContainers(testNmb++, stdmap, ftmap, "Insert3 (value)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert3 (size)");
	
	ftmap.insert(temp.begin(), temp.end());
	stdmap.insert(temp.begin(), temp.end());

	compareContainers(testNmb++, stdmap, ftmap, "Insert4 range (value)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert4 range (size)");

	// getchar();
	std::cout << std::endl;
	
// swap
	ft::map<VALUE_TYPE> ftmap2;
	std::map<VALUE_TYPE> stdmap2;
	

	ftmap.swap(ftmap2);
	stdmap.swap(stdmap2);

	compareContainers(testNmb++, stdmap, ftmap, "Swap1 (value)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Swap1 (size)");

	compareContainers(testNmb++, stdmap2, ftmap2, "Swap2 (value)");
	compareValues(testNmb++, stdmap2.size(), ftmap2.size(), "Swap2 (size)");

	// getchar();
	std::cout << std::endl;

// erase
	for (size_t i = 0; i < 200; i++)
		stdmap.insert(std::make_pair(i, i + 15));

	for (int i = 0; i < 200; i++)
		ftmap.insert(std::make_pair(i, i + 15));
	
	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();
	
	ftmap.erase(ftIterator);
	stdmap.erase(stdIterator);
	
	compareContainers(testNmb++, stdmap, ftmap, "Erase one element 1 (values)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase one element 1 (size)");
	
	ftIterator = ftmap.end();
	stdIterator = stdmap.end();

	--ftIterator;
	--stdIterator;
	
	ftmap.erase(ftIterator);
	stdmap.erase(stdIterator);
	
	compareContainers(testNmb++, stdmap, ftmap, "Erase one element 2 (values)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase one element 2 (size)");

	
	ftmap.erase(10);
	stdmap.erase(10);

	compareContainers(testNmb++, stdmap, ftmap, "Erase one element 3 (values)");
	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase one element 3 (size)");
	
	// getchar();
	std::cout << std::endl;
	
// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	++ftIterator;
// 	++stdIterator;
	
// 	ftIterator = ftmap.erase(ftIterator, ftIterator + 5);
// 	stdIterator = stdmap.erase(stdIterator, stdIterator + 5);

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase range of elements 1 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase range of elements 1  (size)");

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();
	
// 	ftIterator = ftmap.erase(ftIterator, ftIterator + 5);
// 	stdIterator = stdmap.erase(stdIterator, stdIterator + 5);

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase range of elements 2 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase range of elements 2  (size)");

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();
	
// 	ftIterator = ftmap.erase(ftIterator, ftmap.end());
// 	stdIterator = stdmap.erase(stdIterator, stdmap.end());

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase range of elements 3 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase range of elements 3  (size)");

// 	getchar();
// 	std::cout << std::endl;

// // clear

// 	ftmap.push_back(42);
// 	ftmap.push_back(42);
// 	stdmap.push_back(42);
// 	stdmap.push_back(42);

// 	ftmap.clear();
// 	stdmap.clear();

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Clear (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Clear (size)");
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Clear (capacity)");
	
// 	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	// getchar();
	// std::system("clear");
	return;
}

void map_test()
{
	std::cout << GREEN << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          MAP TESTING           |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << NORMAL;

	constructor();
	iterators();
	capacity();
	element_access();
	modifiers();
	// observers();
	// operations();

	return;
}