/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:26:08 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/01 19:02:21 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <cstddef> //for fundamental types
# include "list.hpp"

namespace ft
{
	template <class T>
  	struct list_iterator 
	{
	private:
		typedef T						value_type;
		typedef ptrdiff_t				difference_type;
		typedef typename ft::Node<T>	node;
		typedef T*   					pointer;
		typedef T& 						reference;

		node * ptr;

	public:
	
	// *************** Constructors ***************

		iterator() : ptr(nullptr) { return; }

		iterator(iterator const & toCopy)
		{
			ptr = toCopy.ptr;
			return ;
		}

		iterator & operator= (iterator const & toCopy)
		{
			if (&this != toCopy)
				ptr = toCopy.ptr;
			return *this;
		}
	
	// *************** Destructor ***************
		~iterator(void) { return ; }
	
	// *************** Overloads ***************
		bool operator==(iterator const & other) const { return this->ptr==other.ptr; }
		
		bool operator!=(iterator const & other) const { return this->ptr!=other.ptr; }
		
		reference operator*(void) const { return this->ptr->value; }

		pointer operator->(void) const { return this->ptr->value; }
		
		iterator & operator++(void)
		{
			this->ptr++;
			return *this;
		}

		iterator & operator++(int value)
		{
			iterator temp(*this);
			this->ptr++;
			return temp;
		}

		iterator & operator--(void)
		{
			this->ptr--;
			return *this;
		}

		iterator & operator--(int value)
		{
			iterator temp(*this);
			this->ptr--;
			return temp;
		}
  };
}

#endif
