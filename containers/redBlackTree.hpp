/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:30:24 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/17 21:03:01 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <utility>
# include <iostream>

# define BLACK_NODE false
# define RED_NODE 	true

# define RED		"\x1b[31m"
# define NORMAL		"\x1b[0m"

namespace ft
{
	template <class Key, class T>
	struct treeNode
	{
		std::pair<Key, T> pair;
		treeNode *parent;
		treeNode *left;
		treeNode *right;
		bool color;
	};

	template <class Key, class T>
	class redBlackTree
	{
	private:
		typedef treeNode<Key, T>							node;
		typedef size_t									size_type;
		typedef typename std::pair<const Key, T>		value_type;
		
		node* _root;
		size_type _size;

	public:
		redBlackTree(void) 
		{
			// _root = new node;
			// _root->parent = NULL;
			// _root->left = NULL;
			// _root->right = NULL;
			_root = _newNode(value_type());
			_root->color = BLACK_NODE;
			_size = 0;
		}

		~redBlackTree(void)
		{
			//clear and deallocate
		}

		void insert(const value_type& val)
		{
			if (this->_size == 0)
				this->_root->pair.operator=(val);
			else
			{
				node* newNode = _newNode(val);
				node* parent = _findParent(val);
				newNode->parent = parent;
				if (parent->pair.first > newNode->pair.first)
					parent->left = newNode;
				else
					parent->right = newNode;
				_rebalanceAfterInsert(newNode);
			}
			this->_size++;
		}
	
	private:
		node* _newNode(const value_type& val)
		{
			node* newNode = new node;
			newNode->parent = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->pair.operator=(val);
			newNode->color = RED_NODE;
			return newNode;
		}
		
		node* _findParent(const value_type& val)
		{
			node* parent = NULL;
			node* current = this->_root;
			
			while (current != NULL) 
			{
				parent = current;
				if (val.first < current->pair.first)
					current = current->left;
				else
					current = current->right;
			}
			return parent;
		}

		void _leftRotate(node* x)
		{
			node* y = x->right;
			if (y != NULL)
			{
				x->right = y->left;
				if (x->right != NULL)
					x->right->parent = x;
				if (x == this->_root)
					this->_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->parent = x->parent;
				y->left = x;
				x->parent = y;	
			}
		}

		void _rightRotate(node* x)
		{
			node* y = x->left;
			if (y != NULL)
			{
				x->left = y->right;
				if (x->left != NULL)
					x->left->parent = x;
				if (x == this->_root)
					this->_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->parent = x->parent;
				y->right = x;
				x->parent = y;	
			}
		}

		void _rebalanceAfterInsert(node* newNode)
		{
			node* uncle;
			while (newNode->parent->color == RED_NODE)
			{
				if (newNode->parent == newNode->parent->parent->right)
					uncle = newNode->parent->parent->left;
				else
					uncle = newNode->parent->parent->right;
				if (uncle != NULL && uncle->color == RED_NODE)
				{
					uncle->color = BLACK_NODE;
					newNode->parent->color = BLACK_NODE;
					newNode->parent->parent->color = RED_NODE;
					newNode = newNode->parent->parent;
				}
				else 
				{
					if (newNode->parent == newNode->parent->parent->right)
					{
						if (newNode == newNode->parent->left)
						{
							newNode = newNode->parent;
							_rightRotate(newNode);
						}
						newNode->parent->color = BLACK_NODE;
						newNode->parent->parent->color = RED_NODE;
						_leftRotate(newNode->parent->parent);
					}
					else
					{
						if (newNode == newNode->parent->right)
						{
							newNode = newNode->parent;
							_leftRotate(newNode);
						}
						newNode->parent->color = BLACK_NODE;
						newNode->parent->parent->color = RED_NODE;
						_rightRotate(newNode->parent->parent);
					}
				}
				if (newNode == this->_root)
					break;
			}
			this->_root->color = BLACK_NODE;
		}
		public:
		node* getRoot(void)
		{
			return this->_root;
		}
		
		void print(node* root,std::string indent, bool last)
		{
			if (root != NULL)
			{
				std::string sColor = root->color ? RED : NORMAL;
				std::cout << indent;
				if (last)
				{
					std::cout << " R----";
					indent += "   ";
				}
				else
				{
					std::cout << " L----";
					indent += "|  ";
				}
				std::cout << sColor << root->pair.first << NORMAL << std::endl;
				
				print(root->left, indent, false);
				print(root->right, indent, true);
    		}
 		}
	};
}
#endif
