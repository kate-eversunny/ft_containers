/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:57:56 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/04 23:07:05 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cstddef> //for fundamental types
# include "list_iterator.hpp"
# include <limits>

#include <iostream>

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
		void
		create_list_end(void)
		{
			this->tail = new node;
			this->head = this->tail;
			this->tail->value = 0;
			this->tail->prev = this->head;
			this->tail->next = this->head;
			this->list_size = 0;
			return; 
		}
		
		void
		create_list_head(const value_type& val)
		{
			this->head = new node;
			this->head->value = val;
			this->head->prev = this->tail;
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->tail->next = this->head;
			this->list_size++;
			this->tail->value = list_size;
			return; 
		}
		
	public:
	// *************** Constructors ***************
		explicit
		list (void)
		{ 
			create_list_end();
			return; 
		}
		
		explicit
		list (size_type n, const value_type& val = value_type())
		{
			create_list_end();
			for (size_type i = 0; i < n; i++)
				push_front(val);
			return;
		}
		
		// // template <class InputIterator>
		// // list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		// template <class InputIterator>
		// list (InputIterator first, InputIterator last)
		// {
		// 	create_list_end();
		// 	insert(end(), first, last);
		// 	return;
		// }
		
		list (const list& x)
		{
			if (this != &x)
			{
				iterator it = x.begin();
				create_list_end();
				create_list_head(it.ptr->value);
				for (++it; it != x.end(); it++)
					push_back(it.ptr->value);
			}
			return;
		}
	
	// *************** Destructor ***************
		~list(void) 
		{
			if (!empty())
				erase(begin(), end());
			delete this->tail;
			return; 
		}
	
	// *************** Overload of operator= ***************
		list&
		operator= (const list& x)
		{
			erase(begin(), end());
			iterator it = x.begin();
			create_list_head(it.ptr->value);
			for (++it; it != x.end(); it++)
				push_back(it.ptr->value);
			return *this;
		}

	// *************** Iterators ***************
		iterator
		begin(void)
		{
			iterator beg(this->head);
			return beg;
		}
		
		const_iterator
		begin() const 
		{
			iterator beg(this->head);
			return beg;
		}

		iterator
		end(void) 
		{
			iterator end(this->tail);
			return end;
		}

		const_iterator
		end() const
		{
			iterator end(this->tail);
			return end;
		}

		// reverse_iterator rbegin();
		
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();

		// const_reverse_iterator rend() const;
		
	
	// *************** Capacity ***************
		bool
		empty(void) const { return this->list_size == 0; }
		
		size_type
		size(void) const { return this->list_size; }
		
		size_type
		max_size(void) const { return std::numeric_limits<difference_type>::max() / sizeof(node); }
	
	// *************** Element access ***************
		reference
		front(void) { return this->head->value; }
		
		const_reference
		front(void) const { return this->head->value; }
		
		reference
		back(void) { return this->tail->prev->value; }
		
		const_reference
		back(void) const { return this->tail->prev->value; }
	
	// *************** Modifiers ***************
		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last)
		// {
		// 	ft::list<T> temp(first, last);
		// 	clear();
		// 	*this = temp;
		// 	return;
		// }

		void
		assign (size_type n, const value_type& val)
		{
			clear();
			for (size_type i = 0; i < n; i++)
				push_front(val);
			return;
		}

		void
		push_front (const value_type& val)
		{
			node * current = new node;
			current->value = val;
			current->prev = this->tail;
			current->next = this->head;
			this->head->prev = current;
			this->tail->next = current;
			this->head = current;
			this->list_size++;
			this->tail->value = list_size;
			return;
		}

		void
		pop_front(void)
		{
			node * current = this->head->next;
			current->prev = this->tail;
			delete head;
			this->head = current;
			this->list_size--;
			this->tail->value = list_size;
			return;
		}

		void
		push_back (const value_type& val)
		{
			if (empty())
				create_list_head(val);
			else
			{
				node * current = new node;
				node * previous = this->tail->prev;
				current->value = val;
				current->prev = previous;
				previous->next = current;
				current->next = this->tail;
				this->tail->prev = current;
				this->list_size++;
				this->tail->value = list_size;
			}
			return;
		}

		void
		pop_back(void)
		{
			node * current = this->tail->prev->prev;
			current->next = this->tail;
			delete this->tail->prev;
			this->tail->prev = current;
			this->list_size--;
			this->tail->value = list_size;
			return;
		}

		iterator
		insert (iterator position, const value_type& val)
		{
			if (position == this->head)
			{
				push_front(val);
				return (begin());
			}
			else
			{
				node *new_node = new node;
				node *prev = position.ptr->prev;
				new_node->value = val;
				new_node->prev = prev;
				new_node->next = position.ptr;
				prev->next = new_node;
				position.ptr->prev = new_node;
				this->list_size++;
				this->tail->value = list_size;
				return iterator(new_node);
			}
		}

		void
		insert (iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				insert(position, val);
			return;
		}

		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last)
		// {
		// 	InputIterator it;
		// 	for (it = first; it != last; it++)
		// 		insert(position, *it);
		// 	return;
		// }

		iterator
		erase (iterator position)
		{
			iterator temp = position;
			position++;
			if (temp.ptr == this->head)
				pop_front();
			else
			{
				temp.ptr->prev->next = position.ptr;
				position.ptr->prev = temp.ptr->prev;
				delete temp.ptr;
				temp.ptr = NULL;
				this->list_size--;
				this->tail->value = list_size;
			}
			return position;
		}

		iterator
		erase (iterator first, iterator last)
		{
			while (first != last)
				first = erase(first);
			return last;
		}
		
		void
		swap (list& x)
		{
			ft::list<T> temp(x);
			x = *this;
			*this = temp;
			return;
		}

		void
		resize (size_type n, value_type val = value_type())
		{
			if (this->list_size > n)
			{
				iterator it;
				for (it = begin(); n > 0; it++)
					n--;
				erase(it, end());
			}
			else if (this->list_size < n)
				insert(end(), n - this->list_size, val);
			return;			
		}

		void
		clear(void)
		{
			erase(begin(), end());
			return;
		}

	// *************** Operations ***************
		void
		splice (iterator position, list& x)
		{
			node * pos = position.ptr;
			iterator temp;
			for (iterator it = x.begin(); it != x.end(); it = temp)
			{
				it = x.begin();
				temp = ++(x.begin());
				it.ptr->prev = pos->prev;
				it.ptr->next = pos;
				pos->prev->next = it.ptr;
				pos->prev = it.ptr;
				this->list_size++;
				this->tail->value = list_size;
				if (pos == this->head)
					this->head = it.ptr;
				x.head = temp.ptr;
			}
			x.head = x.tail;
			x.tail->next = x.tail->prev = x.head;
			x.list_size = x.tail->value = 0;
			return;
		}

		void
		splice (iterator position, list& x, iterator i)
		{
			node * pos = position.ptr;
			node * tmp = i.ptr->prev;
			iterator temp;
			for (iterator it = i; it != x.end(); it = temp)
			{
				it = i;
				temp = ++i;
				it.ptr->prev = pos->prev;
				it.ptr->next = pos;
				pos->prev->next = it.ptr;
				pos->prev = it.ptr;
				this->list_size++;
				this->tail->value = list_size;
				if (pos == this->head)
					this->head = it.ptr;
				x.tail->value = x.list_size--;
			}
			x.tail->prev = tmp;
			tmp->next = x.tail;
			return;
		}

		void
		splice (iterator position, list& x, iterator first, iterator last)
		{
			node * pos = position.ptr;
			node * tmp = first.ptr->prev;
			iterator temp;
			for (iterator it = first; it != last; it = temp)
			{
				it = first;
				temp = ++first;
				it.ptr->prev = pos->prev;
				it.ptr->next = pos;
				pos->prev->next = it.ptr;
				pos->prev = it.ptr;
				this->list_size++;
				this->tail->value = list_size;
				if (pos == this->head)
					this->head = it.ptr;
				x.tail->value = x.list_size--;
			}
			last.ptr->prev = tmp;
			tmp->next = last.ptr;
			return;
		}
		
		void
		remove (const value_type& val);
		
		template <class Predicate>
  		void 
		remove_if (Predicate pred);

		void
		unique(void);

		template <class BinaryPredicate>
  		void
		unique (BinaryPredicate binary_pred);
		
		void
		merge (list& x);

		template <class Compare>
		void
		merge (list& x, Compare comp);

		void
		sort(void);
		
		template <class Compare>
		void
		sort (Compare comp);

		void
		reverse(void);
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
