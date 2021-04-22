/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:16 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/22 20:58:55 by pvivian          ###   ########.fr       */
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
	{
		temp2.insert(ft::pair<const int, int>(i, i + 5));
	}
	
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
	
	getchar();
	std::system("clear");
	return;
}

// static void iterators(void)
// {
// 	int testNmb = 0;
	
// 	std::cout << std::endl << YELLOW << "                              *** ITERATORS ***                          " << NORMAL << std::endl;

// 	std::map<VALUE_TYPE>::iterator stdIterator;
// 	ft::map<VALUE_TYPE>::iterator ftIterator;

// 	ft::map<VALUE_TYPE> ftmap(50, 21);
// 	ftmap.push_back(42);
// 	std::map<VALUE_TYPE> stdmap(50, 21);
// 	stdmap.push_back(42);

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Begin (value)");
	
// 	ftIterator = ftmap.end();
// 	stdIterator = stdmap.end();
	
// 	--ftIterator;
// 	--stdIterator;

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "End (value)");

// 	std::map<VALUE_TYPE>::reverse_iterator stdRevIterator;
// 	ft::map<VALUE_TYPE>::reverse_iterator ftRevIterator;

// 	ftRevIterator = ftmap.rbegin();
// 	stdRevIterator = stdmap.rbegin();

// 	compareValues(testNmb++, *stdRevIterator, *ftRevIterator, "Rbegin (value)");
	
// 	ftRevIterator = ftmap.rend();
// 	stdRevIterator = stdmap.rend();

// 	--ftRevIterator;
// 	--stdRevIterator;
	
// 	compareValues(testNmb++, *stdRevIterator, *ftRevIterator, "Rend (value)");
	

// 	// const iterators - need tests
	
// 	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
// 	getchar();
// 	std::system("clear");
// 	return;
// }

// static void capacity(void)
// {
// 	int testNmb = 0;
	
// 	std::cout << std::endl << YELLOW << "                              *** CAPACITY ***                          " << NORMAL << std::endl;

// 	ft::map<VALUE_TYPE> ftmapBlank;
// 	std::map<VALUE_TYPE> stdmapBlank;
// 	compareValues(testNmb++, stdmapBlank.empty(), ftmapBlank.empty(), "Empty (blank)");

// 	ft::map<VALUE_TYPE> ftmap(5, 21);
// 	ftmap.push_back(42);
// 	ftmap.push_back(42);
// 	ftmap.push_back(42);
// 	ftmap.push_back(42);
// 	ftmap.pop_back();
// 	ftmap.push_back(553);
// 	std::map<VALUE_TYPE> stdmap(5, 21);
// 	stdmap.push_back(42);
// 	stdmap.push_back(42);
// 	stdmap.push_back(42);
// 	stdmap.push_back(42);
// 	stdmap.pop_back();
// 	stdmap.push_back(553);
	
// 	compareValues(testNmb++, stdmap.empty(), ftmap.empty(), "Empty (full)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Size");
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Capacity");
// 	compareValues(testNmb++, stdmap.max_size(), ftmap.max_size(), "Max_size");
	
// 	ftmap.reserve(100);
// 	stdmap.reserve(100);
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Reserve1 (capacity)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Reserve1 (size)");
// 	compareValues(testNmb++, stdmap.front(), ftmap.front(), "Reserve1 (front)");
// 	compareValues(testNmb++, stdmap.back(), ftmap.back(), "Reserve1 (back)");
	
// 	ftmap.reserve(20);
// 	stdmap.reserve(20);
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Reserve2 (capacity)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Reserve2 (size)");
// 	compareValues(testNmb++, stdmap.front(), ftmap.front(), "Reserve1 (front)");
// 	compareValues(testNmb++, stdmap.back(), ftmap.back(), "Reserve2 (back)");

// 	ftmap.resize(200);
// 	stdmap.resize(200);
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Resize1 (capacity)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Resize1 (size)");
	
// 	ftmap.resize(50);
// 	stdmap.resize(50);
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Resize2 (capacity)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Resize2 (size)");
	
// 	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
// 	getchar();
// 	std::system("clear");
// 	return;
// }

// static void element_access(void)
// {
// 	int testNmb = 0;
	
// 	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

// 	ft::map<VALUE_TYPE> ftmap(200, 21);
// 	ftmap.push_back(42);
// 	std::map<VALUE_TYPE> stdmap(200, 21);
// 	stdmap.push_back(42);
	
// 	compareValues(testNmb++, stdmap[100], ftmap[100], "Operator[]1");
// 	compareValues(testNmb++, stdmap[200], ftmap[200], "Operator[]2");
	
// 	compareValues(testNmb++, stdmap.at(50), ftmap.at(50), "At (valid index)");
	
// 	bool stdException = false;
// 	bool ftException = false;
// 	try {
// 		stdmap.at(500);
// 	}
// 	catch(const std::exception& e) {
// 		// std::cerr << std::endl << "Std exception: " << e.what() <<std::endl;
// 		stdException = true;
// 	}
// 	try {
// 		ftmap.at(500);
// 	}
// 	catch(const std::exception& e) {
// 		// std::cerr << "Ft exception:  " << e.what() <<std::endl;
// 		ftException = true;
// 	}

// 	compareValues(testNmb++, stdException, ftException, "At (invalid index)");
	
// 	compareValues(testNmb++, stdmap.front(), ftmap.front(), "Front");
// 	compareValues(testNmb++, stdmap.back(), ftmap.back(), "Back");
	
// 	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
// 	getchar();
// 	std::system("clear");
// 	return;
// }

// static void modifiers(void)
// {
// 	int testNmb = 0;
	
// 	std::cout << std::endl << YELLOW << "                              *** Modifiers ***                          " << NORMAL << std::endl;

// 	ft::map<VALUE_TYPE> ftmap;
// 	ft::map<VALUE_TYPE> ftmap2(200, 42);
// 	std::map<VALUE_TYPE> stdmap;
// 	std::map<VALUE_TYPE> stdmap2(200, 42);

// 	ft::map<VALUE_TYPE>::iterator ftIterator;
// 	std::map<VALUE_TYPE>::iterator stdIterator;
	
// // push_back && pop_back

// 	ftmap.push_back(222);
// 	ftmap.push_back(222);
// 	ftmap.push_back(222);
// 	ftmap.push_back(222);

// 	stdmap.push_back(222);
// 	stdmap.push_back(222);
// 	stdmap.push_back(222);
// 	stdmap.push_back(222);
	
// 	compareValues(testNmb++, stdmap.back(), ftmap.back(), "Push_back (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Push_back (size)");

// 	ftmap.pop_back();
// 	ftmap.pop_back();
// 	ftmap.pop_back();

// 	stdmap.pop_back();
// 	stdmap.pop_back();
// 	stdmap.pop_back();
	
// 	compareValues(testNmb++, stdmap.back(), ftmap.back(), "Pop_back1 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Pop_back1 (size)");
	
// 	ftmap.pop_back();
// 	stdmap.pop_back();

// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Pop_back2 (size)");
	
// 	getchar();
// 	std::cout << std::endl;
	
// // assign

// 	ftmap.assign(20, 555);
// 	stdmap.assign(20, 555);

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Assign1 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Assign1 (size)");

// 	ftmap.assign(600, 2121);
// 	stdmap.assign(600, 2121);

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Assign2 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Assign2 (size)");

// 	getchar();
// 	std::cout << std::endl;

// // insert

// 	ftIterator = ftmap.end();
// 	stdIterator = stdmap.end();
	
// 	ftmap.insert(ftIterator, 565);
// 	stdmap.insert(stdIterator, 565);

// 	ftIterator = ftmap.end();
// 	stdIterator = stdmap.end();
	
// 	ftIterator--;
// 	stdIterator--;

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Insert1 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert1 (size)");
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Insert1 (capacity)");

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();
	
// 	ftIterator = ftmap.insert(ftIterator, 565);
// 	stdIterator = stdmap.insert(stdIterator, 565);

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Insert2 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert2 (size)");
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Insert2 (capacity)");

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();
	
// 	ftmap.insert(ftIterator, 20, 333);
// 	stdmap.insert(stdIterator, 20, 333);

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Insert3 range (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Insert3 range (size)");
// 	compareValues(testNmb++, stdmap.capacity(), ftmap.capacity(), "Insert3 range(capacity)");

// 	getchar();
// 	std::cout << std::endl;
	
// // swap

// 	ftmap.swap(ftmap2);
// 	stdmap.swap(stdmap2);
	
// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Swap1 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Swap1 (size)");

// 	ftIterator = ftmap2.begin();
// 	stdIterator = stdmap2.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Swap2 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Swap2 (size)");

// 	getchar();
// 	std::cout << std::endl;

// // erase

// 	ftIterator = ftmap.begin();
// 	stdIterator = stdmap.begin();
	
// 	ftIterator = ftmap.erase(ftIterator);
// 	stdIterator = stdmap.erase(stdIterator);
	
// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase one element 1 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase one element 1 (size)");
	
// 	++ftIterator;
// 	++stdIterator;
	
// 	ftIterator = ftmap.erase(ftIterator);
// 	stdIterator = stdmap.erase(stdIterator);
	
// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase one element 2 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase one element 2 (size)");

// 	ftIterator = ftmap.end();
// 	stdIterator = stdmap.end();

// 	--ftIterator;
// 	--stdIterator;
	
// 	ftIterator = ftmap.erase(ftIterator);
// 	stdIterator = stdmap.erase(stdIterator);

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase one element 3 (value)");
// 	compareValues(testNmb++, stdmap.size(), ftmap.size(), "Erase one element 3 (size)");
	
// 	getchar();
// 	std::cout << std::endl;
	
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
	
// 	getchar();
// 	std::system("clear");
// 	return;
// }

// static void non_member_func(void)
// {
// 	int testNmb = 0;
	
// 	std::cout << std::endl << YELLOW << "                              *** Non-member functions overloads ***                          " << NORMAL << std::endl;

// 	ft::map<VALUE_TYPE> ftmap1(200, 21);
// 	ft::map<VALUE_TYPE> ftmap2(200, 21);
// 	ft::map<VALUE_TYPE> ftmap3(100, 12);
	
// 	std::map<VALUE_TYPE> stdmap1(200, 21);
// 	std::map<VALUE_TYPE> stdmap2(200, 21);
// 	std::map<VALUE_TYPE> stdmap3(100, 12);
	
// 	compareValues(testNmb++, stdmap1 == stdmap2, ftmap1 == ftmap2, "Operator== 1");
// 	compareValues(testNmb++, stdmap1 == stdmap3, ftmap1 == ftmap3, "Operator== 2");

// 	compareValues(testNmb++, stdmap1 == stdmap2, ftmap1 == ftmap2, "Operator!= 1");
// 	compareValues(testNmb++, stdmap1 == stdmap3, ftmap1 == ftmap3, "Operator!= 2");

// 	compareValues(testNmb++, stdmap1 < stdmap2, ftmap1 < ftmap2, "Operator< 1");
// 	compareValues(testNmb++, stdmap1 < stdmap3, ftmap1 < ftmap3, "Operator< 2");

// 	compareValues(testNmb++, stdmap1 <= stdmap2, ftmap1 <= ftmap2, "Operator<= 1");
// 	compareValues(testNmb++, stdmap1 <= stdmap3, ftmap1 <= ftmap3, "Operator<= 2");

// 	compareValues(testNmb++, stdmap1 > stdmap2, ftmap1 > ftmap2, "Operator> 1");
// 	compareValues(testNmb++, stdmap1 > stdmap3, ftmap1 > ftmap3, "Operator> 2");

// 	compareValues(testNmb++, stdmap1 >= stdmap2, ftmap1 >= ftmap2, "Operator>= 1");
// 	compareValues(testNmb++, stdmap1 >= stdmap3, ftmap1 >= ftmap3, "Operator>= 2");
	
// 	getchar();
// 	std::cout << std::endl;
	
// // swap

// 	ft::swap(ftmap1, ftmap3);
// 	std::swap(stdmap1, stdmap3);
	
// 	ft::map<VALUE_TYPE>::iterator ftIterator = ftmap1.begin();
// 	std::map<VALUE_TYPE>::iterator stdIterator = stdmap1.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Swap1 (value)");
// 	compareValues(testNmb++, stdmap1.size(), ftmap1.size(), "Swap1 (size)");

// 	ftIterator = ftmap3.begin();
// 	stdIterator = stdmap3.begin();

// 	compareValues(testNmb++, *stdIterator, *ftIterator, "Swap2 (value)");
// 	compareValues(testNmb++, stdmap3.size(), ftmap3.size(), "Swap2 (size)");
	
// 	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
// 	getchar();
// 	std::system("clear");
// 	return;
// }

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
	// iterators();
	// capacity();
	// element_access();
	// modifiers();
	// observers();
	// operations();

	return;
}