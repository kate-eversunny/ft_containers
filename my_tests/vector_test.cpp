/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:04:46 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/10 20:42:15 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"
#define VALUE_TYPE int

void constructor(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CONSTRUCTOR ***                          " << NORMAL << std::endl;

	std::vector<VALUE_TYPE>::iterator stdIterator;
	ft::vector<VALUE_TYPE>::iterator ftIterator;

	ft::vector<VALUE_TYPE> ftVectorBlanc;
	std::vector<VALUE_TYPE> stdVectorBlanc;

	compareValues(testNmb++, stdVectorBlanc.size(), ftVectorBlanc.size(), "Constructor vector(size)");

	ft::vector<VALUE_TYPE> ftVector(200, 42);
	std::vector<VALUE_TYPE> stdVector(200, 42);

	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Constructor vector(size)");

	stdIterator = stdVector.begin();
	ftIterator = ftVector.begin();

	compareValues(testNmb++, *stdIterator, *ftIterator, "Constructor vector(value)");

	/*		COPY		*/
	ft::vector<VALUE_TYPE>ftVectorCopy(ftVector);
	std::vector<VALUE_TYPE>stdVectorCopy(stdVector);
	
	compareValues(testNmb++, stdVectorCopy.size(), ftVectorCopy.size(), "Constructor copy (size)");
	
	stdIterator = stdVectorCopy.begin();
	ftIterator = ftVectorCopy.begin();
	
	compareValues(testNmb++, *stdIterator, *ftIterator, "Constructor copy (value)");

	// /*     RANGE     */
	// ft::vector<VALUE_TYPE>ftVectorRange(ftVector.begin(), ftVector.end());
	// std::vector<VALUE_TYPE>stdVectorRange(stdVector.begin(), stdVector.end());

	// compareValues(testNmb++, stdVectorRange.size(), ftVectorRange.size(), "Constructor range (size)");

	// stdIterator = stdVectorRange.begin();
	// ftIterator = ftVectorRange.begin();
	
	// compareValues(testNmb++, *stdIterator, *ftIterator, "Constructor range (value)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void iterators(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ITERATORS ***                          " << NORMAL << std::endl;

	std::vector<VALUE_TYPE>::iterator stdIterator;
	ft::vector<VALUE_TYPE>::iterator ftIterator;

	ft::vector<VALUE_TYPE> ftVector(50, 21);
	ftVector.push_back(42);
	std::vector<VALUE_TYPE> stdVector(50, 21);
	stdVector.push_back(42);

	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();

	compareValues(testNmb++, *stdIterator, *ftIterator, "Begin (value)");
	
	ftIterator = ftVector.end();
	stdIterator = stdVector.end();

	compareValues(testNmb++, *stdIterator, *ftIterator, "End (value)");

	std::vector<VALUE_TYPE>::reverse_iterator stdRevIterator;
	ft::vector<VALUE_TYPE>::reverse_iterator ftRevIterator;

	ftRevIterator = ftVector.rbegin();
	stdRevIterator = stdVector.rbegin();

	compareValues(testNmb++, *stdRevIterator, *ftRevIterator, "Rbegin (value)");
	
	ftRevIterator = ftVector.rend();
	stdRevIterator = stdVector.rend();

	compareValues(testNmb++, *stdRevIterator, *ftRevIterator, "Rend (value)");
	

	// const iterators - need tests
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void capacity(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CAPACITY ***                          " << NORMAL << std::endl;

	ft::vector<VALUE_TYPE> ftVectorBlank;
	std::vector<VALUE_TYPE> stdVectorBlank;
	compareValues(testNmb++, stdVectorBlank.empty(), ftVectorBlank.empty(), "Empty (blank)");

	ft::vector<VALUE_TYPE> ftVector(50, 21);
	ftVector.push_back(42);
	ftVector.push_back(42);
	ftVector.push_back(42);
	ftVector.push_back(42);
	ftVector.pop_back();
	std::vector<VALUE_TYPE> stdVector(50, 21);
	stdVector.push_back(42);
	stdVector.push_back(42);
	stdVector.push_back(42);
	stdVector.push_back(42);
	stdVector.pop_back();
	
	compareValues(testNmb++, stdVector.empty(), ftVector.empty(), "Empty (full)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Size");
	compareValues(testNmb++, stdVector.capacity(), ftVector.capacity(), "Capacity");
	compareValues(testNmb++, stdVector.max_size(), ftVector.max_size(), "Max_size");
	
	ftVector.reserve(100);
	stdVector.reserve(100);
	compareValues(testNmb++, stdVector.capacity(), ftVector.capacity(), "Reserve1 (capacity)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Reserve1 (size)");
	
	ftVector.reserve(20);
	stdVector.reserve(20);
	compareValues(testNmb++, stdVector.capacity(), ftVector.capacity(), "Reserve2 (capacity)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Reserve2 (size)");

	ftVector.resize(200);
	stdVector.resize(200);
	compareValues(testNmb++, stdVector.capacity(), ftVector.capacity(), "Resize1 (capacity)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Resize1 (size)");
	
	ftVector.resize(50);
	stdVector.resize(50);
	compareValues(testNmb++, stdVector.capacity(), ftVector.capacity(), "Resize2 (capacity)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Resize2 (size)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void element_access(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

	ft::vector<VALUE_TYPE> ftVector(200, 21);
	ftVector.push_back(42);
	std::vector<VALUE_TYPE> stdVector(200, 21);
	stdVector.push_back(42);
	
	compareValues(testNmb++, stdVector[100], ftVector[100], "Operator[]1");
	compareValues(testNmb++, stdVector[200], ftVector[200], "Operator[]2");
	
	compareValues(testNmb++, stdVector.at(50), ftVector.at(50), "At (valid index)");
	
	bool stdException = false;
	bool ftException = false;
	try {
		stdVector.at(500);
	}
	catch(const std::exception& e) {
		std::cerr << std::endl << "Std exception: " << e.what() <<std::endl;
		stdException = true;
	}
	try {
		ftVector.at(500);
	}
	catch(const std::exception& e) {
		std::cerr << "Ft exception:  " << e.what() <<std::endl;
		ftException = true;
	}

	compareValues(testNmb++, stdException, ftException, "At (invalid index)");
	
	compareValues(testNmb++, stdVector.front(), ftVector.front(), "Front");
	compareValues(testNmb++, stdVector.back(), ftVector.back(), "Back");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void modifiers(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Modifiers ***                          " << NORMAL << std::endl;

	ft::vector<VALUE_TYPE> ftVector(500, 21);
	ft::vector<VALUE_TYPE> ftVector2(200, 42);
	std::vector<VALUE_TYPE> stdVector(500, 21); // add different values with insert
	std::vector<VALUE_TYPE> stdVector2(200, 42);

	ft::vector<VALUE_TYPE>::iterator ftIterator;
	std::vector<VALUE_TYPE>::iterator stdIterator;
	
	ftVector.swap(ftVector2);
	stdVector.swap(stdVector2);
	
	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();

	compareValues(testNmb++, *stdIterator, *ftIterator, "Swap (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Swap (size)");

	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();
	
	ftIterator = ftVector.erase(ftIterator);
	stdIterator = stdVector.erase(stdIterator);
	
	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase one element 1 (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Erase one element 1 (size)");
	
	++ftIterator;
	++stdIterator;
	
	ftIterator = ftVector.erase(ftIterator);
	stdIterator = stdVector.erase(stdIterator);
	
	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase one element 2 (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Erase one element 2 (size)");

	ftIterator = ftVector.end();
	stdIterator = stdVector.end();

	--ftIterator;
	--stdIterator;
	
	ftIterator = ftVector.erase(ftIterator);
	stdIterator = stdVector.erase(stdIterator);

	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase one element 3 (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Erase one element 3 (size)");
	
	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();

	++ftIterator;
	++stdIterator;
	
	ftIterator = ftVector.erase(ftIterator, ftIterator + 5);
	stdIterator = stdVector.erase(stdIterator, stdIterator + 5);

	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase range of elements 1 (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Erase range of elements 1  (size)");

	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();
	
	ftIterator = ftVector.erase(ftIterator, ftIterator + 5);
	stdIterator = stdVector.erase(stdIterator, stdIterator + 5);

	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase range of elements 2 (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Erase range of elements 2  (size)");

	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();
	
	ftIterator = ftVector.erase(ftIterator, ftVector.end());
	stdIterator = stdVector.erase(stdIterator, stdVector.end());

	compareValues(testNmb++, *stdIterator, *ftIterator, "Erase range of elements 3 (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Erase range of elements 3  (size)");

	ftVector.push_back(42);
	ftVector.push_back(42);
	stdVector.push_back(42);
	stdVector.push_back(42);

	ftVector.clear();
	stdVector.clear();

	ftIterator = ftVector.begin();
	stdIterator = stdVector.begin();

	compareValues(testNmb++, *stdIterator, *ftIterator, "Clear (value)");
	compareValues(testNmb++, stdVector.size(), ftVector.size(), "Clear (size)");
	compareValues(testNmb++, stdVector.capacity(), ftVector.capacity(), "Clear (capacity)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void vector_test()
{
	std::cout << GREEN << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         VECTOR TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << NORMAL;

	// constructor();
	// iterators();
	// capacity();
	// element_access();
	modifiers();

	
}