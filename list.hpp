/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:57:56 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/02 18:59:09 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cstddef> //for fundamental types
# include "list_iterator.hpp"
# include <limits>

#include <iostream> // delete

namespace ft
{
	template<class T>
	struct Node
	{
		T	value;
		struct Node *next;
		struct Node *prev;
	};
}

namespace ft
{	
	template<class T>
	class list
	{
	public:
		typedef T 												value_type;
		typedef typename ft::Node<T>							node;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef T*												pointer;
		typedef const T*										const_pointer;
		typedef typename ft::list_iterator<value_type>			iterator;
		typedef typename ft::list_iterator<value_type>		const_iterator;
		// typedef typename ft::list_reverse_iterator<value_type>	reverse_iterator;
		// typedef typename ft::list_reverse_iterator<value_type>	const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;
	
	private:
		node 		*head;
		node 		*tail;
		size_type	list_size;
		

	// *************** Additional functions ***************
		void create_list_head(const value_type& val)
		{
			head = new node;
			head->value = val;
			head->prev = nullptr;
			head->next = nullptr;
			tail = head;
			list_size = 1;
			return; 
		}
		
	public:
	// *************** Constructors ***************
		explicit list (void) : head(nullptr), tail(nullptr), list_size(0)
		{ 
			// create_list_head(nullptr);
			return; 
		}
		
		explicit list (size_type n, const value_type& val = value_type())
		{
			create_list_head(val);
			for (size_type i = 1; i < n; i++)
				push_back(val);
			return;
		}
		
		// template <class InputIterator>
		// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		
		list (const list& x)
		{
			if (this != &x)
			{
				iterator it = x.begin();
				create_list_head(it.ptr->value);
				for (++it; it != x.end(); it++)
					push_back(it.ptr->value);
			}
		}
	
	// *************** Destructor ***************
		~list(void) 
		{
			// if (!empty())
			// 	erase(begin(), end());
			return; 
		};
	
	// *************** Overload of operator= ***************
		list& operator= (const list& x);

	// *************** Iterators ***************
		iterator begin(void)
		{
			iterator beg(this->head);
			return beg;
		}
		
		const_iterator begin() const { return begin(); }

		iterator end(void) 
		{
			iterator end(this->tail->next); ////// 												need to be fixed
			return end;
		}

		// const_iterator end() const;

		// reverse_iterator rbegin();
		
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();

		// const_reverse_iterator rend() const;
		
	
	// *************** Capacity ***************
		bool empty(void) const { return this->list_size == 0; }
		
		size_type size(void) const { return this->list_size; }
		
		size_type max_size(void) const { return std::numeric_limits<difference_type>::max() / sizeof(node); }
	
	// *************** Element access ***************
		reference front(void) { return this->head->value; }
		
		const_reference front(void) const { return this->head->value; }
		
		reference back(void) { return this->tail->value; }
		
		const_reference back(void) const { return this->tail->value; }
	
	// *************** Modifiers ***************
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);

		void assign (size_type n, const value_type& val);

		void push_front (const value_type& val)
		{
			if (empty())
				create_list_head(val);
			else
			{
				node * current = new node;
				current->value = val;
				current->prev = nullptr;
				current->next = this->head;
				this->head->prev = current;
				this->head = current;
				this->list_size++;
			}
			return;
		}

		void pop_front(void)
		{
			node * current = this->head->next;
			current->prev = nullptr;
			delete head;
			head = current;
			this->list_size--;
			return;
		}

		void push_back (const value_type& val)
		{
			if (empty())
				create_list_head(val);
			else
			{
				node * current = new node;
				current->value = val;
				current->prev = this->tail;
				current->next = nullptr;
				this->tail->next = current;
				this->tail = current;
				this->list_size++;
			}
			return;
		}

		void pop_back(void)
		{
			node * current = this->tail->prev;
			current->next = nullptr;
			delete this->tail;
			this->tail = current;
			this->list_size--;
			return;
		}

		iterator insert (iterator position, const value_type& val)
		{
			node *new_node = new node;
			new_node->value = val;
			new_node->prev = position.ptr->prev;
			new_node->next = position.ptr;
			position.ptr->prev->next = new_node;
			position.ptr->prev = new_node;
			return iterator(new_node);
		}

		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position)
		{
			if (position != end())
			{
				iterator temp = end();
				if (position.ptr->prev == nullptr)
				{
					this->head = position.ptr->next;
					this->head->prev = nullptr;
					temp = position++;
				}
				else if (position.ptr->next == nullptr)
				{
					this->tail = position.ptr->prev;
					this->tail->next = nullptr;
				}
				else
				{
					position.ptr->prev->next = position.ptr->next;
					position.ptr->next->prev = position.ptr->prev;
					temp = position++;
				}
				delete position.ptr;
				this->list_size--;
				return temp;
			}
			return position;
		}

		iterator erase (iterator first, iterator last)
		{
			iterator i;
			i = first;
			
			while (i != last)
				i = erase(i);
			return last;
		}
		
		void swap (list& x);

		void resize (size_type n, value_type val = value_type());

		void clear(void);

	// *************** Operations ***************
		void splice (iterator position, list& x);

		void splice (iterator position, list& x, iterator i);

		void splice (iterator position, list& x, iterator first, iterator last);
		
		void remove (const value_type& val);
		
		template <class Predicate>
  		void remove_if (Predicate pred);

		void unique(void);

		template <class BinaryPredicate>
  		void unique (BinaryPredicate binary_pred);
		
		void merge (list& x);

		template <class Compare>
		void merge (list& x, Compare comp);

		void sort(void);
		
		template <class Compare>
		void sort (Compare comp);

		void reverse(void);
	};

	// // *************** Non-member function overloads ***************
	// template <class T, class Alloc>
	// bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// void swap (list<T,Alloc>& x, list<T,Alloc>& y);
}

#endif
