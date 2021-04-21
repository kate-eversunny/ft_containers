/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:30:24 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/19 18:13:46 by pvivian          ###   ########.fr       */
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
	template <class T1, class T2>
	struct pair {
		T1 first;
		T2 second;
		pair() {}
		pair(const T1& x, const T2& y) : first(x), second(y) {} 
	};

	template <class T1, class T2>
	inline bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y) { 
		return x.first == y.first && x.second == y.second;
	}

	template <class T1, class T2> 
	inline bool operator<(const pair<T1,T2>& x, const pair<T1,T2>& y) {
		return x.first < y.first 
			|| (!(y.first < x.first) && x.second < y.second);
	}

	template <class Key, class T, class Pair = ft::pair<Key, T> >
	struct treeNode
	{
		Pair 		pair;
		treeNode 	*parent;
		treeNode 	*left;
		treeNode 	*right;
		bool 		color;
		bool		isFirst;
		bool		isLast;
	};

	template <class Key, class T, class Pair =  ft::pair<Key, T> >
	class redBlackTree
	{
	private:
		typedef treeNode<Key, T>		node;
		typedef size_t					size_type;
		typedef Pair					value_type;
		typedef Key						key_type;
		
		node* _root;
		node* _first;
		node* _last;
		size_type _size;

	public:
		redBlackTree(void) 
		{
			_root = _newNode(value_type());
			_first = _newNode(value_type());
			_last = _newNode(value_type());
			
			_root->color = BLACK_NODE;
			_root->left = _first;
			_root->right = _last;
			
			_first->color = _last->color = BLACK_NODE;
			_first->isFirst = _last->isLast = true;
			_first->parent = _last->parent = _root;
			_size = 0;
		}

		~redBlackTree(void)
		{
			delete this->_first;
			delete this->_last;
			return;
		}

		node*
		insert(node* hint, const value_type& val)
		{
			node* newNode;
			if (this->_size == 0)
			{
				this->_root->pair.operator=(val);
				newNode = this->_root;
			}
			else
			{
				newNode = _newNode(val);
				node* parent = _findParent(hint, val);
				newNode->parent = parent;
				if (parent->pair.first > newNode->pair.first)
				{
					newNode->left = parent->left;
					newNode->left->parent = newNode;
					parent->left = newNode;
				}
				else
				{
					newNode->right = parent->right;
					newNode->right->parent = newNode;
					parent->right = newNode;
				}
				_rebalanceAfterInsert(newNode);
			}
			this->_size++;
			return newNode;
		}

		size_type
		deleteNode(node* toDelete)
		{
			node* replacement = NULL;
			bool originalColor;
			size_type deletedNodes = 0;

			if (toDelete == NULL || toDelete == this->_first || toDelete == this->_last)
				return deletedNodes;
			originalColor = toDelete->color;
			if (toDelete->left == NULL || toDelete->right == NULL)
				_cutNodeWithOneOrNoChildren(toDelete, &replacement);
			else
				_cutNodeWithTwoChildren(toDelete, &originalColor);
			delete toDelete;
			this->_size--;
			if (originalColor == BLACK_NODE && replacement != NULL)
				_rebalanceAfterDelete(replacement);
			return ++deletedNodes;
		}

		node*
		getRoot(void)
		{
			return this->_root;
		}

		node*
		getFirst(void)
		{
			return this->_first;
		}

		node*
		getLast(void)
		{
			return this->_last;
		}

		node*
		findNode(const key_type& key)
		{
			node* current = this->_root;
			while (current != NULL && current != this->_first && current != this->_last)
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
		
		void
		print(node* root, std::string indent, bool right)
		{
			if (root == NULL || root == this->_first || root == this->_last)
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

		node*
		min(node* node)
		{
   			while (node->left != NULL && node->left != this->_first)
				node = node->left;
    		return node;
  		}

		node*
		max(node* node)
		{
   			while (node->right != NULL && node->right != this->_last)
				node = node->right;
    		return node;
  		}

		size_type
		size(void)
		{
			return this->_size;
		}
  
	private:
		node*
		_newNode(const value_type& val)
		{
			node* newNode = new node;
			newNode->parent = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->pair.operator=(val);
			newNode->color = RED_NODE;
			newNode->isFirst = false;
			newNode->isLast = false;
			return newNode;
		}
		
		node*
		_findParent(node* current, const value_type& val)
		{
			node* parent = NULL;
			
			// if (current != this->_root)
			// {
			// 	if (current == current->parent->left)
			// 	{
			// 		if (current->parent )
			// 	}
			// }
			while (current != NULL && current != this->_first && current != this->_last) 
			{
				parent = current;
				if (val.first < current->pair.first)
					current = current->left;
				else
					current = current->right;
			}
			return parent;
		}

		void
		_cutNodeWithOneOrNoChildren(node* toDelete, node** replacement)
		{
			if (toDelete->left == NULL)
				*replacement = toDelete->right;
			else
				*replacement = toDelete->left;
			_replace(toDelete, *replacement);
		}

		void
		_cutNodeWithTwoChildren(node* toDelete, bool* originalColor)
		{
			node* replacingNode;

			replacingNode = min(toDelete->right);
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
		
		void
		_replace(node* toReplace, node *toInsert)
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
		
		void
		_leftRotate(node* x)
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

		void
		_rightRotate(node* x)
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

		void
		_rebalanceAfterInsert(node* newNode)
		{
			node* uncle;
			while (newNode != this->_root && newNode->parent->color == RED_NODE)
			{
				uncle = newNode->parent->parent->right;
				if (newNode->parent == newNode->parent->parent->right)
					uncle = newNode->parent->parent->left;
				if (uncle != NULL && uncle != this->_last && uncle->color == RED_NODE)
					_recolorIfUncleRed(&newNode, uncle);
				else 
				{
					if (newNode->parent == newNode->parent->parent->right)
						_rebalanceIfParentRight(newNode);
					else
						_rebalanceIfParentLeft(newNode);
				}
			}
			this->_root->color = BLACK_NODE;
		}

		void
		_recolorIfUncleRed(node **newNode, node *uncle)
		{
			uncle->color = (*newNode)->parent->color = BLACK_NODE;
			(*newNode)->parent->parent->color = RED_NODE;
			(*newNode) = (*newNode)->parent->parent;
			return;
		}

		void
		_rebalanceIfParentRight(node *newNode)
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

		void
		_rebalanceIfParentLeft(node *newNode)
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
		
		void
		_rebalanceAfterDelete(node* x)
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
					if ((!s->left || s->left->color == BLACK_NODE) && (!s->right || s->right->color == BLACK_NODE))
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
	};
}
#endif
