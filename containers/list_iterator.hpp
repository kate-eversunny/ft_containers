/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:26:08 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/12 16:33:05 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

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
		typedef typename ft::Node<T>	node;
		typedef T*						pointer;
		typedef T& 						reference;

	public:
		node *ptr;
	
	// *************** Constructors ***************

		list_iterator() : ptr(NULL) { return; }

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
	
	// *************** Member functions ***************
		bool operator==(list_iterator const & other) const { return this->ptr==other.ptr; }
		
		bool operator!=(list_iterator const & other) const { return this->ptr!=other.ptr; }
		
		reference operator*(void) const { return this->ptr->value; }

		pointer operator->(void) const { return &this->ptr->value; }
		
		list_iterator & operator++(void)
		{
			this->ptr = this->ptr->next;
			return *this;
		}

		list_iterator operator++(int)
		{
			list_iterator temp(*this);
			this->ptr = this->ptr->next;
			return temp;
		}

		list_iterator & operator--(void)
		{
			this->ptr = this->ptr->prev;
			return *this;
		}

		list_iterator  operator--(int)
		{
			list_iterator temp(*this);
			this->ptr = this->ptr->prev;
			return temp;
		}
  	};

	template <class T>
  	struct const_list_iterator : public list_iterator<T>
	{
	private:
		typedef typename ft::Node<T>	node;
		typedef T						value_type;
		typedef const value_type*		const_pointer;
		typedef const value_type& 		const_reference;
	
	public:
	// *************** Constructors ***************

		const_list_iterator() { return; }

		const_list_iterator(node* new_ptr) { this->ptr = new_ptr; return; }

		const_list_iterator(const_list_iterator const & toCopy)
		{
			this->ptr = toCopy.ptr;
			return;
		}

		const_list_iterator(list_iterator<T> const & toCopy)
		{
			this->ptr = toCopy.ptr;
			return;
		}
		
		const_list_iterator & operator= (const_list_iterator const & toCopy)
		{
			if (this != &toCopy)
				this->ptr = toCopy.ptr;
			return *this;
		}
	
		const_list_iterator & operator= (list_iterator<T> const & toCopy)
		{
			if (this != &toCopy)
				this->ptr = toCopy.ptr;
			return *this;
		}
		
	// *************** Destructor ***************
		~const_list_iterator(void) { return ; }
	
	// *************** Member functions ***************
		const_reference operator*(void) const { return this->ptr->value; }
		const_pointer operator->(void) const { return &this->ptr->value; }
	};

}

#endif
