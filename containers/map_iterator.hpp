/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:26:44 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/01 16:45:22 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <cstddef> //for fundamental types
# include "redBlackTree.hpp"

namespace ft
{
	template <class Key, class T>
	struct treeNode;
	
	template <class Key, class T>
  	struct map_iterator 
	{
	private:
		typedef treeNode<Key, T>						node;
		typedef size_t									size_type;
		typedef typename std::pair<Key, T>				value_type;
		typedef Key										key_type;
		typedef ptrdiff_t								difference_type;
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
  	struct reverse_map_iterator 
	{
	private:
		typedef typename std::pair<Key, T>			value_type;
		typedef ptrdiff_t							difference_type;
		typedef typename ft::treeNode<Key, T>		node;
		typedef value_type*							pointer;
		typedef value_type& 						reference;
		typedef typename ft::map_iterator<Key, T>	iterator_type;

		iterator_type base_iterator;
	
	public:
	
	// *************** Constructors ***************

		reverse_map_iterator() { iterator_type base_iterator; return; }

		explicit reverse_map_iterator(iterator_type it) { iterator_type base_iterator(it); return; }

		reverse_map_iterator (const reverse_map_iterator<Key, T>& toCopy)
		{
			iterator_type base_iterator(toCopy.base_iterator);
			return ;
		}
	
	// *************** Destructor ***************
		~reverse_map_iterator(void) { return ; }
	
	// *************** Member functions ***************
		iterator_type base() const { return this->base_iterator; }

		reference operator*(void) const { return *this->base_iterator; }

		pointer operator->(void) const { return &this->base_iterator; }
		
		reverse_map_iterator & operator++(void)
		{
			this->base_iterator--;
			return *this;
		}

		reverse_map_iterator operator++(int)
		{
			reverse_map_iterator temp(*this);
			this->base_iterator--;
			return temp;
		}
		
		reverse_map_iterator & operator--(void)
		{
			this->base_iterator++;
			return *this;
		}

		reverse_map_iterator operator--(int)
		{
			reverse_map_iterator temp(*this);
			this->base_iterator++;
			return temp;
		}

		bool operator==(reverse_map_iterator const & other) const { return this->base_iterator==other.base_iterator; }
		
		bool operator!=(reverse_map_iterator const & other) const { return this->base_iterator!=other.base_iterator; }
  };
}

#endif
