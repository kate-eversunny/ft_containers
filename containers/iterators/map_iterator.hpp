/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:26:44 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/23 17:33:22 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "redBlackTree.hpp"

namespace ft
{
	template <class Key, class T, class Pair>
	struct treeNode;
	
	template <class Key, class T>
  	struct map_iterator 
	{
	private:
		typedef treeNode<Key, T>						node;
		typedef typename std::pair<const Key, T>		value_type;
		typedef value_type*								pointer;
		typedef value_type& 							reference;

	public:
		node *ptr;
	
	// *************** Constructors ***************

		map_iterator() : ptr(NULL) { return; }

		map_iterator(node* new_ptr) : ptr(new_ptr) { return; }

		map_iterator(map_iterator const & toCopy) 
		{
			ptr = toCopy.ptr;
			return ;
		}

		map_iterator & operator= (map_iterator const & toCopy)
		{
			if (this != &toCopy)
				ptr = toCopy.ptr;
			return *this;
		}
	
	// *************** Destructor ***************
		~map_iterator(void) { return ; }
	
	// *************** Member functions ***************
		bool operator==(map_iterator const & other) const { return this->ptr==other.ptr; }
		
		bool operator!=(map_iterator const & other) const { return this->ptr!=other.ptr; }
		
		reference operator*(void) const { return this->ptr->pair; }

		pointer operator->(void) const { return &this->ptr->pair; }
		
		map_iterator & operator++(void)
		{
			node* current;
			if (this->ptr->isFirst)
				this->ptr = this->ptr->parent;
			else if (this->ptr->isLast)
				return *this;
			else if (this->ptr->right)
				this->ptr = min(this->ptr->right);
			else if (this->ptr->parent)
			{
				current = this->ptr->parent;
				while (current->pair.first <= this->ptr->pair.first)
					current = current->parent;
				this->ptr = current;
			}
			return *this;
		}

		map_iterator operator++(int)
		{
			map_iterator temp(*this);
			node* current;
			if (this->ptr->isFirst)
				this->ptr = this->ptr->parent;
			else if (this->ptr->isLast)
				return temp;
			else if (this->ptr->right)
				this->ptr = min(this->ptr->right);
			else if (this->ptr->parent)
			{
				current = this->ptr->parent;
				while (current->pair.first <= this->ptr->pair.first)
					current = current->parent;
				this->ptr = current;
			}
			return temp;
		}

		map_iterator & operator--(void)
		{
			node* current;
			if (this->ptr->isLast)
				this->ptr = this->ptr->parent;
			else if (this->ptr->isFirst)
				return *this;
			else if (this->ptr->left)
				this->ptr = max(this->ptr->left);
			else if (this->ptr->parent)
			{
				current = this->ptr->parent;
				while (current->pair.first >= this->ptr->pair.first)
					current = current->parent;
				this->ptr = current;
			}
			return *this;
		}

		map_iterator  operator--(int)
		{
			map_iterator temp(*this);
			node* current;
			if (this->ptr->isLast)
				this->ptr = this->ptr->parent;
			else if (this->ptr->isFirst)
				return temp;
			else if (this->ptr->left)
				this->ptr = max(this->ptr->left);
			else if (this->ptr->parent)
			{
				current = this->ptr->parent;
				while (current->pair.first >= this->ptr->pair.first)
					current = current->parent;
				this->ptr = current;
			}
			return temp;
		}
		
		private:
		
		node*
		min(node* node)
		{
   			while (node->left != NULL)
				node = node->left;
    		return node;
  		}

		node*
		max(node* node)
		{
   			while (node->right != NULL)
				node = node->right;
    		return node;
  		}
  	};

  	template <class Key, class T>
  	struct const_map_iterator : public map_iterator<Key, T>
	{
	private:
		typedef treeNode<Key, T>						node;
		typedef typename std::pair<const Key, T>		value_type;
		typedef const value_type*						const_pointer;
		typedef const value_type& 						const_reference;
	
	public:
	// *************** Constructors ***************

		const_map_iterator() { return; }

		const_map_iterator(node* new_ptr) { this->ptr = new_ptr; return; }

		const_map_iterator(const_map_iterator const & toCopy) : map_iterator<Key, T>(toCopy)
		{
			this->ptr = toCopy.ptr;
			return;
		}

		const_map_iterator(map_iterator<Key, T> const & toCopy) : map_iterator<Key, T>(toCopy)
		{
			this->ptr = toCopy.ptr;
			return;
		}

		const_map_iterator & operator= (const_map_iterator const & toCopy)
		{
			if (this != &toCopy)
				this->ptr = toCopy.ptr;
			return *this;
		}
	
		const_map_iterator & operator= (map_iterator<Key, T> const & toCopy)
		{
			if (this != &toCopy)
				this->ptr = toCopy.ptr;
			return *this;
		}
	// *************** Destructor ***************
		~const_map_iterator(void) { return ; }
	
	// *************** Member functions ***************
		const_reference operator*(void) const { return this->ptr->pair; }
		const_pointer operator->(void) const { return &this->ptr->pair; }
	};
}

#endif
