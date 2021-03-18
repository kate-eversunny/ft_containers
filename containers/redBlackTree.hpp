/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:30:24 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/18 21:54:38 by pvivian          ###   ########.fr       */
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
		typedef treeNode<Key, T>						node;
		typedef size_t									size_type;
		typedef typename std::pair<const Key, T>		value_type;
		typedef Key										key_type;
		
		node* _root;
		size_type _size;

	public:
		redBlackTree(void) 
		{
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

		size_type deleteNode(key_type key)
		{
			node* replacement = NULL;
			bool originalColor;
			size_type deletedNodes = 0;
			node* toDelete = _findNode(key);

			if (toDelete == NULL)
				return deletedNodes;
			originalColor = toDelete->color;
			if (toDelete->left == NULL || toDelete->right == NULL)
				_cutNodeWithOneOrNoChildren(toDelete, replacement);
			else
				_cutNodeWithTwoChildren(toDelete, &originalColor);
			delete toDelete;
			if (originalColor == BLACK_NODE && replacement != NULL)
				_rebalanceAfterDelete(replacement);
			return ++deletedNodes;
		}

	void _rebalanceAfterDelete(node* x)
	{
		node* s;
		while (x != this->_root && x->color == BLACK_NODE)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == RED_NODE)
				{
					s->color = BLACK_NODE;
					x->parent->color = RED_NODE;
					_leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == BLACK_NODE && s->right->color == BLACK_NODE)
				{
					s->color = RED_NODE;
					x = x->parent;
				}
				else
				{
					if (s->right->color == BLACK_NODE)
					{
						s->left->color = BLACK_NODE;
						s->color = RED_NODE;
						_rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK_NODE;
					s->right->color = BLACK_NODE;
					_leftRotate(x->parent);
					x = this->_root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->color == RED_NODE)
				{
					s->color = BLACK_NODE;
					x->parent->color = RED_NODE;
					_rightRotate(x->parent);
					s = x->parent->left;
				}
				if (s->right->color == BLACK_NODE && s->right->color == BLACK_NODE)
				{
					s->color = RED_NODE;
					x = x->parent;
				}
				else
				{
					if (s->left->color == BLACK_NODE)
					{
						s->right->color = BLACK_NODE;
						s->color = RED_NODE;
						_leftRotate(s);
						s = x->parent->left;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK_NODE;
					s->left->color = BLACK_NODE;
					_rightRotate(x->parent);
					x = this->_root;
				}
			}
		}
		x->color = BLACK_NODE;
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
		
		node* _findNode(const key_type& key)
		{
			node* current = this->_root;
			while (current != NULL)
			{
				if (current->pair.first == key)
					break;
				else if (current->pair.first <= key)
					current = current->right;
				else
					current = current->left;
			}
			return current;
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

		node* _min(node* node)
		{
   			while (node->left != NULL)
				node = node->left;
    		return node;
  		}

		void _cutNodeWithOneOrNoChildren(node* toDelete, node* replacement)
		{
			if (toDelete->left == NULL)
				replacement = toDelete->right;
			else
				replacement = toDelete->left;
			_replace(toDelete, replacement);
		}

		void _cutNodeWithTwoChildren(node* toDelete, bool* originalColor)
		{
			node* replacingNode;

			replacingNode = _min(toDelete->right);
			*originalColor = replacingNode->color;
			if (replacingNode->parent != toDelete)
			{
				replacingNode->parent->left = replacingNode->right;
				replacingNode->right = toDelete->right;
			}
			_replace(toDelete, replacingNode);
			replacingNode->left = toDelete->left;
			if (replacingNode->right != NULL)
				replacingNode->right->parent = replacingNode;
			replacingNode->left->parent = replacingNode;
			replacingNode->color = toDelete->color;
		}
		
		void _replace(node* toReplace, node *toInsert)
		{
			if (toReplace == this->_root)
				this->_root = toInsert;
			else if (toReplace == toReplace->parent->left)
				toReplace->parent->left = toInsert;
			else
				toReplace->parent->right = toInsert;
			if (toInsert != NULL)
				toInsert->parent = toReplace->parent;
		}
		
		void _leftRotate(node* x)
		{
			node* y = x->right;
			if (y == NULL)
				return;
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

		void _rightRotate(node* x)
		{
			node* y = x->left;
			if (y == NULL)
				return;
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
		
		void print(node* root,std::string indent, bool right)
		{
			if (root == NULL)
				return;
			std::string sColor = root->color ? RED : NORMAL;
			std::cout << indent;
			if (right)
			{
				std::cout << " R----";
				indent += "   ";
			}
			else
			{
				std::cout << " L----";
				indent += "|  ";
			}
			std::cout << sColor << root->pair.first << " " << root->pair.second << NORMAL << std::endl;
			print(root->left, indent, false);
			print(root->right, indent, true);
 		}
	};
}
#endif
