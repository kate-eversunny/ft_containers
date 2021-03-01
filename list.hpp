/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:57:56 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/01 19:00:22 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cstddef> //for fundamental types
# include "list_iterator.hpp"

namespace ft
{
	template<class T>
	struct Node
	{
		T	value;
		struct Node *next;
		struct Node *prev;
	};
	
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
		// typedef typename ft::list_iterator<value_type>		const_iterator;
		// typedef typename ft::list_reverse_iterator<value_type>	reverse_iterator;
		// typedef typename ft::list_reverse_iterator<value_type>	const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;
	
	private:
		node *nodes;
		
	public:
	// *************** Constructors ***************
		explicit list (void) : nodes(nullptr) { return; }
		
		explicit list (size_type n, const value_type& val = value_type());
		// {
		// 	this->nodes = this->node_allocator.allocate(n); //
		// 	iterator beg = this->nodes;
		// 	while (beg != nodes + n)
		// 	{
		// 		beg->ptr->
		// 	}
			
			
		// }
		
		// template <class InputIterator>
		// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		
		// list (const list& x);
	
	// *************** Destructor ***************
		~list(void);
	
	// *************** Overload of operator= ***************
		list& operator= (const list& x);
	
	// *************** Capacity ***************
		bool empty(void) const;
		
		size_type size(void) const;
		
		size_type max_size(void) const;
	
	// *************** Element access ***************
		reference front(void);
		
		const_reference front(void) const;
		
		reference back(void);
		
		const_reference back(void) const;
	
	// *************** Modifiers ***************
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);

		void assign (size_type n, const value_type& val);

		void push_front (const value_type& val);

		void pop_front(void);

		iterator insert (iterator position, const value_type& val);

		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);

		iterator erase (iterator first, iterator last);
		
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
