/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:58:00 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/04 23:07:38 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
// #include <stack>
// #include <vector>
#include <iterator>
#include "list_iterator.hpp"

int main(void)
{
	ft::list<int> a;
	a.assign(3, 3);
	ft::list<int>::iterator it = a.begin();

	ft::list<int> b;
	b.assign(3, 4);
	ft::list<int>::iterator it2 = b.begin();
	it2++;

	a.splice(it, b, it2, b.end());
	for (it = a.begin(); it != a.end(); it++)
		std::cout << a.size() << " " << *it << std::endl;
	for (it2 = b.begin(); it2 != b.end(); it2++)
		std::cout << b.size() << " " << *it2 << std::endl;

	return 0;
}