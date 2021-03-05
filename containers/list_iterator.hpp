/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:26:08 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/05 22:29:24 by pvivian          ###   ########.fr       */
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
	
	// *************** Overloads ***************
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
  	struct reverse_list_iterator 
	{
	private:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef typename ft::Node<T>			node;
		typedef T*								pointer;
		typedef T& 								reference;
		typedef typename ft::list_iterator<T>	iterator_type;

		iterator_type base;
	
	public:
	
	// *************** Constructors ***************

		reverse_list_iterator() { iterator_type base; return; }

		explicit reverse_list_iterator(iterator_type it) { iterator_type base(it); return; }

		template <class T>
		reverse_iterator (const reverse_list_iterator<T>& toCopy)
		{
			iterator_type base(toCopy.base);
			return ;
		}
	
	// *************** Destructor ***************
		~reverse_list_iterator(void) { return ; }
	
	// *************** Member functions ***************
		iterator_type base() const { return this->base; }

		reference operator*(void) const { return *this->base; }

		pointer operator->(void) const { return &this->base; }
		
		reverse_list_iterator & operator++(void)
		{
			this->base--;
			return *this;
		}

		reverse_list_iterator operator++(int)
		{
			reverse_list_iterator temp(*this);
			this->base--;
			return temp;
		}
		
		reverse_list_iterator & operator--(void)
		{
			this->base++;
			return *this;
		}

		reverse_list_iterator operator--(int)
		{
			reverse_list_iterator temp(*this);
			this->base++;
			return temp;
		}

		bool operator==(reverse_list_iterator const & other) const { return this->base==other.base; }
		
		bool operator!=(reverse_list_iterator const & other) const { return this->base!=other.base; }
  };
}

#endif
