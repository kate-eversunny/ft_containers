/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:28:19 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/09 18:51:51 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
// # include <limits.h>
# include <exception>
# include <memory>
# include "vector_iterator.hpp"

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> > 
	class vector
	{
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef vector_iterator<T>								iterator;
		typedef vector_iterator<T>						const_iterator;
		typedef vector_reverse_iterator<T>						reverse_iterator;
		typedef vector_reverse_iterator<T>				const_reverse_iterator;
	
	private:
		allocator_type		_allocator;
		pointer				_start;
		pointer				_finish;
		pointer				_end_of_storage;
		size_type			_size;
		

		size_type _check_init_len(size_type n)
		{
			if (n > max_size())
				throw std::range_error("cannot create ft::vector larger than max_size");
			return n;
		}
	
	public:
	
	/* ******************* Constructors ******************* */
		explicit vector( const allocator_type& alloc = allocator_type()) : _allocator(alloc), _start(), _finish(), _end_of_storage(), _size(0) { return; }
		
		explicit vector( size_type n, const T& value = value_type(), const allocator_type& alloc = allocator_type() ) : _allocator(alloc)
		{
			_start = _allocator.allocate(_check_init_len(n));
			_finish = _start;
			_end_of_storage = _start + n;
			_size = 0;

			for (pointer i = _start; i != _end_of_storage; i++, ++_size)
				_allocator.construct(i, value);
			_finish = _start + n - 1;
			return;
		}
		
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _allocator(alloc)
		// {
			
		// }
		
		vector(vector const & x)
		{
			this->_allocator = allocator_type(x._allocator);
			size_type capacity = x.capacity();
			this->_start = _allocator.allocate(_check_init_len(capacity));
			this->_finish = this->_start;
			this->_end_of_storage = this->_start + capacity;
			
			iterator it = x.begin();
			for (pointer i = this->_start; i != _end_of_storage; i++, it++)
				_allocator.construct(i, *it);
			this->_size = x.size();
			this->_finish = this->_start + this->_size - 1;
			return;
		}

	/* ******************* Destructor ******************* */
		~vector(void) 
		{
			// destroying
			// deallocating
		}

	/* ******************* Operator= overload ******************* */
		vector & operator=(vector const & x)
		{
			size_type size = x.size();
			_allocator = x._allocator;
			if (this->capacity() < size)
			{
				_allocator.deallocate(this->_start, this->capacity());
				this->_start = _allocator.allocate(_check_init_len(size));
				this->_finish = this->_start;
				this->_end_of_storage = this->_start + size;
			}
			iterator x_beg;
			pointer i = this->_start;
			for (x_beg = x.begin(); x_beg != x.end(); x_beg++)
			{
				_allocator.construct(i, *x_beg);
				++i;
			}
			_finish = _start + size - 1;
			_size = size;
			return *this;
		}

	/* ******************* Iterators ******************* */

		iterator
		begin() { iterator beg(_start); return beg; }
		
		const_iterator
		begin() const { const_iterator beg(_start); return beg;}
		
		iterator
		end() 
		{
			pointer i = _finish;
			if (this->_size)
				++i;
			iterator ending(i); 
			return ending;
		}
		
		const_iterator
		end() const 
		{
			pointer i = _finish;
			if (this->_size)
				++i;
			const_iterator ending(i);
			return ending;
		}
		
		reverse_iterator
		rbegin() { reverse_iterator beg(_finish); return beg; }
		
		const_reverse_iterator
		rbegin() const {const_reverse_iterator beg(_finish); return beg; }
		
		reverse_iterator
		rend() 
		{
			pointer i = _start;
			if (this->_size)
				--i;
			reverse_iterator ending(i); 
			return ending;
		}
		
		const_reverse_iterator
		rend() const 
		{
			pointer i = _start;
			if (this->_size)
				--i;
			const_reverse_iterator ending(i);
			return ending;
		}
		
	/* ******************* Capacity ******************* */
		size_type size() const { return this->_size; }

		size_type max_size() const { return _allocator.max_size(); }

		void resize (size_type n, value_type val = value_type());

		size_type capacity() const { return size_type (this->_end_of_storage - this->_start); }

		bool empty() const { return _size == 0; }

		void reserve (size_type n);

	/* ******************* Element access ******************* */
	
		reference operator[] (size_type n);

		const_reference operator[] (size_type n) const;

		reference at (size_type n);
		
		const_reference at (size_type n) const;

		reference front();

		const_reference front() const;

    	reference back();
		
		const_reference back() const;

	/* ******************* Modifiers ******************* */	

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);
		
		void assign (size_type n, const value_type& val);

		void push_back (const value_type& val)
		{
			if (this->_size == this->capacity())
			{
				// allocate capacity * 2
				// copy values
				// insert new value
				// destroy && deallocate previous values
				// save finish, start, size, end_of_storage
			}
			else
			{
				++(this->_finish);
				*(this->_finish) = val;
				this->_size++;
			}
		}

		void pop_back();

		iterator insert (iterator position, const value_type& val);
		
		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);

		iterator erase (iterator first, iterator last);

		void swap (vector& x);
		
		void clear();
	};

	/* ******************* Non-member functions ******************* */	

		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
  		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
