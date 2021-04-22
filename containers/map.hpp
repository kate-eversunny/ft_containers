/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:25:38 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/22 21:02:45 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef> //for fundamental types
# include "redBlackTree.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "allocator.hpp"
# include <limits>
# include <type_traits>
# include <iostream>
# include <functional>

namespace ft
{	
	template <class Key, class T,
			class Compare = std::less<Key>,
			class Allocator = ft::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		
		typedef Key															key_type;
		typedef T 															mapped_type;
		typedef typename ft::pair<const key_type, mapped_type>				value_type;
		typedef Compare														key_compare;
		typedef Allocator													allocator_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef value_type*													pointer;
		typedef const value_type*											const_pointer;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;
		typedef typename ft::map_iterator<key_type, mapped_type>			iterator;
		typedef typename ft::const_map_iterator<key_type, mapped_type>		const_iterator;
		typedef typename ft::reverse_iterator<value_type, iterator>			reverse_iterator;
		typedef typename ft::const_reverse_iterator<value_type, iterator>	const_reverse_iterator;
		typedef typename ft::redBlackTree<key_type, mapped_type>			tree_type;
	
		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			key_compare comp;
			value_compare (key_compare c) : comp(c) {}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

	
	private:
		key_compare		_compare;
		allocator_type	_allocator;
		value_compare 	_val_compare;
		tree_type		_tree;

	public:
	// *************** Constructors ***************
		explicit
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _allocator(alloc), _val_compare(value_compare(comp))
		{ 
			return; 
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), 
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _compare(comp), _allocator(alloc), _val_compare(value_compare(comp))
		{
			insert(first, last);
			return;
		}

		map(map const & x) : _val_compare(value_compare(key_compare()))
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
			clear();
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
		
		const_iterator
		begin() const 
		{
			const_iterator beg(this->_tree.getFirst());
			return ++beg;
		}

		iterator
		end(void) 
		{
			iterator ending(this->_tree.getLast());
			return ending;
		}

		const_iterator
		end() const
		{
			const_iterator ending(this->_tree.getLast());
			return ending;
		}

		reverse_iterator
		rbegin()
		{
			
			reverse_iterator rbeg(this->_tree.getLast());
			return ++rbeg;
		}
		
		const_reverse_iterator
		rbegin() const
		{
			const_reverse_iterator rbeg(this->_tree.getLast());
			return ++rbeg;
		}

		reverse_iterator
		rend()
		{
			reverse_iterator ending(this->_tree.getFirst());
			return ending;
		}

		const_reverse_iterator
		rend() const
		{
			const_reverse_iterator ending(this->_tree.getFirst());
			return ending;
		}
		
	
	// *************** Capacity ***************
		bool
		empty(void) const { return this->_tree.size() == 0; }
		
		size_type
		size(void) const { return this->_tree.size(); }
		
		size_type
		max_size(void) const { return std::numeric_limits<difference_type>::max() / sizeof(ft::treeNode<key_type, mapped_type> ); }
	
	// *************** Element access ***************
	
		mapped_type& operator[] (const key_type& k)
		{
			treeNode<key_type, mapped_type>* node = this->_tree._findNode(k);
			if (node == NULL)
			{
				_check_init_len(this->size() + 1);
				node = this->_tree.insert(value_type(k, mapped_type()));
			}
			return node->pair.second;
		}
	
	// *************** Modifiers ***************

		ft::pair<iterator, bool>
		insert(const value_type& val)
		{
			bool res = false;
			treeNode<key_type, mapped_type>* node = this->_tree.findNode(val.first);
	
			if (node == NULL || node == this->_tree.getFirst() || node == this->_tree.getLast())
			{
				_check_init_len(this->size() + 1);
				node = this->_tree.insert(this->_tree.getRoot(), val);
				res = true;
			}
			ft::pair<iterator, bool> pair(iterator(node), res);
			return pair;
		}
		
		iterator
		insert(iterator position, const value_type& val)
		{
			treeNode<key_type, mapped_type>* node = this->_tree.findNode(val.first);
			if (node == NULL || node == this->_tree.getFirst() || node == this->_tree.getLast())
			{
				_check_init_len(this->size() + 1);
				node = this->_tree.insert(position.ptr, val);
			}
			return iterator(node);
		}

		template <class InputIterator>
  		void
		insert (InputIterator first, InputIterator last,
				typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			while(first != last)
			{
				insert(*first);
				++first;
			}
			return;
		}

		void
		erase (iterator position)
		{
			this->_tree.deleteNode(position.ptr);
			return;
		}

		
		size_type
		erase (const key_type& k)
		{
			treeNode<key_type, mapped_type>* toDelete = this->_tree.findNode(k);
			size_type deletedNodes = this->_tree.deleteNode(toDelete);
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
				first = it;
				++it;
			}
		}

		void
		swap (map& x)
		{
			ft::map<key_type, mapped_type> temp(x);
			x = *this;
			*this = temp;
			return;
		}

		void
		clear(void)
		{
			erase(begin(), end());
			return;
		}

// 	// *************** Observers ***************

		key_compare
		key_comp() const
		{
			return this->_compare;
		}

		value_compare
		value_comp() const
		{
			return this->_val_compare;
		}

// 	// *************** Operations ***************
		iterator
		find (const key_type& k)
		{
			treeNode<key_type, mapped_type> *node = this->_tree.findNode(k);
			if (!node)
				return end();
			return iterator(node);
		}
		
		const_iterator
		find (const key_type& k) const
		{
			treeNode<key_type, mapped_type> *node = this->_tree.findNode(k);
			if (!node)
				return end();
			return const_iterator(node);
		}

		size_type
		count (const key_type& k) const
		{
			if (find(k) == end())
				return 0;
			return 1;
		}

		iterator
		lower_bound (const key_type& k)
		{
			return find(k);
		}
		
		const_iterator
		lower_bound (const key_type& k) const
		{
			return find(k);
		}
		

		iterator
		upper_bound (const key_type& k)
		{
			iterator it = find(k);
			if (it == end())
				return it;
			return ++it;
		}
		
		const_iterator
		upper_bound (const key_type& k) const
		{
			const_iterator it = find(k);
			if (it == end())
				return it;
			return ++it;
		}

		ft::pair<const_iterator, const_iterator>
		equal_range (const key_type& k) const
		{
			return ft::pair<const_iterator, const_iterator> (lower_bound(k), upper_bound(k));
		}
		
		ft::pair<iterator, iterator>
		equal_range (const key_type& k)
		{
			return ft::pair<iterator, iterator> (lower_bound(k), upper_bound(k));
		}
	
// 	// *************** Additional functions***************
private:
		size_type
		_check_init_len(size_type n)
		{
			if (n > max_size())
				throw std::range_error("cannot create ft::map larger than max_size()");
			return n;
		}
	};
}

#endif
