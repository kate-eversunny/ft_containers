/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:18 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/26 15:21:35 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

#define VALUE_TYPE int

static void constructor(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CONSTRUCTOR ***                          " << NORMAL << std::endl;

	ft::queue<VALUE_TYPE> ftQueueList;
	std::queue<VALUE_TYPE> stdQueueList;

	compareValues(++testNmb, stdQueueList.size(), ftQueueList.size(), "Constructor list queue (size)");
	compareValues(++testNmb, stdQueueList.empty(), ftQueueList.empty(), "Constructor list queue (empty)");
	
	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void capacity(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** CAPACITY ***                          " << NORMAL << std::endl;

	ft::queue<VALUE_TYPE> ftQueueList;
	std::queue<VALUE_TYPE> stdQueueList;

	compareValues(++testNmb, stdQueueList.size(), ftQueueList.size(), "Size1 list queue");
	compareValues(++testNmb, stdQueueList.empty(), ftQueueList.empty(), "Empty1 list queue");

	ftQueueList.push(42);
	ftQueueList.push(42);
	ftQueueList.push(42);
	ftQueueList.push(42);
	ftQueueList.pop();
	ftQueueList.push(553);
	
	stdQueueList.push(42);
	stdQueueList.push(42);
	stdQueueList.push(42);
	stdQueueList.push(42);
	stdQueueList.pop();
	stdQueueList.push(553);

	compareValues(++testNmb, stdQueueList.size(), ftQueueList.size(), "Size2 list queue");
	compareValues(++testNmb, stdQueueList.empty(), ftQueueList.empty(), "Empty2 list queue");

	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void element_access(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

	ft::queue<VALUE_TYPE> ftqueueList;
	std::queue<VALUE_TYPE> stdqueueList;

	ftqueueList.push(42);
	ftqueueList.push(24);
	ftqueueList.push(43);
	ftqueueList.push(15);

	stdqueueList.push(42);
	stdqueueList.push(24);
	stdqueueList.push(43);
	stdqueueList.push(15);

	compareValues(++testNmb, stdqueueList.front(), ftqueueList.front(), "Front1 list queue");
	compareValues(++testNmb, stdqueueList.back(), ftqueueList.back(), "Back1 list queue");
	
	ftqueueList.pop();
	ftqueueList.push(553);
	
	stdqueueList.pop();
	stdqueueList.push(553);

	compareValues(++testNmb, stdqueueList.front(), ftqueueList.front(), "Front2 list queue");
	compareValues(++testNmb, stdqueueList.back(), ftqueueList.back(), "Back2 list queue");

	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void modifiers(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Modifiers ***                          " << NORMAL << std::endl;

	ft::queue<VALUE_TYPE> ftqueueList;
	std::queue<VALUE_TYPE> stdqueueList;

	ftqueueList.push(222);
	ftqueueList.push(115);
	ftqueueList.push(884);
	ftqueueList.push(13);

	stdqueueList.push(222);
	stdqueueList.push(115);
	stdqueueList.push(884);
	stdqueueList.push(13);
	
	compareValues(++testNmb, stdqueueList.front(), ftqueueList.front(), "Push list(front value)");
	compareValues(++testNmb, stdqueueList.back(), ftqueueList.back(), "Push list(back value)");
	compareValues(++testNmb, stdqueueList.size(), ftqueueList.size(), "Push list(size)");

	ftqueueList.pop();
	ftqueueList.pop();
	ftqueueList.pop();

	stdqueueList.pop();
	stdqueueList.pop();
	stdqueueList.pop();
	
	compareValues(++testNmb, stdqueueList.front(), ftqueueList.front(), "Pop list(front value)");
	compareValues(++testNmb, stdqueueList.back(), ftqueueList.back(), "Pop list(back value)");
	compareValues(++testNmb, stdqueueList.size(), ftqueueList.size(), "Pop list(size)");
	
	ftqueueList.pop();
	stdqueueList.pop();

	compareValues(++testNmb, stdqueueList.size(), ftqueueList.size(), "Pop2 list(size)");

	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

static void non_member_func(void)
{
	int testNmb = 0;
	
	std::cout << std::endl << YELLOW << "                              *** Non-member functions overloads ***                          " << NORMAL << std::endl;

	ft::queue<VALUE_TYPE> ftqueueList1;
	ft::queue<VALUE_TYPE> ftqueueList2;
	ft::queue<VALUE_TYPE> ftqueueList3;

	ftqueueList2.push(213);
	ftqueueList3.push(213);
	
	std::queue<VALUE_TYPE> stdqueueList1;
	std::queue<VALUE_TYPE> stdqueueList2;
	std::queue<VALUE_TYPE> stdqueueList3;

	stdqueueList2.push(213);
	stdqueueList3.push(213);
	
	compareValues(++testNmb, stdqueueList1 == stdqueueList2, ftqueueList1 == ftqueueList2, "Operator== 1");
	compareValues(++testNmb, stdqueueList1 == stdqueueList3, ftqueueList1 == ftqueueList3, "Operator== 2");

	compareValues(++testNmb, stdqueueList1 == stdqueueList2, ftqueueList1 == ftqueueList2, "Operator!= 1");
	compareValues(++testNmb, stdqueueList1 == stdqueueList3, ftqueueList1 == ftqueueList3, "Operator!= 2");

	compareValues(++testNmb, stdqueueList1 < stdqueueList2, ftqueueList1 < ftqueueList2, "Operator< 1");
	compareValues(++testNmb, stdqueueList1 < stdqueueList3, ftqueueList1 < ftqueueList3, "Operator< 2");

	compareValues(++testNmb, stdqueueList1 <= stdqueueList2, ftqueueList1 <= ftqueueList2, "Operator<= 1");
	compareValues(++testNmb, stdqueueList1 <= stdqueueList3, ftqueueList1 <= ftqueueList3, "Operator<= 2");

	compareValues(++testNmb, stdqueueList1 > stdqueueList2, ftqueueList1 > ftqueueList2, "Operator> 1");
	compareValues(++testNmb, stdqueueList1 > stdqueueList3, ftqueueList1 > ftqueueList3, "Operator> 2");

	compareValues(++testNmb, stdqueueList1 >= stdqueueList2, ftqueueList1 >= ftqueueList2, "Operator>= 1");
	compareValues(++testNmb, stdqueueList1 >= stdqueueList3, ftqueueList1 >= ftqueueList3, "Operator>= 2");

	std::cout << std::endl << YELLOW << "*** *** *** *** ***" << NORMAL << std::endl;
	
	getchar();
	std::system("clear");
	return;
}

void queue_test()
{
	std::cout << GREEN << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         QUEUE TESTING          |" << std::endl;
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