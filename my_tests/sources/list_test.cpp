/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:13 by gbroccol          #+#    #+#             */
/*   Updated: 2021/06/13 16:00:54 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

#define VALUE_TYPE int

static void	constructor(void)
{
	size_t testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CONSTRUCTOR ***                          " << NORMAL << std::endl;

	ft::list  <VALUE_TYPE> ftListBlanc;
	std::list <VALUE_TYPE> stdListBlanc;

	compareValues(++testNmb, stdListBlanc.size(), ftListBlanc.size(), "Constructor default (size)");
	compareContainers(++testNmb, stdListBlanc, ftListBlanc, "Constructor default (value)");

	ft::list  <VALUE_TYPE> ftList((size_t)10, 42);
	std::list <VALUE_TYPE> stdList((size_t)10, 42);

	compareValues(++testNmb, stdList.size(), ftList.size(), "Constructor (size)");
	compareContainers(++testNmb, stdList, ftList, "Constructor (value)");

	ft::list  <VALUE_TYPE> ftListCopy(ftList);
	std::list <VALUE_TYPE> stdListCopy(stdList);
	
	compareValues(++testNmb, stdListCopy.size(), ftListCopy.size(), "Constructor copy (size)");
	compareContainers(++testNmb, stdListCopy, ftListCopy, "Constructor copy (value)");
	
	ft::list  <VALUE_TYPE> ftListrange(ftList.begin(), ftList.end());
	std::list <VALUE_TYPE> stdListrange(stdList.begin(), stdList.end());
	
	compareValues(++testNmb, stdListrange.size(), ftListrange.size(), "Constructor range (size)");
	compareContainers(++testNmb, stdListrange, ftListrange, "Constructor copy (value)");

	ftList = ftListBlanc;
	stdList = stdListBlanc;

	compareValues(++testNmb, stdList.size(), ftList.size(), "Operator= (size)");
	compareContainers(++testNmb, stdList, ftList, "Operator= (value)");
}

static void	iterators(void)
{
	size_t testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                         *** ITERATORS ***                          " << NORMAL << std::endl;
	
	std::list<VALUE_TYPE>::iterator stdIterator;
	ft::list<VALUE_TYPE>::iterator ftIterator;


	std::list<VALUE_TYPE> stdlist;
	for (size_t i = 0; i < 20; i++)
		stdlist.push_back(i + 5);

	ft::list<VALUE_TYPE> ftlist;
	for (int i = 0; i < 20; i++)
		ftlist.push_back(i + 5);

	ftIterator = ftlist.begin();
	stdIterator = stdlist.begin();

	compareValues(++testNmb, *stdIterator, *ftIterator, "Begin (value)");
	
	ftIterator = ftlist.end();
	stdIterator = stdlist.end();

	ftIterator--;
	stdIterator--;

	compareValues(++testNmb, *stdIterator, *ftIterator, "End (value)");

	std::list<VALUE_TYPE>::reverse_iterator stdRevIterator;
	ft::list<VALUE_TYPE>::reverse_iterator ftRevIterator;

	ftRevIterator = ftlist.rbegin();
	stdRevIterator = stdlist.rbegin();

	compareValues(++testNmb, *stdRevIterator, *ftRevIterator, "Rbegin (value)");
	
	ftRevIterator = ftlist.rend();
	stdRevIterator = stdlist.rend();

	--ftRevIterator;
	--stdRevIterator;
	
	compareValues(++testNmb, *stdRevIterator, *ftRevIterator, "Rend (value)");
	
	compareContainers(++testNmb, stdlist, ftlist, "Iterator (all values)");
}

static void	capacity(void)
{
	size_t testNmb = 0;

	std::cout << std::endl << YELLOW << "                                 *** SIZE ***                          " << NORMAL << std::endl;
	
	ft::list <VALUE_TYPE> ftlist;
	std::list <VALUE_TYPE> stdlist;
	
	compareValues(++testNmb, ftlist.empty(), stdlist.empty(), "Empty list - true");
	compareValues(++testNmb, ftlist.size(), stdlist.size(), "Size 1");
	
	ftlist.push_front(10);
	stdlist.push_front(10);
	compareValues(++testNmb, ftlist.empty(), stdlist.empty(), "Empty list - false");
	compareValues(++testNmb, ftlist.size(), stdlist.size(), "Size 2 test");

	ftlist.push_back(11);
	stdlist.push_back(11);
	compareValues(++testNmb, ftlist.size(), stdlist.size(), "Size 3");

	ftlist.push_front(9);
	stdlist.push_front(9);
	compareValues(++testNmb, ftlist.size(), stdlist.size(), "Size 4");

	compareValues(++testNmb, ftlist.max_size(), stdlist.max_size(), "Max_size");
}

static void	elementAccess(void)
{
	size_t testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

	ft::list  <VALUE_TYPE> ftlist((size_t)10, 42);
	std::list <VALUE_TYPE> stdlist((size_t)10, 42);

	ftlist.push_front(11111111);
	stdlist.push_front(11111111);

	ftlist.push_back(22222222);
	stdlist.push_back(22222222);
	
	compareValues(++testNmb, stdlist.front(), ftlist.front(), "Front value is");
	compareValues(++testNmb, stdlist.back(), ftlist.back(), "Back value is");

	compareContainers(++testNmb, stdlist, ftlist, "Compare all values");
}

static void	modifiers(void)
{
	size_t testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** MODIFIERS ***                          " << NORMAL << std::endl;

	ft::list<VALUE_TYPE> ftlist((size_t)10, 42);
	std::list<VALUE_TYPE> stdlist((size_t)10, 42);

	std::list<VALUE_TYPE> empty;
	ft::list<VALUE_TYPE> ftempty;
	std::list<VALUE_TYPE> temp(80, 12);

//assign
	std::cout << std::endl << YELLOW << "assign" << NORMAL << std::endl;

	ftlist.assign(5, 21);
	stdlist.assign(5, 21);
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Assign 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Assign 1 (values)");

	ftlist.assign(empty.begin(), empty.end());
	stdlist.assign(empty.begin(), empty.end());
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Assign 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Assign 2 (values)");

	ftlist.assign(temp.begin(), temp.end());
	stdlist.assign(temp.begin(), temp.end());
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Assign 3 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Assign 3 (values)");
	
	std::cout << std::endl;

//insert
	std::cout << std::endl << YELLOW << "insert" << NORMAL << std::endl;

	stdlist.clear();
	ftlist.clear();

	std::list<VALUE_TYPE>::iterator sit = stdlist.insert(stdlist.begin(), 5);
	ft::list<VALUE_TYPE>::iterator fit = ftlist.insert(ftlist.begin(), 5);

	compareValues(++testNmb, *sit, *fit, "Insert 1 (return value)");
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Insert 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Insert 1 (values)");

	stdlist.insert(stdlist.begin(), 3, 7);
	ftlist.insert(ftlist.begin(), 3, 7);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Insert 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Insert 2 (values)");
	
	empty.insert(empty.begin(), temp.begin(), temp.end());
	ftempty.insert(ftempty.begin(), temp.begin(), temp.end());

	compareValues(++testNmb, empty.size(), ftempty.size(), "Insert 3 (size)");
	compareContainers(++testNmb, empty, ftempty, "Insert 3 (values)");
	
	std::cout << std::endl;

//erase
	std::cout << std::endl << YELLOW << "erase" << NORMAL << std::endl;
  
	sit = stdlist.erase(stdlist.begin());
	fit = ftlist.erase(ftlist.begin());

	compareValues(++testNmb, *sit, *fit, "Erase 1 (return value)");
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Erase 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Erase 1 (values)");

	sit = stdlist.erase(stdlist.begin(), stdlist.begin());
	fit = ftlist.erase(ftlist.begin(), ftlist.begin());

	compareValues(++testNmb, *sit, *fit, "Erase 2 (return value)");
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Erase 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Erase 2 (values)");

	sit = stdlist.erase(stdlist.begin(), stdlist.end());
	fit = ftlist.erase(ftlist.begin(), ftlist.end());

	compareValues(++testNmb, *sit, *fit, "Erase 3 (return value)");
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Erase 3 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Erase 3 (values)");

	std::cout << std::endl;
	
//swap
	std::cout << std::endl << YELLOW << "swap" << NORMAL << std::endl;

	std::list<VALUE_TYPE> empty2;
	std::list<VALUE_TYPE> stdtemp;
	ft::list<VALUE_TYPE> ftempty2;
	ft::list<VALUE_TYPE> fttemp;

	for (size_t i = 0; i < 300; i++)
	{
		stdlist.push_back(i);
		ftlist.push_back(i);
	}

	stdlist.swap(empty2);
	ftlist.swap(ftempty2);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Swap 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Swap 1 (values)");

	compareValues(++testNmb, empty2.size(), ftempty2.size(), "Swap 2 (size)");
	compareContainers(++testNmb, empty2, ftempty2, "Swap 2 (values)");

	for (size_t i = 0; i < 300; i++)
	{
		stdlist.push_back(i);
		ftlist.push_back(i);
	}

	for (size_t i = 100; i < 300; i++)
	{
		stdtemp.push_back(i);
		fttemp.push_back(i);
	}

	stdlist.swap(stdtemp);
	ftlist.swap(fttemp);
	
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Swap 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Swap 1 (values)");

	compareValues(++testNmb, stdtemp.size(), fttemp.size(), "Swap 2 (size)");
	compareContainers(++testNmb, stdtemp, fttemp, "Swap 2 (values)");

//resize
	std::cout << std::endl << YELLOW << "resize" << NORMAL << std::endl;
	
	stdlist.clear();
	ftlist.clear();

	stdlist.resize(300, 9);
	ftlist.resize(300, 9);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Resize 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Resize 1 (values)");

	empty2.resize(300, 9);
	ftempty2.resize(300, 9);

	compareValues(++testNmb, empty2.size(), ftempty2.size(), "Resize 2 (size)");
	compareContainers(++testNmb, empty2, ftempty2, "Resize 2 (values)");

	stdlist.resize(3, 7);
	ftlist.resize(3, 7);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Resize 3 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Resize 3 (values)");

//pop_back
	std::cout << std::endl << YELLOW << "pop_back" << NORMAL << std::endl;

	stdlist.pop_back();
	ftlist.pop_back();

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Pop_back (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Pop_back (values)");

//pop_front
	std::cout << std::endl << YELLOW << "pop_front" << NORMAL << std::endl;

	stdlist.pop_front();
	ftlist.pop_front();

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Pop_front (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Pop_front (values)");

//push_back
	std::cout << std::endl << YELLOW << "push_back" << NORMAL << std::endl;
	std::list<VALUE_TYPE> empty3;
	ft::list<VALUE_TYPE> ftempty3;
	
	empty3.push_back(222);
	empty3.push_back(333);
	ftempty3.push_back(222);
	ftempty3.push_back(333);

	compareValues(++testNmb, empty3.size(), ftempty3.size(), "Push_back 1 (size)");
	compareContainers(++testNmb, empty3, ftempty3, "Push_back 1 (values)");

	stdlist.push_back(222);
	stdlist.push_back(333);
	ftlist.push_back(222);
	ftlist.push_back(333);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Push_back 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Push_back 2 (values)");

//push_front
	std::cout << std::endl << YELLOW << "push_front" << NORMAL << std::endl;
	
	std::list<VALUE_TYPE> empty4;
	ft::list<VALUE_TYPE> ftempty4;

	empty4.push_front(222);
	empty4.push_front(444);
	ftempty4.push_front(222);
	ftempty4.push_front(444);

	compareValues(++testNmb, empty4.size(), ftempty4.size(), "Push_front 1 (size)");
	compareContainers(++testNmb, empty4, ftempty4, "Push_front 1 (values)");

	stdlist.push_front(222);
	stdlist.push_front(444);
	ftlist.push_front(222);
	ftlist.push_front(444);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Push_front 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Push_front 2 (values)");

//clear
	std::cout << std::endl << YELLOW << "clear" << NORMAL << std::endl;
	
	std::list<VALUE_TYPE> empty5;
	ft::list<VALUE_TYPE> ftempty5;

	empty5.clear();
	ftempty5.clear();

	compareValues(++testNmb, empty5.size(), ftempty5.size(), "Clear 1 (size)");
	compareContainers(++testNmb, empty5, ftempty5, "Clear 1 (values)");

	stdlist.clear();
	ftlist.clear();

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Clear 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Clear 2 (values)");
}

static void	operations(void)
{
	size_t testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** OPERATIONS ***                          " << NORMAL << std::endl;

//splice
	std::cout << std::endl << YELLOW << "splice" << NORMAL << std::endl;

	std::list <VALUE_TYPE> stdlistSplice1;
	ft::list <VALUE_TYPE> ftlistSplice1;

	for (int i = 0; i < 100; i++)
	{
		stdlistSplice1.push_back(i);
		ftlistSplice1.push_back(i);
	}

	std::list <VALUE_TYPE> stdlistSplice2;
	ft::list <VALUE_TYPE> ftlistSplice2;

	for (int i = 100; i < 200; i++)
	{
		stdlistSplice2.push_back(i);
		ftlistSplice2.push_back(i);
	}

	stdlistSplice1.splice(stdlistSplice1.begin(), stdlistSplice2);
	ftlistSplice1.splice(ftlistSplice1.begin(), ftlistSplice2);

	compareValues(++testNmb, stdlistSplice1.size(), ftlistSplice1.size(), "Splice 1 (size)");
	compareContainers(++testNmb, stdlistSplice1, ftlistSplice1, "Splice 1 (values)");

	compareValues(++testNmb, stdlistSplice2.size(), ftlistSplice2.size(), "Splice 2 (size)");
	compareContainers(++testNmb, stdlistSplice2, ftlistSplice2, "Splice 2 (values)");

	stdlistSplice1.clear();
	ftlistSplice1.clear();

	for (int i = 0; i < 100; i++)
	{
		stdlistSplice1.push_back(i);
		ftlistSplice1.push_back(i);
	}

	stdlistSplice2.clear();
	ftlistSplice2.clear();

	for (int i = 100; i < 200; i++)
	{
		stdlistSplice2.push_back(i);
		ftlistSplice2.push_back(i);
	}

	stdlistSplice1.splice(stdlistSplice1.begin(), stdlistSplice2, stdlistSplice2.begin());
	ftlistSplice1.splice(ftlistSplice1.begin(), ftlistSplice2, ftlistSplice2.begin());

	compareValues(++testNmb, stdlistSplice1.size(), ftlistSplice1.size(), "Splice 3 (size)");
	compareContainers(++testNmb, stdlistSplice1, ftlistSplice1, "Splice 3 (values)");

	compareValues(++testNmb, stdlistSplice2.size(), ftlistSplice2.size(), "Splice 4 (size)");
	compareContainers(++testNmb, stdlistSplice2, ftlistSplice2, "Splice 4 (values)");

	stdlistSplice1.clear();
	ftlistSplice1.clear();

	for (int i = 0; i < 100; i++)
	{
		stdlistSplice1.push_back(i);
		ftlistSplice1.push_back(i);
	}

	stdlistSplice2.clear();
	ftlistSplice2.clear();

	for (int i = 100; i < 200; i++)
	{
		stdlistSplice2.push_back(i);
		ftlistSplice2.push_back(i);
	}

	stdlistSplice1.splice(stdlistSplice1.begin(), stdlistSplice2, ++stdlistSplice2.begin(), stdlistSplice2.end());
	ftlistSplice1.splice(ftlistSplice1.begin(), ftlistSplice2, ++ftlistSplice2.begin(), ftlistSplice2.end());

	compareValues(++testNmb, stdlistSplice1.size(), ftlistSplice1.size(), "Splice 5 (size)");
	compareContainers(++testNmb, stdlistSplice1, ftlistSplice1, "Splice 5 (values)");

	compareValues(++testNmb, stdlistSplice2.size(), ftlistSplice2.size(), "Splice 6 (size)");
	compareContainers(++testNmb, stdlistSplice2, ftlistSplice2, "Splice 6 (values)");

	std::list<VALUE_TYPE> empty;
	ft::list<VALUE_TYPE> ftempty;

	stdlistSplice1.splice(stdlistSplice1.begin(), empty);
	ftlistSplice1.splice(ftlistSplice1.begin(), ftempty);
	
	compareValues(++testNmb, stdlistSplice1.size(), ftlistSplice1.size(), "Splice 7 (size)");
	compareContainers(++testNmb, stdlistSplice1, ftlistSplice1, "Splice 7 (values)");

	compareValues(++testNmb, empty.size(), ftempty.size(), "Splice 8 (size)");
	compareContainers(++testNmb, empty, ftempty, "Splice 8 (values)");

//remove
	std::cout << std::endl << YELLOW << "remove" << NORMAL << std::endl;
	
	std::list <VALUE_TYPE> stdlist;
	ft::list <VALUE_TYPE> ftlist;

	for (int i = 0; i < 100; i++)
	{
		stdlist.push_back(i);
		ftlist.push_back(i);
	}
	
	stdlist.remove(50);
	ftlist.remove(50);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Remove 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Remove 1 (values)");
	
	stdlist.remove(1000);
	ftlist.remove(1000);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Remove 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Remove 2 (values)");
	
//remove_if
	std::cout << std::endl << YELLOW << "remove if" << NORMAL << std::endl;

	stdlist.remove_if(ft_is_odd<VALUE_TYPE>());
	ftlist.remove_if(ft_is_odd<VALUE_TYPE>());

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Remove_if (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Remove_if (values)");

//remove_if
	std::cout << std::endl << YELLOW << "remove if" << NORMAL << std::endl;

	stdlist.remove_if(ft_is_odd<VALUE_TYPE>());
	ftlist.remove_if(ft_is_odd<VALUE_TYPE>());

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Remove_if (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Remove_if (values)");

//unique
	std::cout << std::endl << YELLOW << "unique" << NORMAL << std::endl;

	for (int i = 0; i < 50; i++)
	{
		stdlist.push_back(1);
		ftlist.push_back(1);
	}
	
	stdlist.unique();
	ftlist.unique();

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Unique 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Unique 1 (values)");
	
	stdlist.unique(ft_is_near<VALUE_TYPE>());
	ftlist.unique(ft_is_near<VALUE_TYPE>());
	
	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Unique 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Unique 2 (values)");
	
//merge
	std::cout << std::endl << YELLOW << "merge" << NORMAL << std::endl;

	for (int i = 0; i < 50; i++)
	{
		stdlist.push_back(i);
		ftlist.push_back(i);
	}

	stdlist.merge(empty);
	ftlist.merge(ftempty);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Merge 1 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Merge 1 (values)");

	std::list <VALUE_TYPE> stdlist2;
	ft::list <VALUE_TYPE> ftlist2;

	for (int i = 0; i < 100; i++)
	{
		stdlist2.push_back(i);
		ftlist2.push_back(i);
	}

	stdlist.merge(stdlist2);
	ftlist.merge(ftlist2);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Merge 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Merge 2 (values)");
	compareValues(++testNmb, stdlist2.size(), ftlist2.size(), "Merge 3 (size)");
	compareContainers(++testNmb, stdlist2, ftlist2, "Merge 3 (values)");

	for (int i = 100; i < 200; i++)
	{
		stdlist2.push_back(i);
		ftlist2.push_back(i);
	}

	stdlist.merge(stdlist2, mycomparison<VALUE_TYPE>);
	ftlist.merge(ftlist2, mycomparison<VALUE_TYPE>);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Merge 4 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Merge 4 (values)");
	compareValues(++testNmb, stdlist2.size(), ftlist2.size(), "Merge 5 (size)");
	compareContainers(++testNmb, stdlist2, ftlist2, "Merge 5 (values)");
	

//sort
	std::cout << std::endl << YELLOW << "sort" << NORMAL << std::endl;

	empty.sort();
	ftempty.sort();
	
	compareValues(++testNmb, empty.size(), ftempty.size(), "Sort 1 (size)");
	compareContainers(++testNmb, empty, ftempty, "Sort 1 (values)");

	stdlist.sort();
	ftlist.sort();

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Sort 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Sort 2 (values)");

	stdlist.sort(mycomparison2<VALUE_TYPE>);
	ftlist.sort(mycomparison2<VALUE_TYPE>);

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Sort 3 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Sort 3 (values)");

//reverse
	std::cout << std::endl << YELLOW << "reverse" << NORMAL << std::endl;
	
	empty.reverse();
	ftempty.reverse();
	
	compareValues(++testNmb, empty.size(), ftempty.size(), "Reverse 1 (size)");
	compareContainers(++testNmb, empty, ftempty, "Reverse 1 (values)");

	stdlist.reverse();
	ftlist.reverse();

	compareValues(++testNmb, stdlist.size(), ftlist.size(), "Reverse 2 (size)");
	compareContainers(++testNmb, stdlist, ftlist, "Reverse 2 (values)");
}

static void non_member_func(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Non-member functions overloads ***                          " << NORMAL << std::endl;

	std::list<VALUE_TYPE> stdlist1;
	for (size_t i = 0; i < 300; i++)
		stdlist1.push_back(i + 10);

	std::list<VALUE_TYPE> stdlist2;
	for (size_t i = 0; i < 300; i++)
		stdlist2.push_back(i + 10);

	std::list<VALUE_TYPE> stdlist3;
	for (size_t i = 0; i < 100; i++)
		stdlist3.push_back(i + 11);

	ft::list<VALUE_TYPE> ftlist1;
	for (int i = 0; i < 300; i++)
		ftlist1.push_back(i + 10);

	ft::list<VALUE_TYPE> ftlist2;
	for (int i = 0; i < 300; i++)
		ftlist2.push_back(i + 10);

	ft::list<VALUE_TYPE> ftlist3;
	for (size_t i = 0; i < 100; i++)
		ftlist3.push_back(i + 11);
	
	compareValues(++testNmb, stdlist1 == stdlist2, ftlist1 == ftlist2, "Operator== 1");
	compareValues(++testNmb, stdlist1 == stdlist3, ftlist1 == ftlist3, "Operator== 2");

	compareValues(++testNmb, stdlist1 == stdlist2, ftlist1 == ftlist2, "Operator!= 1");
	compareValues(++testNmb, stdlist1 == stdlist3, ftlist1 == ftlist3, "Operator!= 2");

	compareValues(++testNmb, stdlist1 < stdlist2, ftlist1 < ftlist2, "Operator< 1");
	compareValues(++testNmb, stdlist1 < stdlist3, ftlist1 < ftlist3, "Operator< 2");

	compareValues(++testNmb, stdlist1 <= stdlist2, ftlist1 <= ftlist2, "Operator<= 1");
	compareValues(++testNmb, stdlist1 <= stdlist3, ftlist1 <= ftlist3, "Operator<= 2");

	compareValues(++testNmb, stdlist1 > stdlist2, ftlist1 > ftlist2, "Operator> 1");
	compareValues(++testNmb, stdlist1 > stdlist3, ftlist1 > ftlist3, "Operator> 2");

	compareValues(++testNmb, stdlist1 >= stdlist2, ftlist1 >= ftlist2, "Operator>= 1");
	compareValues(++testNmb, stdlist1 >= stdlist3, ftlist1 >= ftlist3, "Operator>= 2");
	
// swap

	ft::swap(ftlist1, ftlist3);
	std::swap(stdlist1, stdlist3);

	compareContainers(++testNmb, stdlist1, ftlist1, "Swap1 (value)");
	compareValues(++testNmb, stdlist1.size(), ftlist1.size(), "Swap1 (size)");

	compareContainers(++testNmb, stdlist3, ftlist3, "Swap2 (value)");
	compareValues(++testNmb, stdlist3.size(), ftlist3.size(), "Swap2 (size)");
	return;
}

static void various_types(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** VARIOUS TYPES of DATA ***                          " << NORMAL << std::endl;
	
	std::string str1("Hello friend");
	std::string str2("Bebebebe");

	std::list<std::string> stdlist1(20, str1);
	ft::list<std::string> ftlist1(20, str1);

	stdlist1.push_back(str2);
	ftlist1.push_back(str2);
	stdlist1.push_back(str2);
	ftlist1.push_back(str2);
	compareContainers(++testNmb, stdlist1, ftlist1, "Std:string");

	float f = 1.234;

	std::vector<float> vectorData(15, f);
	std::list<std::vector<float> > stdlist2(20, vectorData);
	ft::list<std::vector<float> > ftlist2(20, vectorData);
	compareContainers(++testNmb, stdlist2, ftlist2, "Class");
	
	char a = 'a';
	std::list<char> stdlist3(20, a);
	ft::list<char> ftlist3(20, a);
	compareContainers(++testNmb, stdlist3, ftlist3, "Char");


	std::list<const float> stdlist4(20, f);
	ft::list<const float> ftlist4(20, f);
	compareContainers(++testNmb, stdlist4, ftlist4, "Const float");
	
}

void	list_test()
{
	std::cout << YELLOW << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          LIST TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << NORMAL;
	
	/*			Member functions			*/

	constructor();
	iterators();
	capacity();
	elementAccess();
	modifiers();
	operations();
	non_member_func();
	various_types();
}
