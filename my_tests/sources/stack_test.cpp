/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:20 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/26 15:21:41 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

#define VALUE_TYPE int

static void constructor(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CONSTRUCTOR ***                          " << NORMAL << std::endl;

	ft::stack<VALUE_TYPE> ftStackList;
	std::stack<VALUE_TYPE> stdStackList;

	compareValues(++testNmb, stdStackList.size(), ftStackList.size(), "Constructor list stack (size)");
	compareValues(++testNmb, stdStackList.empty(), ftStackList.empty(), "Constructor list stack (empty)");

	ft::stack<VALUE_TYPE, ft::vector<VALUE_TYPE> > ftStackVector;
	std::stack<VALUE_TYPE, std::vector<VALUE_TYPE> > stdStackVector;

	compareValues(++testNmb, stdStackVector.size(), ftStackVector.size(), "Constructor vector stack (size)");
	compareValues(++testNmb, stdStackVector.empty(), ftStackVector.empty(), "Constructor vector stack (empty)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void capacity(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CAPACITY ***                          " << NORMAL << std::endl;

	ft::stack<VALUE_TYPE> ftStackList;
	std::stack<VALUE_TYPE> stdStackList;

	compareValues(++testNmb, stdStackList.size(), ftStackList.size(), "Size1 list stack");
	compareValues(++testNmb, stdStackList.empty(), ftStackList.empty(), "Empty1 list stack");

	ftStackList.push(42);
	ftStackList.push(42);
	ftStackList.push(42);
	ftStackList.push(42);
	ftStackList.pop();
	ftStackList.push(553);
	
	stdStackList.push(42);
	stdStackList.push(42);
	stdStackList.push(42);
	stdStackList.push(42);
	stdStackList.pop();
	stdStackList.push(553);

	compareValues(++testNmb, stdStackList.size(), ftStackList.size(), "Size2 list stack");
	compareValues(++testNmb, stdStackList.empty(), ftStackList.empty(), "Empty2 list stack");

	getchar();
	std::cout << std::endl;

	ft::stack<VALUE_TYPE, ft::vector<VALUE_TYPE> > ftStackVector;
	std::stack<VALUE_TYPE, std::vector<VALUE_TYPE> > stdStackVector;
	
	compareValues(++testNmb, stdStackVector.size(), ftStackVector.size(), "Size1 vector stack");
	compareValues(++testNmb, stdStackVector.empty(), ftStackVector.empty(), "Empty1 vector stack");

	ftStackVector.push(42);
	ftStackVector.push(42);
	ftStackVector.push(42);
	ftStackVector.push(42);
	ftStackVector.pop();
	ftStackVector.push(553);
	
	stdStackVector.push(42);
	stdStackVector.push(42);
	stdStackVector.push(42);
	stdStackVector.push(42);
	stdStackVector.pop();
	stdStackVector.push(553);

	compareValues(++testNmb, stdStackVector.size(), ftStackVector.size(), "Size2 vector stack");
	compareValues(++testNmb, stdStackVector.empty(), ftStackVector.empty(), "Empty2 vector stack");

	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void element_access(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

	ft::stack<VALUE_TYPE> ftStackList;
	std::stack<VALUE_TYPE> stdStackList;

	ftStackList.push(42);
	ftStackList.push(24);
	ftStackList.push(43);
	ftStackList.push(15);

	stdStackList.push(42);
	stdStackList.push(24);
	stdStackList.push(43);
	stdStackList.push(15);

	compareValues(++testNmb, stdStackList.top(), ftStackList.top(), "Top1 list stack");
	
	ftStackList.pop();
	ftStackList.push(553);
	
	stdStackList.pop();
	stdStackList.push(553);

	compareValues(++testNmb, stdStackList.top(), ftStackList.top(), "Top2 list stack");

	ft::stack<VALUE_TYPE, ft::vector<VALUE_TYPE> > ftStackVector;
	std::stack<VALUE_TYPE, std::vector<VALUE_TYPE> > stdStackVector;

	ftStackVector.push(42);
	ftStackVector.push(33);
	ftStackVector.push(515);
	ftStackVector.push(1048);

	stdStackVector.push(42);
	stdStackVector.push(33);
	stdStackVector.push(515);
	stdStackVector.push(1048);
	
	compareValues(++testNmb, stdStackVector.top(), ftStackVector.top(), "Top1 vector stack");
	
	ftStackVector.pop();
	ftStackVector.push(553);

	stdStackVector.pop();
	stdStackVector.push(553);

	
	compareValues(++testNmb, stdStackVector.top(), ftStackVector.top(), "Top2 vector stack");

	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void modifiers(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Modifiers ***                          " << NORMAL << std::endl;

	ft::stack<VALUE_TYPE> ftStackList;
	std::stack<VALUE_TYPE> stdStackList;

	ftStackList.push(222);
	ftStackList.push(115);
	ftStackList.push(884);
	ftStackList.push(13);

	stdStackList.push(222);
	stdStackList.push(115);
	stdStackList.push(884);
	stdStackList.push(13);
	
	compareValues(++testNmb, stdStackList.top(), ftStackList.top(), "Push list(value)");
	compareValues(++testNmb, stdStackList.size(), ftStackList.size(), "Push list(size)");

	ftStackList.pop();
	ftStackList.pop();
	ftStackList.pop();

	stdStackList.pop();
	stdStackList.pop();
	stdStackList.pop();
	
	compareValues(++testNmb, stdStackList.top(), ftStackList.top(), "Pop1 list(value)");
	compareValues(++testNmb, stdStackList.size(), ftStackList.size(), "Pop1 list(size)");
	
	ftStackList.pop();
	stdStackList.pop();

	compareValues(++testNmb, stdStackList.size(), ftStackList.size(), "Pop2 list(size)");

	std::cout << std::endl;
	getchar();

	ft::stack<VALUE_TYPE, ft::vector<VALUE_TYPE> > ftStackVector;
	std::stack<VALUE_TYPE, std::vector<VALUE_TYPE> > stdStackVector;

	ftStackVector.push(222);
	ftStackVector.push(115);
	ftStackVector.push(884);
	ftStackVector.push(13);

	stdStackVector.push(222);
	stdStackVector.push(115);
	stdStackVector.push(884);
	stdStackVector.push(13);
	
	compareValues(++testNmb, stdStackVector.top(), ftStackVector.top(), "Push vector(value)");
	compareValues(++testNmb, stdStackVector.size(), ftStackVector.size(), "Push vector(size)");

	ftStackVector.pop();
	ftStackVector.pop();
	ftStackVector.pop();

	stdStackVector.pop();
	stdStackVector.pop();
	stdStackVector.pop();
	
	compareValues(++testNmb, stdStackVector.top(), ftStackVector.top(), "Pop1 vector(value)");
	compareValues(++testNmb, stdStackVector.size(), ftStackVector.size(), "Pop1 vector(size)");
	
	ftStackVector.pop();
	stdStackVector.pop();

	compareValues(++testNmb, stdStackVector.size(), ftStackVector.size(), "Pop2 vector(size)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void non_member_func(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Non-member functions overloads ***                          " << NORMAL << std::endl;

	std::cout << GREEN << "List stack" << NORMAL << std::endl;

	ft::stack<VALUE_TYPE> ftStackList1;
	ft::stack<VALUE_TYPE> ftStackList2;
	ft::stack<VALUE_TYPE> ftStackList3;

	ftStackList2.push(213);
	ftStackList3.push(213);
	
	std::stack<VALUE_TYPE> stdStackList1;
	std::stack<VALUE_TYPE> stdStackList2;
	std::stack<VALUE_TYPE> stdStackList3;

	stdStackList2.push(213);
	stdStackList3.push(213);
	
	compareValues(++testNmb, stdStackList1 == stdStackList2, ftStackList1 == ftStackList2, "Operator== 1");
	compareValues(++testNmb, stdStackList1 == stdStackList3, ftStackList1 == ftStackList3, "Operator== 2");

	compareValues(++testNmb, stdStackList1 == stdStackList2, ftStackList1 == ftStackList2, "Operator!= 1");
	compareValues(++testNmb, stdStackList1 == stdStackList3, ftStackList1 == ftStackList3, "Operator!= 2");

	compareValues(++testNmb, stdStackList1 < stdStackList2, ftStackList1 < ftStackList2, "Operator< 1");
	compareValues(++testNmb, stdStackList1 < stdStackList3, ftStackList1 < ftStackList3, "Operator< 2");

	compareValues(++testNmb, stdStackList1 <= stdStackList2, ftStackList1 <= ftStackList2, "Operator<= 1");
	compareValues(++testNmb, stdStackList1 <= stdStackList3, ftStackList1 <= ftStackList3, "Operator<= 2");

	compareValues(++testNmb, stdStackList1 > stdStackList2, ftStackList1 > ftStackList2, "Operator> 1");
	compareValues(++testNmb, stdStackList1 > stdStackList3, ftStackList1 > ftStackList3, "Operator> 2");

	compareValues(++testNmb, stdStackList1 >= stdStackList2, ftStackList1 >= ftStackList2, "Operator>= 1");
	compareValues(++testNmb, stdStackList1 >= stdStackList3, ftStackList1 >= ftStackList3, "Operator>= 2");

	std::cout << std::endl;
	getchar();
	
	std::cout << GREEN << "Vector stack" << NORMAL << std::endl;
	
	ft::stack<VALUE_TYPE> ftStackVector1;
	ft::stack<VALUE_TYPE> ftStackVector2;
	ft::stack<VALUE_TYPE> ftStackVector3;

	ftStackVector2.push(213);
	ftStackVector3.push(213);
	
	std::stack<VALUE_TYPE> stdStackVector1;
	std::stack<VALUE_TYPE> stdStackVector2;
	std::stack<VALUE_TYPE> stdStackVector3;

	stdStackVector2.push(213);
	stdStackVector3.push(213);
	
	compareValues(++testNmb, stdStackVector1 == stdStackVector2, ftStackVector1 == ftStackVector2, "Operator== 1");
	compareValues(++testNmb, stdStackVector1 == stdStackVector3, ftStackVector1 == ftStackVector3, "Operator== 2");

	compareValues(++testNmb, stdStackVector1 == stdStackVector2, ftStackVector1 == ftStackVector2, "Operator!= 1");
	compareValues(++testNmb, stdStackVector1 == stdStackVector3, ftStackVector1 == ftStackVector3, "Operator!= 2");

	compareValues(++testNmb, stdStackVector1 < stdStackVector2, ftStackVector1 < ftStackVector2, "Operator< 1");
	compareValues(++testNmb, stdStackVector1 < stdStackVector3, ftStackVector1 < ftStackVector3, "Operator< 2");

	compareValues(++testNmb, stdStackVector1 <= stdStackVector2, ftStackVector1 <= ftStackVector2, "Operator<= 1");
	compareValues(++testNmb, stdStackVector1 <= stdStackVector3, ftStackVector1 <= ftStackVector3, "Operator<= 2");

	compareValues(++testNmb, stdStackVector1 > stdStackVector2, ftStackVector1 > ftStackVector2, "Operator> 1");
	compareValues(++testNmb, stdStackVector1 > stdStackVector3, ftStackVector1 > ftStackVector3, "Operator> 2");

	compareValues(++testNmb, stdStackVector1 >= stdStackVector2, ftStackVector1 >= ftStackVector2, "Operator>= 1");
	compareValues(++testNmb, stdStackVector1 >= stdStackVector3, ftStackVector1 >= ftStackVector3, "Operator>= 2");

	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void stack_test()
{
	std::cout << GREEN << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         STACK TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << NORMAL;

	constructor();
	capacity();
	element_access();
	modifiers();
	non_member_func();

	return;
}