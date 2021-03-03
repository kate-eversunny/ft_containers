/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:26:08 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/03 12:37:19 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <cstddef> //for fundamental types
# include "list.hpp"

namespace ft
{
	template <class T>
	struct Node;
	
	template <class T>
  	struct list_iterator 
	{
	private:
		typedef T						value_type;
		typedef ptrdiff_t				difference_type;
		typedef typename ft::Node<T>	node;
		typedef T*						pointer;
		typedef T& 						reference;

	public:
		node *ptr;
	
	// *************** Constructors ***************

		list_iterator() : ptr(nullptr) { return; }

		list_iterator(node * new_ptr) : ptr(new_ptr) { return; }

		list_iterator(list_iterator const & toCopy)
		{
			ptr = toCopy.ptr;
			return ;
		}

		list_iterator & operator= (list_iterator const & toCopy)
		{
			if (this != &toCopy)
				ptr = toCopy.ptr;
			return *this;
		}
	
	// *************** Destructor ***************
		~list_iterator(void) { return ; }
	
	// *************** Overloads ***************
		bool operator==(list_iterator const & other) const { return this->ptr==other.ptr; }
		
		bool operator!=(list_iterator const & other) const { return this->ptr!=other.ptr; }
		
		reference operator*(void) const { return this->ptr->value; }

		pointer operator->(void) const { return &this->ptr->value; }
		
		list_iterator & operator++(void)
		{
			// if (this->ptr->next)
				this->ptr = this->ptr->next;
			return *this;
		}

		list_iterator operator++(int)
		{
			list_iterator temp(*this);
			// if (this->ptr->next)
				this->ptr = this->ptr->next;
			return temp;
		}

		list_iterator & operator--(void)
		{
			// if (this->ptr->prev)
				this->ptr = this->ptr->prev;
			return *this;
		}

		list_iterator  operator--(int)
		{
			list_iterator temp(*this);
			// if (this->ptr->prev)
				this->ptr = this->ptr->prev;
			return temp;
		}
  };
}

#endif
