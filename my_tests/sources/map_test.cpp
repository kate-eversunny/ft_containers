/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:16 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/26 21:05:58 by pvivian          ###   ########.fr       */
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

	compareValues(++testNmb, stdmapBlanc.size(), ftmapBlanc.size(), "Constructor default map(size)");

	std::map<VALUE_TYPE> temp;
	for (size_t i = 0; i < 20; i++)
		temp.insert(std::make_pair(i, i + 5));

	ft::map<VALUE_TYPE> temp2;
	for (int i = 0; i < 20; i++)
		temp2.insert(std::make_pair(i, i + 5));
	
	std::map<VALUE_TYPE> stdmap(temp.begin(), temp.end());
	ft::map<VALUE_TYPE> ftmap(temp2.begin(), temp2.end());


	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Constructor map(size)");

	compareContainers(++testNmb, stdmap, ftmap, "Constructor map(value)");

	/*		COPY		*/
	ft::map<VALUE_TYPE>ftmapCopy(ftmap);
	std::map<VALUE_TYPE>stdmapCopy(stdmap);
	
	compareValues(++testNmb, stdmapCopy.size(), ftmapCopy.size(), "Constructor copy (size)");
	
	compareContainers(++testNmb, stdmapCopy, ftmapCopy, "Constructor copy (value)");

	
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

	compareValues(++testNmb, stdIterator->first, ftIterator->first, "Begin (key)");
	compareValues(++testNmb, stdIterator->second, ftIterator->second, "Begin (value)");
	
	ftIterator = ftmap.end();
	stdIterator = stdmap.end();

	ftIterator--;
	stdIterator--;
	
	compareValues(++testNmb, stdIterator->first, ftIterator->first, "End (key)");
	compareValues(++testNmb, stdIterator->second, ftIterator->second, "End (value)");

	std::map<VALUE_TYPE>::reverse_iterator stdRevIterator;
	ft::map<VALUE_TYPE>::reverse_iterator ftRevIterator;

	ftRevIterator = ftmap.rbegin();
	stdRevIterator = stdmap.rbegin();

	compareValues(++testNmb, stdRevIterator->first, ftRevIterator->first, "Rbegin (key)");
	compareValues(++testNmb, stdRevIterator->second, ftRevIterator->second, "Rbegin (value)");
	
	ftRevIterator = ftmap.rend();
	stdRevIterator = stdmap.rend();

	--ftRevIterator;
	--stdRevIterator;
	
	compareValues(++testNmb, stdRevIterator->first, ftRevIterator->first, "Rend (key)");
	compareValues(++testNmb, stdRevIterator->second, ftRevIterator->second, "Rend(value)");
	
	compareContainers(++testNmb, stdmap, ftmap, "Iterator (all values)");

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
	compareValues(++testNmb, stdmapBlank.empty(), ftmapBlank.empty(), "Empty (blank)");

	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 20; i++)
		stdmap.insert(std::make_pair(i, i + 15));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 20; i++)
		ftmap.insert(std::make_pair(i, i + 15));
	
	compareValues(++testNmb, stdmap.empty(), ftmap.empty(), "Empty (full)");
	compareValues(++testNmb, stdmap.max_size(), ftmap.max_size(), "Max_size");
	
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
	
	compareValues(++testNmb, stdmap[100], ftmap[100], "Operator[]1");
	compareValues(++testNmb, stdmap[200], ftmap[200], "Operator[]2");
	compareContainers(++testNmb, stdmap, ftmap, "Operator[] (all values)");
	
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
	
	compareContainers(++testNmb, stdmap, ftmap, "Insert1 (value)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Insert1 (size)");

	ftIterator = ftmap.end();
	stdIterator = stdmap.end();
	
	ftmap.insert(ftIterator, std::make_pair(301, 222226));
	stdmap.insert(stdIterator, std::make_pair(301, 222226));

	compareContainers(++testNmb, stdmap, ftmap, "Insert2 (value)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Insert2 (size)");
	
	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();
	
	ftmap.insert(ftIterator, std::make_pair(302, 222226));
	stdmap.insert(stdIterator, std::make_pair(302, 222226));

	compareContainers(++testNmb, stdmap, ftmap, "Insert3 (value)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Insert3 (size)");
	
	ftmap.insert(temp.begin(), temp.end());
	stdmap.insert(temp.begin(), temp.end());

	compareContainers(++testNmb, stdmap, ftmap, "Insert4 range (value)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Insert4 range (size)");

	// getchar();
	std::cout << std::endl;
	
// swap
	ft::map<VALUE_TYPE> ftmap2;
	std::map<VALUE_TYPE> stdmap2;
	

	ftmap.swap(ftmap2);
	stdmap.swap(stdmap2);

	compareContainers(++testNmb, stdmap, ftmap, "Swap1 (value)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Swap1 (size)");

	compareContainers(++testNmb, stdmap2, ftmap2, "Swap2 (value)");
	compareValues(++testNmb, stdmap2.size(), ftmap2.size(), "Swap2 (size)");

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
	
	compareContainers(++testNmb, stdmap, ftmap, "Erase one element 1 (values)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Erase one element 1 (size)");
	
	ftIterator = ftmap.end();
	stdIterator = stdmap.end();

	--ftIterator;
	--stdIterator;
	
	ftmap.erase(ftIterator);
	stdmap.erase(stdIterator);
	
	compareContainers(++testNmb, stdmap, ftmap, "Erase one element 2 (values)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Erase one element 2 (size)");

	
	ftmap.erase(10);
	stdmap.erase(10);

	compareContainers(++testNmb, stdmap, ftmap, "Erase one element 3 (values)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Erase one element 3 (size)");
	
	// getchar();
	std::cout << std::endl;
	
	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();

	++ftIterator;
	++stdIterator;
	
	ftmap.erase(ftIterator, ++ftIterator);
	stdmap.erase(stdIterator, ++stdIterator);

	compareContainers(++testNmb, stdmap, ftmap, "Erase range of elements 1 (values)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Erase range of elements 1  (size)");


	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();
	
	ftmap.erase(ftIterator, ftmap.end());
	stdmap.erase(stdIterator, stdmap.end());

	compareContainers(++testNmb, stdmap, ftmap, "Erase range of elements 2 (values)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Erase range of elements 2  (size)");

	// getchar();
	std::cout << std::endl;

// clear

	ftmap.insert(std::make_pair(1, 42));
	ftmap.insert(std::make_pair(2, 42));
	stdmap.insert(std::make_pair(1, 42));
	stdmap.insert(std::make_pair(2, 42));

	ftmap.clear();
	stdmap.clear();

	compareContainers(++testNmb, stdmap, ftmap, "Clear (values)");
	compareValues(++testNmb, stdmap.size(), ftmap.size(), "Clear (size)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	// getchar();
	// std::system("clear");
	return;
}

static void observers(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Observers ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 300; i++)
		stdmap.insert(std::make_pair(i, i + 10));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 300; i++)
		ftmap.insert(std::make_pair(i, i + 10));
	
	ft::map<VALUE_TYPE>::iterator ftIterator;
	std::map<VALUE_TYPE>::iterator stdIterator;

	ft::map<VALUE_TYPE>::key_compare ftcomp = ftmap.key_comp();
	std::map<VALUE_TYPE>::key_compare stdcomp = stdmap.key_comp();

	ftIterator = ftmap.begin();
	stdIterator = stdmap.begin();
	
	compareValues(++testNmb, stdcomp(stdIterator->first, ftIterator->second), ftcomp(stdIterator->first, ftIterator->second), "Key_comp");
	compareValues(++testNmb, stdmap.value_comp()(*stdIterator, *ftIterator), ftmap.value_comp()(*stdIterator, *ftIterator), "Value_comp");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	// getchar();
	// std::system("clear");
}

static void operations(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Operations ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE> stdmap;
	for (size_t i = 0; i < 300; i++)
		stdmap.insert(std::make_pair(i, i + 10));

	ft::map<VALUE_TYPE> ftmap;
	for (int i = 0; i < 300; i++)
		ftmap.insert(std::make_pair(i, i + 10));
	
	ft::map<VALUE_TYPE>::iterator ftIterator;
	std::map<VALUE_TYPE>::iterator stdIterator;

// find
	ftIterator = ftmap.find(20);
	stdIterator = stdmap.find(20);
	
	compareValues(++testNmb, stdIterator->second, ftIterator->second, "Find (valid value)");

	bool ftRes = false;
	bool stdRes = false;
	
	ftIterator = ftmap.find(5000);
	stdIterator = stdmap.find(5000);

	if (ftIterator == ftmap.end())
		ftRes = true;
	if (stdIterator == stdmap.end())
		stdRes = true;
	compareValues(++testNmb, stdRes, ftRes, "Find (invalid value)");
	
//count
	compareValues(++testNmb, stdmap.count(20), ftmap.count(20), "Count (valid value)");
	compareValues(++testNmb, stdmap.count(50000), ftmap.count(50000), "Count (invalid value)");

//lower_bound
	ftIterator = ftmap.lower_bound(20);
	stdIterator = stdmap.lower_bound(20);
	
	compareValues(++testNmb, stdIterator->first, ftIterator->first, "Lower_bound (valid value)");

	ftIterator = ftmap.lower_bound(50000);
	stdIterator = stdmap.lower_bound(50000);
	
	if (ftIterator == ftmap.end())
		ftRes = true;
	if (stdIterator == stdmap.end())
		stdRes = true;
	compareValues(++testNmb, stdRes, ftRes, "Lower_bound(invalid value)");

//upper_bound
	ftIterator = ftmap.upper_bound(20);
	stdIterator = stdmap.upper_bound(20);
	
	compareValues(++testNmb, stdIterator->first, ftIterator->first, "Upper_bound (valid value)");

	ftIterator = ftmap.upper_bound(50000);
	stdIterator = stdmap.upper_bound(50000);
	
	if (ftIterator == ftmap.end())
		ftRes = true;
	if (stdIterator == stdmap.end())
		stdRes = true;
	compareValues(++testNmb, stdRes, ftRes, "Upper_bound(invalid value)");

//equal_range

	ftIterator = ftmap.equal_range(20).first;
	stdIterator = stdmap.equal_range(20).first;
	
	compareValues(++testNmb, stdIterator->second, ftIterator->second, "Equal_range (valid value)");

	ftIterator = ftmap.equal_range(-1).second;
	stdIterator = stdmap.equal_range(-1).second;
	
	if (ftIterator == ftmap.end())
		ftRes = true;
	if (stdIterator == stdmap.end())
		stdRes = true;
	compareValues(++testNmb, stdRes, ftRes, "Equal_range(invalid value)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	// getchar();
	// std::system("clear");
}

static void non_member_func(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Non-member functions overloads ***                          " << NORMAL << std::endl;

	std::map<VALUE_TYPE> stdmap1;
	for (size_t i = 0; i < 300; i++)
		stdmap1.insert(std::make_pair(i, i + 10));

	std::map<VALUE_TYPE> stdmap2;
	for (size_t i = 0; i < 300; i++)
		stdmap2.insert(std::make_pair(i, i + 10));

	std::map<VALUE_TYPE> stdmap3;
	for (size_t i = 0; i < 100; i++)
		stdmap3.insert(std::make_pair(i, i + 11));

	ft::map<VALUE_TYPE> ftmap1;
	for (int i = 0; i < 300; i++)
		ftmap1.insert(std::make_pair(i, i + 10));

	ft::map<VALUE_TYPE> ftmap2;
	for (int i = 0; i < 300; i++)
		ftmap2.insert(std::make_pair(i, i + 10));

	ft::map<VALUE_TYPE> ftmap3;
	for (size_t i = 0; i < 100; i++)
		ftmap3.insert(std::make_pair(i, i + 11));
	
	compareValues(++testNmb, stdmap1 == stdmap2, ftmap1 == ftmap2, "Operator== 1");
	compareValues(++testNmb, stdmap1 == stdmap3, ftmap1 == ftmap3, "Operator== 2");

	compareValues(++testNmb, stdmap1 == stdmap2, ftmap1 == ftmap2, "Operator!= 1");
	compareValues(++testNmb, stdmap1 == stdmap3, ftmap1 == ftmap3, "Operator!= 2");

	compareValues(++testNmb, stdmap1 < stdmap2, ftmap1 < ftmap2, "Operator< 1");
	compareValues(++testNmb, stdmap1 < stdmap3, ftmap1 < ftmap3, "Operator< 2");

	compareValues(++testNmb, stdmap1 <= stdmap2, ftmap1 <= ftmap2, "Operator<= 1");
	compareValues(++testNmb, stdmap1 <= stdmap3, ftmap1 <= ftmap3, "Operator<= 2");

	compareValues(++testNmb, stdmap1 > stdmap2, ftmap1 > ftmap2, "Operator> 1");
	compareValues(++testNmb, stdmap1 > stdmap3, ftmap1 > ftmap3, "Operator> 2");

	compareValues(++testNmb, stdmap1 >= stdmap2, ftmap1 >= ftmap2, "Operator>= 1");
	compareValues(++testNmb, stdmap1 >= stdmap3, ftmap1 >= ftmap3, "Operator>= 2");
	
	getchar();
	std::cout << std::endl;
	
// swap

	ft::swap(ftmap1, ftmap3);
	std::swap(stdmap1, stdmap3);

	compareContainers(++testNmb, stdmap1, ftmap1, "Swap1 (value)");
	compareValues(++testNmb, stdmap1.size(), ftmap1.size(), "Swap1 (size)");

	compareContainers(++testNmb, stdmap3, ftmap3, "Swap2 (value)");
	compareValues(++testNmb, stdmap3.size(), ftmap3.size(), "Swap2 (size)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
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
	observers();
	operations();
	non_member_func();

	return;
}