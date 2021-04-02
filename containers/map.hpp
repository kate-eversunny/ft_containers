/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:25:38 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/01 18:24:57 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef> //for fundamental types
# include "redBlackTree.hpp"
# include "map_iterator.hpp"
# include <limits>
# include <memory>
# include <iostream>
# include <utility>
# include <functional>

namespace ft
{	
	template <class Key, class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key,T> > >
	class map
	{
	public:
		
		typedef Key															key_type;
		typedef T 															mapped_type;
		typedef typename std::pair<const key_type,mapped_type>				value_type;
		typedef typename std::less<key_type>								key_compare;
		// typedef typename value_comp											value_compare;
		typedef Allocator													allocator_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef value_type*													pointer;
		typedef const value_type*											const_pointer;
		typedef typename ft::map_iterator<key_type, mapped_type>			iterator;
		// typedef typename ft::map_iterator<value_type>					const_iterator;
		typedef typename ft::reverse_map_iterator<key_type, mapped_type>	reverse_iterator;
		// typedef typename ft::reverse_map_iterator<value_type>	const_reverse_iterator;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;
		typedef typename ft::redBlackTree<Key, T>							tree_type;
	
	private:
		key_compare		_compare;
		allocator_type	_allocator;
		tree_type		_tree;

	// *************** Additional functions ***************

		static bool
		compare(const value_type& val1, const value_type& val2) { return val1 < val2; }

		
	public:
	// *************** Constructors ***************
		explicit
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _allocator(alloc)
		{ 
			return; 
		}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		// {
		// 	return;
		// }

		map(const map& x)
		{
			if (this != &x)
			{
				if (x.size() != 0)
					insert(x.begin(), x.end());
			}
			return;
		}
	
	// *************** Destructor ***************
		~map(void) 
		{
			// deconstruct && deallocate
			return; 
		}
	
	// *************** Overload of operator= ***************
		map&
		operator= (const map& x) 
		{
			erase(begin(), end());
			if (x.size() != 0)
				insert(x.begin(), x.end());
			return *this;
		}

	// *************** Iterators ***************
		iterator
		begin(void)
		{
			iterator beg(this->_tree.getFirst());
			return ++beg;
		}
		
		// const_iterator
		// begin() const 
		// {
		// 	treeNode* root = this->_tree.getRoot();
		// 	const_iterator beg(this->_tree.min(root));
		// 	return beg;
		// }

		iterator
		end(void) 
		{
			iterator ending(this->_tree.getLast());
			return ending;
		}

		// const_iterator
		// end() const
		// {
		// 	treeNode*  = this->_tree.getRoot();
		// 	const_iterator ending(this->_tree.max(root));
		// 	return ++ending;
		// }

		reverse_iterator
		rbegin()
		{
			
			iterator rbeg(this->_tree.getLast());
			return --rbeg;
		}
		
		// const_reverse_iterator
		// rbegin() const
		// {
		// 	treeNode*  = this->_tree.getRoot();
		// 	const_reverse_iterator rbeg(this->_tree.max(root));
		// 	return rbeg;
		// }

		reverse_iterator
		rend()
		{
			iterator ending(this->_tree.getFirst());
			return ending;
		}

		// const_reverse_iterator
		// rend() const
		// {
		// 	treeNode*  = this->_tree.getRoot();
		// 	const_reverse_iterator rending(this->_tree.min(root));
		// 	return --ending;
		// }
		
	
	// *************** Capacity ***************
		bool
		empty(void) const { return this->_tree.size() == 0; }
		
		size_type
		size(void) const { return this->_tree.size(); }
		
		size_type
		max_size(void) const { return std::numeric_limits<difference_type>::max() / sizeof(ft::treeNode<Key, T> ); }
	
	// *************** Element access ***************
	
		mapped_type& operator[] (const key_type& k)
		{
			treeNode<Key, T>* node = this->_tree._findNode(k);
			if (node == NULL)
				node = this->_tree.insert(value_type(k, mapped_type()));
			return node->pair.second;
		}
	
	// *************** Modifiers ***************

		std::pair<iterator, bool>
		insert(const value_type& val)
		{
			bool res = false;
			treeNode<Key, T>* node = this->_tree.findNode(val.first);
	
			if (node == NULL || node == this->_tree.getFirst() || node == this->_tree.getLast())
			{
				node = this->_tree.insert(this->_tree.getRoot(), val);
				res = true;
			}
			std::pair<iterator, bool> pair(iterator(node), res);
			return pair;
		}
		
		iterator
		insert(iterator position, const value_type& val)
		{
			treeNode<Key, T>* node = this->_tree.findNode(val.first);
			if (node == NULL || node == this->_tree.getFirst() || node == this->_tree.getLast())
				node = this->_tree.insert(position.ptr, val);
			return iterator(node);
		}

		// template <class InputIterator>
  		// void
		// insert (InputIterator first, InputIterator last);

		void
		erase (iterator position)
		{
			this->_tree.deleteNode(position.ptr);
			return;
		}

		
		size_type
		erase (const key_type& k)
		{
			treeNode<Key, T>* toDelete = this->_tree.findNode(k);
			size_type deletedNodes = this->_tree.deleteNode(toDelete);
			
			this->_tree.print(this->_tree.getRoot(), "", true); //
			
			return deletedNodes;
		}

     	void
		erase (iterator first, iterator last)
		{
			iterator it = first;
			++it;
			while(first != last)
			{
				erase(first);
				// this->_tree.print(this->_tree.getRoot(), "", true);
				first = it;
				++it;
			}
		}

		
// 		void
// 		swap (map& x)
// 		{
// 			ft::map<T> temp(x);
// 			x = *this;
// 			*this = temp;
// 			return;
// 		}

// 		void
// 		resize (size_type n, value_type val = value_type())
// 		{
// 			if (this->map_size > n)
// 			{
// 				iterator it;
// 				for (it = begin(); n > 0; it++)
// 					n--;
// 				erase(it, end());
// 			}
// 			else if (this->map_size < n)
// 				insert(end(), n - this->map_size, val);
// 			return;			
// 		}

// 		void
// 		clear(void)
// 		{
// 			erase(begin(), end());
// 			return;
// 		}

// 	// *************** Operations ***************
// 		void
// 		splice (iterator position, map& x)
// 		{
// 			node * pos = position.ptr;
// 			iterator temp;
// 			for (iterator it = x.begin(); it != x.end(); it = temp)
// 			{
// 				it = x.begin();
// 				temp = ++(x.begin());
// 				it.ptr->prev = pos->prev;
// 				it.ptr->next = pos;
// 				pos->prev->next = it.ptr;
// 				pos->prev = it.ptr;
// 				this->map_size++;
// 				this->tail->value = map_size;
// 				if (pos == this->head)
// 					this->head = it.ptr;
// 				x.head = temp.ptr;
// 			}
// 			x.head = x.tail;
// 			x.tail->next = x.tail->prev = x.head;
// 			x.map_size = x.tail->value = 0;
// 			return;
// 		}

// 		void
// 		splice (iterator position, map& x, iterator i)
// 		{
// 			if (i == x.begin())
// 			{
// 				splice(position, x);
// 				return;
// 			}
// 			node * pos = position.ptr;
// 			node * tmp = i.ptr->prev;
// 			iterator temp;
// 			for (iterator it = i; it != x.end(); it = temp)
// 			{
// 				it = i;
// 				temp = ++i;
// 				it.ptr->prev = pos->prev;
// 				it.ptr->next = pos;
// 				pos->prev->next = it.ptr;
// 				pos->prev = it.ptr;
// 				this->map_size++;
// 				this->tail->value = map_size;
// 				if (pos == this->head)
// 					this->head = it.ptr;
// 				x.tail->value = --x.map_size;
// 			}
// 			x.tail->prev = tmp;
// 			tmp->next = x.tail;
// 			return;
// 		}

// 		void
// 		splice (iterator position, map& x, iterator first, iterator last)
// 		{
// 			if (last == x.end())
// 			{
// 				splice(position, x, first);
// 				return;
// 			}
// 			node * pos = position.ptr;
// 			node * tmp = first.ptr->prev;
// 			iterator temp;
// 			for (iterator it = first; it != last; it = temp)
// 			{
// 				it = first;
// 				temp = ++first;
// 				it.ptr->prev = pos->prev;
// 				it.ptr->next = pos;
// 				pos->prev->next = it.ptr;
// 				pos->prev = it.ptr;
// 				this->map_size++;
// 				this->tail->value = map_size;
// 				if (pos == this->head)
// 					this->head = it.ptr;
// 				x.tail->value = --x.map_size;
// 			}
// 			if (tmp == x.end().ptr)
// 				x.head = tmp;
// 			last.ptr->prev = tmp;
// 			tmp->next = last.ptr;
// 			return;
// 		}
		
// 		void
// 		remove (const value_type& val)
// 		{
// 			iterator it = begin();
// 			while (it != end())
// 			{
// 				if (*it == val)
// 					it = erase(it);
// 				else 
// 					it++;
// 			}
// 		}
		
// 		template <class Predicate>
//   		void 
// 		remove_if (Predicate pred)
// 		{
// 			iterator it = begin();
// 			while (it != end())
// 			{
// 				if (pred(*it))
// 					it = erase(it);
// 				else 
// 					it++;
// 			}
// 		}

// 		void
// 		unique(void)
// 		{
// 			iterator it = begin();
// 			iterator temp;
// 			while (it != end())
// 			{
// 				temp = it;
// 				++it;
// 				if (it != end() && *temp == *it)
// 				{
// 					erase(it);
// 					it = temp;
// 				}	
// 			}
// 			return;
// 		}

// 		template <class BinaryPredicate>
//   		void
// 		unique (BinaryPredicate binary_pred)
// 		{
// 			iterator it = begin();
// 			iterator temp;
// 			while (it != end())
// 			{
// 				temp = it;
// 				++it;
// 				if (it != end() && binary_pred(*it, *temp))
// 				{
// 					erase(it);
// 					it = temp;
// 				}	
// 			}
// 			return;
// 		}
		
// 		void
// 		merge (map& x) { merge(x, compare); }

// 		template <class Compare1>
// 		void
// 		merge (map& x, Compare1 comp)
// 		{
// 			if (this != &x)
// 			{
// 				iterator it1 = begin();
// 				iterator it2 = x.begin();
// 				iterator temp;
				
// 				while (it1 != end() && it2 != x.end())
// 				{
// 					if (comp(*it1, *it2))
// 						++it1;
// 					else
// 						splice(it1, x, it2, ++it2);
// 				}
// 				splice(it1, x);
// 			}
// 			return;
// 		}

// 		void
// 		sort(void) { sort(compare); }
		
// 		template <class Compare1>
// 		void
// 		sort (Compare1 comp)
// 		{
// 			for (iterator it = begin(); it!= end(); )
// 			{
// 				iterator min = it;
// 				for (iterator temp = it; temp != end(); ++temp)
// 					if (comp(*temp, *min))
// 						min = temp;
// 				if (min != it)
// 				{
// 					if (it.ptr == this->head)
// 						this->head = min.ptr;
// 					min.ptr->next->prev = min.ptr->prev;
// 					min.ptr->prev->next = min.ptr->next;
					
// 					min.ptr->next = it.ptr;
// 					min.ptr->prev = it.ptr->prev;
// 					it.ptr->prev->next = min.ptr;
// 					it.ptr->prev = min.ptr;
// 				}
// 				else
// 					++it;
// 			}
// 			return;
// 		}

// 		void
// 		reverse(void)
// 		{
// 			node * temp = NULL;
// 			for (iterator it = begin(); it != end(); it--)
// 			{
// 				temp = it.ptr->next;
// 				it.ptr->next = it.ptr->prev;
// 				it.ptr->prev = temp;
// 			}
// 			this->head = this->tail->prev;
// 			return;
// 		}
	};

// 	// *************** Non-member function overloads ***************

// 	template <class T, class Alloc>
// 	bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
// 	{
// 		if (lhs.size() == rhs.size())
// 		{
// 			typename ft::map<T>::iterator it1 = lhs.begin();
// 			typename ft::map<T>::iterator it2 = rhs.begin();
			
// 			while (it1 != lhs.end())
// 			{
// 				if (*it1 != *it2)
// 					return false;
// 				++it1;
// 				++it2;
// 			}
// 			return true;
// 		}
// 		return false;
// 	}

// 	template <class T, class Alloc>
// 	bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
// 	{
// 		return !(lhs == rhs);
// 	}

// 	template <class T, class Alloc>
// 	bool operator<  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
// 	{
// 		typename ft::map<T>::iterator it1 = lhs.begin();
// 		typename ft::map<T>::iterator it2 = rhs.begin();
		
// 		while (it1 != lhs.end() && it2 != rhs.end())
// 		{
// 			if (*it1 > *it2)
// 				return false;
// 			else if (*it1 < *it2)
// 				return true;
// 			++it1;
// 			++it2;
// 		}
// 		if (rhs.size() < lhs.size() || rhs.size() == lhs.size())
// 			return false;
// 		return true;
// 	}

// 	template <class T, class Alloc>
// 	bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
// 	{
// 		return !(rhs < lhs);
// 	}

// 	template <class T, class Alloc>
// 	bool operator>  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
// 	{
// 		return lhs < rhs;
// 	}

// 	template <class T, class Alloc>
// 	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
// 	{
// 		return !(lhs < rhs);
// 	}

// 	template <class T, class Alloc>
// 	void swap (map<T,Alloc>& x, map<T,Alloc>& y) { x.swap(y); return; }
}

#endif
