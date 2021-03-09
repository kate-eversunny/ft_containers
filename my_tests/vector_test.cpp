/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:04:46 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/09 17:30:33 by pvivian          ###   ########.fr       */
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

	constructor();
	iterators();

	
}