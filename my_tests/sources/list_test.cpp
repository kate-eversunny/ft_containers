/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:13 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/26 15:21:50 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

void	capacity(int testNmb)
{
	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	std::list <int> :: iterator sysData;
	ft::list <int> :: iterator userData = testMyList.begin(); // delete  = testMyList.begin()

	std::cout << std::endl << YELLOW << "                                 *** SIZE ***                          " << NORMAL << std::endl;
	
	compareValues(++testNmb, testMyList.empty(), testOriginalList.empty(), "Empty list - true");

	compareValues(++testNmb, testMyList.size(), testOriginalList.size(), "Size test free list");
	
	testMyList.push_front(10);
	testOriginalList.push_front(10);
	compareValues(++testNmb, testMyList.size(), testOriginalList.size(), "Size test");

	compareValues(++testNmb, testMyList.empty(), testOriginalList.empty(), "Empty list - false");

	testMyList.push_back(11);
	testOriginalList.push_back(11);
	compareValues(++testNmb, testMyList.size(), testOriginalList.size(), "Size test free list");

	testMyList.push_front(9);
	testOriginalList.push_front(9);
	compareValues(++testNmb, testMyList.size(), testOriginalList.size(), "Size test free list");

	
	/*		Size of list CHAR		*/
	std::cout << std::endl << YELLOW << "Size of list CHAR" << NORMAL << std::endl;
	
	ft::list <char> userListChar;
	std::list <char> sysListChar;
	
	for (int i = 0; i < 33; i++)
	{
		sysListChar.push_back('a');			
		userListChar.push_back('a');
	}

	std::list <char> :: iterator sysIteratorChar = sysListChar.begin();
	ft::list <char> :: iterator userIteratorChar  = userListChar.begin();

	for (int i = 0; i < 33; i++)
	{
		sysIteratorChar++;
		userIteratorChar++;
	}
	compareValues(++testNmb, userListChar.size(), userListChar.size(), "Size is <char>");
	// compareValues(++testNmb, *sysIteratorChar, *userIteratorChar, "Size of list <char>");
	getchar();
	std::system("clear");
}

void	operators(int testNmb)
{
	std::cout << std::endl << YELLOW << "                         *** VALUES AND OPERATORS ***                          " << NORMAL << std::endl;

	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	std::list <int> :: iterator sysData;
	ft::list <int> :: iterator userData = testMyList.begin(); // delete  = testMyList.begin()

	try
	{
		ft::list  <int> testMyListTest;
		std::list <int> testOriginalListTest;

		std::list <int> :: iterator sysDataTest = testOriginalListTest.begin();
		ft::list <int> :: iterator userDataTest = testMyListTest.begin();

		compareValues(++testNmb, *sysDataTest, *userDataTest, "Operators test *a");

		sysDataTest++;
		userDataTest++;
		compareValues(++testNmb, *sysDataTest, *userDataTest, "Operators test a++");

		sysDataTest--;
		userDataTest--;
		compareValues(++testNmb, *sysDataTest, *userDataTest, "Operators test a--");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	compareValues(++testNmb, *sysData, *userData, "Operators test *a");

	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	sysData++;
	userData++;
	compareValues(++testNmb, *sysData, *userData, "Operators test a++");

	sysData++;
	userData++;
	compareValues(++testNmb, *sysData, *userData, "Operators test a++");

	sysData++;
	userData++;
	sysData++;
	userData++;
	compareValues(++testNmb, *sysData, *userData, "Operators test a++");

	// // sysData = testOriginalList.begin();
	// // userData = testMyList.begin();
	// // sysData++;
	// // itML02++;
	// std::cout << LIGHT_BLUE << ++testNmb << ". Begin value test ++a ...................................... " << NORMAL;
	// // if (*sysData == *itML02)
	// // {
	// // 	std::cout << GREEN << "OK" << NORMAL << std::endl;
	// // 	std::cout << std::setw(69) << "Answer: " << *sysData << std::endl;
	// // }
	// // else
	// 	std::cout << RED << "NO TEST" << NORMAL << std::endl;

	testOriginalList.push_back(5); 
	testOriginalList.push_back(4);
	testMyList.push_back(5);      // can be incorrect if push_back doesn't work
	testMyList.push_back(4);
	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	++sysData;
	++userData;
	compareValues(++testNmb, *sysData, *userData, "Begin value test ++a");
	
	sysData = testOriginalList.end();
	userData = testMyList.end();
	sysData--;
	userData--;
	compareValues(++testNmb, *sysData, *userData, "End value test a--");

	// // sysData = testOriginalList.end();
	// // userData = testMyList.end();
	// // sysData--;
	// // userData--;
	// std::cout << LIGHT_BLUE << ++testNmb << ". End value test --a ...................................... " << NORMAL;
	// // if (*itTOL == *userData)
	// // {
	// // 	std::cout << GREEN << "OK" << NORMAL << std::endl;
	// // 	std::cout << std::setw(69) << "Answer: " << *itTOL << std::endl;
	// // }
	// // else
	// // {
	// 	std::cout << RED << "NO TEST" << NORMAL << std::endl;
	// // 	std::cout << std::setw(69) << "Expected answer: " << *itTOL << std::endl;
	// // 	std::cout << std::setw(69) << "Your answer: " << *userData << std::endl;
	// // }

	sysData = testOriginalList.end();
	userData = testMyList.end();
	--sysData;
	--userData;
	compareValues(++testNmb, *sysData, *userData, "End value test --a");
	
	// try
	// {
	// 	ft::list <int> testMyList1;
	// 	std::list <int> testOriginalList1;

	// 	testMyList1.push_front(55);
	// 	testOriginalList1.push_front(55);
		
	// 	sysData = testOriginalList.end();
	// 	userData = testMyList.end();
		
	// 	sysData = testOriginalList.begin();
	// 	userData = testMyList.begin();

		std::cout << LIGHT_BLUE << ++testNmb << ". End value test a=b ...................................... " << NORMAL;
	// 	if (*sysData == *userData)
	// 	{
	// 		std::cout << GREEN << "OK" << NORMAL << std::endl;
	// 		std::cout << std::setw(69) << "Answer: " << *sysData << std::endl;
	// 	}
	// 	else
	// 	{
			std::cout << RED << "NO TEST" << NORMAL << std::endl;
	// 		std::cout << std::setw(69) << "Expected answer: " << *sysData << std::endl;
	// 		std::cout << std::setw(69) << "Your answer: " << *userData << std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	getchar();
	std::system("clear");
}

void	constructor(int testNmb)
{
	std::cout << std::endl << YELLOW << "                              *** CONSTRUCTOR ***                          " << NORMAL << std::endl;

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	compareValues(++testNmb, sysList.size(), userList.size(), "Constructor list(size, value)");

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	compareValues(++testNmb, *sysIterator, *userIterator, "Constructor list(size, value)");

	/*		COPY		*/
	ft::list  <int> userListCopy(userList);
	std::list <int> sysListCopy(sysList);
	compareValues(++testNmb, sysListCopy.size(), userListCopy.size(), "Constructor copy");
	
	sysIterator = sysListCopy.begin();
	userIterator = userListCopy.begin();
	
	compareValues(++testNmb, *sysIterator, *userIterator, "Constructor copy - value");

	userList.push_front(0);
	sysList.push_front(0);

	sysIterator = sysList.begin();
	userIterator = userList.begin();

	compareValues(++testNmb, *sysIterator, *userIterator, "Front value is");

	userList.push_back(50);
	sysList.push_back(50);

	sysIterator = sysList.end();
	userIterator = userList.end();

	sysIterator--;
	userIterator--;

	compareValues(++testNmb, *sysIterator, *userIterator, "Back value is");

	userList.pop_front();
	sysList.pop_front();

	sysIterator = sysList.begin();
	userIterator = userList.begin();

	compareValues(++testNmb, *sysIterator, *userIterator, "Front value is");

	userList.pop_back();
	sysList.pop_back();

	sysIterator = sysList.end();
	userIterator = userList.end();

	sysIterator--;
	userIterator--;

	compareValues(++testNmb, *sysIterator, *userIterator, "Back value is");
	getchar();
	std::system("clear");
}

void	elementAccess(int testNmb)
{
	std::cout << std::endl << YELLOW << "                              *** ELEMENT ACCESS ***                          " << NORMAL << std::endl;

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	userList.push_front(11111111);
	sysList.push_front(11111111);

	userList.push_back(22222222);
	sysList.push_back(22222222);
	
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is");
	
	getchar();
	std::system("clear");
}

void	modifiers(int testNmb)
{
	std::cout << std::endl << YELLOW << "                              *** MODIFIERS ***                          " << NORMAL << std::endl;

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	std::cout << std::endl << YELLOW << "assign" << NORMAL << std::endl;
	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (assign 1)");

	/*		assign 1		*/
	userList.assign(5, 21);
	sysList.assign(5, 21);
	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (assign 1)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (assign 1)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (assign 1)");
	std::cout << std::endl;

	/*		assign 2		*/

	// userList.push_front(11111111);
	// sysList.push_front(11111111);

	// userList.push_back(22222222);
	// sysList.push_back(22222222);
	
	// // userList.assign(5, 21);
	// sysList.assign(sysList.begin(), sysList.end());
	// compareValues(++testNmb, sysList.size(), userList.size(), "Size is");
	// compareValues(++testNmb, sysList.front(), userList.front(), "Front value is");
	// compareValues(++testNmb, sysList.back(), userList.back(), "Back value is");
	getchar();
	std::system("clear");




	std::cout << std::endl << YELLOW << "insert" << NORMAL << std::endl;
	/*		insert 1		*/
	sysList.clear();
	userList.clear();

	sysList.assign(1, 100);
	userList.assign(1, 100);

	sysList.insert(sysList.begin(), 5);
	userList.insert(userList.begin(), 5);

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (insert 1)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (insert 1)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (insert 1)");
	std::cout << std::endl;
	
	/*		insert 2		*/
	sysList.clear();
	userList.clear();

	sysList.assign(1, 100);
	userList.assign(1, 100);

	sysList.insert(sysList.begin(), 3, 5);
	userList.insert(userList.begin(), 3, 5);

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (insert 2)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (insert 2)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (insert 2)");
	std::cout << std::endl;
	getchar();
	std::system("clear");

	std::cout << std::endl << YELLOW << "erase" << NORMAL << std::endl;
	/*		erase 1		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.erase(sysList.begin());
	userIterator = userList.erase(userList.begin());

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 1)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 1)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 1)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 1)");
	std::cout << std::endl;

	/*		erase 1.1		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 
	userList.push_back(1);

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.erase(sysList.begin());
	userIterator = userList.erase(userList.begin());

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 1.1)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 1.1)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 1.1)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 1.1)");
	std::cout << std::endl;

	/*		erase 2		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();

	userIterator = userList.begin();
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 2)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 2)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 2)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 2)");
	std::cout << std::endl;

	/*		erase 2.0		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 2.0)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 2.0)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 2.0)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 2.0)");
	std::cout << std::endl;

	/*		erase 2.1		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
	userIterator++;
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 2.1)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 2.1)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 2.1)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 2.1)");
	std::cout << std::endl;

	/*		erase 2.2		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;
	sysIterator++;
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
	userIterator++;
	userIterator++;
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 2.2)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 2.2)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 2.2)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 2.2)");
	std::cout << std::endl;

	/*		erase 2.3		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(5);			// 5 6 7
	userList.push_back(5);

	sysList.push_back(6);			// 5 6 7
	userList.push_back(6);

	sysList.push_back(7);			// 5 6 7
	userList.push_back(7);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;
	sysIterator++;
	sysIterator++;
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
	userIterator++;
	userIterator++;
	userIterator++;

	compareValues(++testNmb, *(sysList.begin()), *(userList.begin()), "First iterator is (erase 2.3)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Last iterator is (erase 2.3)");
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (erase 2.3)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (erase 2.3)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (erase 2.3)");
	compareValues(++testNmb, *sysIterator, *userIterator, "Return value (erase 2.3)");
	std::cout << std::endl;
	getchar();
	std::system("clear");


	/*		swap 1		*/
	std::cout << std::endl << YELLOW << "swap" << NORMAL << std::endl;

	std::list <int> sysListSwap1;
	ft::list <int> userListSwap1;

	sysListSwap1.push_back(1);
	userListSwap1.push_back(1);
	
	sysListSwap1.push_back(2);
	userListSwap1.push_back(2);
	
	sysListSwap1.push_back(3);
	userListSwap1.push_back(3);

	std::list <int> sysListSwap2;
	ft::list <int> userListSwap2;

	sysListSwap2.push_back(4);
	userListSwap2.push_back(4);
	
	sysListSwap2.push_back(5);
	userListSwap2.push_back(5);
	
	sysListSwap2.push_back(6);
	userListSwap2.push_back(6);

	sysListSwap2.push_back(7);
	userListSwap2.push_back(7);
	
	sysListSwap2.push_back(8);
	userListSwap2.push_back(8);
	
	sysListSwap2.push_back(9);
	userListSwap2.push_back(9);

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" SysListSwap1:", sysListSwap1);
	// print_container(" SysListSwap2:", sysListSwap2);
	// std::cout << std::endl;
	// print_container("UserListSwap1:", userListSwap1);
	// print_container("UserListSwap2:", userListSwap2);
	// std::cout << std::endl;

	sysListSwap1.swap(sysListSwap2);
	userListSwap1.swap(userListSwap2);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" SysListSwap1:", sysListSwap1);
	// print_container(" SysListSwap2:", sysListSwap2);
	// std::cout << std::endl;
	// print_container("UserListSwap1:", userListSwap1);
	// print_container("UserListSwap2:", userListSwap2);
	// std::cout << std::endl;

	compareValues(++testNmb, sysListSwap1.size(), userListSwap1.size(), "Size is (swap)");
	compareValues(++testNmb, sysListSwap1.front(), userListSwap1.front(), "Front value is (swap)");
	compareValues(++testNmb, sysListSwap1.back(), userListSwap1.back(), "Back value is (swap)");

	compareValues(++testNmb, sysListSwap2.size(), userListSwap2.size(), "Size is (swap)");
	compareValues(++testNmb, sysListSwap2.front(), userListSwap2.front(), "Front value is (swap)");
	compareValues(++testNmb, sysListSwap2.back(), userListSwap2.back(), "Back value is (swap)");

	getchar();
	std::system("clear");

	/*		resize 1		*/
	std::cout << std::endl << YELLOW << "resize" << NORMAL << std::endl;
	
	sysList.clear();
	userList.clear();
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	sysList.resize(3, 9);
	userList.resize(3, 9);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (resize 1)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (resize 1)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (resize 1)");
	getchar();
	// std::system("clear");

	/*		resize 2		*/
	std::cout << std::endl << YELLOW << "resize" << NORMAL << std::endl;
	
	sysList.clear();
	userList.clear();

	sysList.push_back(5);			// 5 6 7
	userList.push_back(5);

	sysList.push_back(6);			// 5 6 7
	userList.push_back(6);

	sysList.push_back(7);			// 5 6 7
	userList.push_back(7);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	sysList.resize(3, 9);
	userList.resize(3, 9);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (resize 2)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (resize 2)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (resize 2)");
	getchar();
	// std::system("clear");

	/*		resize 3		*/
	std::cout << std::endl << YELLOW << "resize" << NORMAL << std::endl;
	
	sysList.clear();
	userList.clear();

	sysList.push_back(5);			// 5 6 7
	userList.push_back(5);

	sysList.push_back(6);			// 5 6 7
	userList.push_back(6);

	sysList.push_back(7);			// 5 6 7
	userList.push_back(7);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	sysList.resize(5, 9);
	userList.resize(5, 9);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (resize 3)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (resize 3)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (resize 3)");
	getchar();
	// std::system("clear");


	/*		resize 4		*/
	std::cout << std::endl << YELLOW << "resize" << NORMAL << std::endl;
	
	sysList.clear();
	userList.clear();

	sysList.push_back(5);			// 5 6 7
	userList.push_back(5);

	sysList.push_back(6);			// 5 6 7
	userList.push_back(6);

	sysList.push_back(7);			// 5 6 7
	userList.push_back(7);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	sysList.resize(1, 9);
	userList.resize(1, 9);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" Sys Erase:", sysList);
	// print_container("User Erase:", userList);
	// std::cout << std::endl;

	compareValues(++testNmb, sysList.size(), userList.size(), "Size is (resize 4)");
	compareValues(++testNmb, sysList.front(), userList.front(), "Front value is (resize 4)");
	compareValues(++testNmb, sysList.back(), userList.back(), "Back value is (resize 4)");
	getchar();
	std::system("clear");
}

void	operations(int testNmb)
{
	std::cout << std::endl << YELLOW << "                              *** OPERATIONS ***                          " << NORMAL << std::endl;

	/*		splice 1		*/
	std::cout << std::endl << YELLOW << "splice" << NORMAL << std::endl;

	std::list <int> sysListSplice1;
	ft::list <int> userListSplice1;

	for (int i = 1; i <= 3; i++)
	{
		sysListSplice1.push_back(i);
		userListSplice1.push_back(i);
	}

	std::list <int> sysListSplice2;
	ft::list <int> userListSplice2;

	for (int i = 4; i <= 9; i++)
	{
		sysListSplice2.push_back(i);
		userListSplice2.push_back(i);
	}

	std::cout << "*** BEFORE ***" << std::endl;
	print_container(" SysListSplice1:", sysListSplice1);
	print_container(" SysListSplice2:", sysListSplice2);
	std::cout << std::endl;
	print_container("UserListSplice1:", userListSplice1);
	print_container("UserListSplice2:", userListSplice2);
	std::cout << std::endl;

	sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2);
	userListSplice1.splice(userListSplice1.begin(), userListSplice2);

	std::cout << "*** AFTER ***" << std::endl;
	print_container(" SysListSplice1:", sysListSplice1);
	print_container(" SysListSplice2:", sysListSplice2);
	std::cout << std::endl;
	print_container("UserListSplice1:", userListSplice1);
	print_container("UserListSplice2:", userListSplice2);
	std::cout << std::endl;

	compareValues(++testNmb, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 1)");
	compareValues(++testNmb, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 1)");
	compareValues(++testNmb, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 1)");

	compareValues(++testNmb, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 1)");
	compareValues(++testNmb, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 1)");
	compareValues(++testNmb, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 1)");

	getchar();
	std::system("clear");

	/*		splice 1.1		*/
	// std::cout << std::endl << YELLOW << "splice" << NORMAL << std::endl;

	// sysListSplice1.clear();
	// userListSplice1.clear();

	// for (int i = 1; i <= 3; i++)
	// {
	// 	sysListSplice1.push_back(i);
	// 	userListSplice1.push_back(i);
	// }

	// sysListSplice2.clear();
	// userListSplice2.clear();

	// for (int i = 4; i <= 9; i++)
	// {
	// 	sysListSplice2.push_back(i);
	// 	userListSplice2.push_back(i);
	// }

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_container(" SysListSplice1:", sysListSplice1);
	// print_container(" SysListSplice2:", sysListSplice2);
	// std::cout << std::endl;
	// print_container("UserListSplice1:", userListSplice1);
	// print_container("UserListSplice2:", userListSplice2);
	// std::cout << std::endl;

	// sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2);
	// // userListSplice1.splice(userListSplice1.begin(), userListSplice2);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_container(" SysListSplice1:", sysListSplice1);
	// print_container(" SysListSplice2:", sysListSplice2);
	// std::cout << std::endl;
	// print_container("UserListSplice1:", userListSplice1);
	// print_container("UserListSplice2:", userListSplice2);
	// std::cout << std::endl;

	// compareValues(++testNmb, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 1.1)");
	// compareValues(++testNmb, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 1.1)");
	// compareValues(++testNmb, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 1.1)");

	// compareValues(++testNmb, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 1.1)");
	// compareValues(++testNmb, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 1.1)");
	// compareValues(++testNmb, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 1.1)");

	// getchar();
	// std::system("clear");

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

	int testNmb = 0;
	
	/*			Member functions			*/
	
	/* extra */
	operators(testNmb);

	constructor(testNmb);
	// destructor(testNmb);			// need tests
	// operator=(testNmb);			// need tests
	
	// iterators(testNmb);			// need tests
	capacity(testNmb);
	elementAccess(testNmb);
	modifiers(testNmb);
	operations(testNmb);
	// observers(testNmb);			// need tests
	// overloads(testNmb);			// need tests
}
