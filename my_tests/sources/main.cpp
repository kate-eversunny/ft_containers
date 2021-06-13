/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:44:26 by gbroccol          #+#    #+#             */
/*   Updated: 2021/06/13 15:17:01 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

int main() {
	
	while (true) {
	
		std::cout << GREEN << "\nSelect tests to run" << NORMAL << std::endl << std::endl;

		std::cout << GREEN << "1.  " << BLUE << "List" <<  NORMAL <<std::endl;
		std::cout << GREEN << "2.  " << BLUE << "Vector" << NORMAL << std::endl;
		std::cout << GREEN << "3.  " << BLUE << "Map" << NORMAL << std::endl;
		std::cout << GREEN << "4.  " << BLUE << "Stack" << NORMAL << std::endl;
		std::cout << GREEN << "5.  " << BLUE << "Queue" << NORMAL << std::endl;
		std::cout << GREEN << "6.  " << BLUE << "All" << NORMAL << std::endl;
		std::cout << GREEN << "0.  " << BLUE << "Exit" << NORMAL << std::endl << std::endl;

		int index = 7;
		while (true) {
			std::cout << GREEN << "Enter index: " << NORMAL;
			std::cin >> index;
			if (std::cin.eof()) {
				std::cout << std::endl;
				exit(0);
			}
			if (!std::cin || index < 0 || index > 10) {
				std::cout << RED << "\nIncorrect input\n" << NORMAL << std::endl;
				std::cin.clear();
				while (std::cin.get() != '\n');
			} else {
				std::cin.ignore();
				break;
			}
		}
	
		if (index == 1)
			list_test();
		else if (index == 2)
			vector_test();
		else if (index == 3)
			map_test();
		else if (index == 4)
			stack_test();
		else if (index == 5)
			queue_test();
		else if (index == 6) {
			list_test();
			getchar();
			std::system("clear");
			
			vector_test();
			getchar();
			std::system("clear");

			map_test();
			getchar();
			std::system("clear");

			stack_test();
			getchar();
			std::system("clear");

			queue_test();
			getchar();
			std::system("clear");
			
		} else if (index == 0)
			exit(0);
		
		std::cout << std::endl;
		std::cout << GREEN << "1. " << BLUE << "Return to the test selection menu" << NORMAL << std::endl;
		std::cout << GREEN << "0. " << BLUE << "Exit" << NORMAL << std::endl << std::endl;
		std::cin >> index;
		if (index == 1)
			continue;
		else if (index == 0)
			exit(0);
			
		index = 0;
		std::cin >> index;
		if (index == '0')
			break; 
	}
}
