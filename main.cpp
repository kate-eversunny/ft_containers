/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/01 19:00:09 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
// #include <iostream>
// #include <stack>
// #include <vector>
#include <iterator>
#include "list_iterator.hpp"

int main(void)
{
	ft::list<int> a;
	// ft::list<int>::iterator it = a.begin();
	ft::list<int>::iterator it ;

	*it = 1;
	// it++;
	// *it = 2;
	
	ft::list<int>::iterator *it2 = &it;
	// it2->;
	

	// std::list<int> b;
	// std::list<int>::iterator it3 = b.begin();
	// std::list<int>::iterator it3 ;
	
	// *it3 = 2;
	return 0;
}