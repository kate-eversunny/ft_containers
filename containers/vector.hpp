/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:28:19 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/21 17:48:44 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <exception>
# include "allocator.hpp"
# include <limits>
# include <type_traits>
# include "vector_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template<class T, class Allocator = ft::allocator<T> > 
	class vector
	{
	public:
		typedef T															value_type;
		typedef Allocator													allocator_type;
		typedef typename std::size_t										size_type;
		typedef typename std::ptrdiff_t										difference_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef value_type*													pointer;
		typedef const value_type*											const_pointer;
		typedef typename ft::vector_iterator<value_type>					iterator;
		typedef typename ft::const_vector_iterator<value_type>				const_iterator;
		typedef typename ft::reverse_iterator<value_type, iterator>			reverse_iterator;
		typedef typename ft::const_reverse_iterator<value_type, iterator>	const_reverse_iterator;
	
	private:
		allocator_type		_allocator;
		pointer				_start;
		pointer				_finish;
		pointer				_end_of_storage;
		size_type			_size;
		
	public:
	
	/* ******************* Constructors ******************* */
		explicit
		vector( const allocator_type& alloc = allocator_type()) : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0), _size(0) 
		{
			return;
		}
		
		explicit
		vector( size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type() ) : _allocator(alloc)
		{
			this->_start = this->_allocator.allocate(_check_init_len(n));
			this->_size = n;
			this->_end_of_storage = this->_start + this->_size;
			_setFinish();
			for (pointer i = this->_start; i != this->_end_of_storage; i++)
				_allocator.construct(i, value);
			return;
		}
		
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0): _allocator(alloc)
		{
			InputIterator it = first;
			size_type newSize = 0;
			pointer i;
			
			for (; it != last; it++)
				++newSize;
			this->_start = i = this->_allocator.allocate(_check_init_len(newSize));
			this->_size = newSize;
			this->_end_of_storage = this->_start + this->_size;
			_setFinish();
			for (; first != last; i++, first++)
				this->_allocator.construct(i, *first);
			return;
		}
		
		vector(vector const & x)
		{
			this->_allocator = allocator_type(x._allocator);
			size_type capacity = x.capacity();
			this->_start = this->_allocator.allocate(_check_init_len(capacity));
			this->_end_of_storage = this->_start + capacity;
			this->_size = x.size();
			_setFinish();
			if (this->_size != 0)
				_construct(x.begin(), this->_finish);
			return;
		}

	/* ******************* Destructor ******************* */
		~vector(void) 
		{
			if (this->capacity() > 0)
			{
				clear();
				this->_allocator.deallocate(this->_start, this->capacity());
			}
			return;
		}

	/* ******************* Operator= overload ******************* */
		vector & 
		operator=(vector const & x)
		{
			size_type size = x.size();
			this->_allocator = x._allocator;
			if (this->capacity() < size)
				_reallocate(size);
			this->_size = size;
			_setFinish();
			iterator it = x.begin();
			for (pointer i = this->_start; i != this->_end_of_storage; i++, it++)
				*i = *it;
			return *this;
		}

	/* ******************* Iterators ******************* */

		iterator
		begin(void)
		{
			iterator beg(_start);
			return beg;
		}
		
		const_iterator
		begin(void) const 
		{
			const_iterator beg(_start);
			return beg;
		}
		
		iterator
		end(void) 
		{
			pointer i = _finish;
			if (this->_size)
				++i;
			iterator ending(i); 
			return ending;
		}
		
		const_iterator
		end(void) const 
		{
			pointer i = _finish;
			if (this->_size)
				++i;
			const_iterator ending(i);
			return ending;
		}
		
		reverse_iterator
		rbegin(void) 
		{
			reverse_iterator beg(_finish);
			return beg;
		}
		
		const_reverse_iterator
		rbegin(void) const 
		{
			const_reverse_iterator beg(_finish);
			return beg;
		}
		
		reverse_iterator
		rend(void) 
		{
			pointer i = _start;
			if (this->_size)
				--i;
			reverse_iterator ending(i); 
			return ending;
		}
		
		const_reverse_iterator
		rend(void) const 
		{
			pointer i = _start;
			if (this->_size)
				--i;
			const_reverse_iterator ending(i);
			return ending;
		}
		
	/* ******************* Capacity ******************* */
		size_type
		size(void) const 
		{
			return this->_size; 
		}

		size_type
		max_size(void) const 
		{
			return _allocator.max_size();
		}

		void
		resize(size_type n, value_type val = value_type())
		{
			_check_init_len(n);
			if (n < this->_size)
				while (this->_size != n)
					pop_back();
			else if (n > this->_size)
				while (this->_size != n)
					push_back(val);
			return;
		}

		size_type
		capacity(void) const 
		{
			return size_type (this->_end_of_storage - this->_start);
		}

		bool
		empty(void) const 
		{
			return _size == 0;
		}

		void
		reserve(size_type n)
		{
			_check_init_len(n);
			if (this->capacity() < n)
				_reallocateWithValues(n);
			return;
		}

	/* ******************* Element access ******************* */
	
		reference
		operator[](size_type n)
		{
			iterator it = begin();
			return it[n];
		}

		const_reference
		operator[](size_type n) const
		{
			const_iterator it = begin();
			return it[n];
		}

		reference
		at(size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::at: index n >= this->size()" );
			return this->operator[](n);
		}
		
		const_reference
		at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::at: index n >= this->size()" );
			return this->operator[](n);
		}

		reference
		front(void) 
		{
			return *this->_start;
		}

		const_reference
		front(void) const 
		{
			return *this->_start;
		}

    	reference
		back(void)
		{
			return *this->_finish;
		}
		
		const_reference
		back(void) const 
		{
			return *this->_finish;
		}

	/* ******************* Modifiers ******************* */	

		template <class InputIterator>
		void
		assign (InputIterator first, InputIterator last,
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			clear();
			insert(this->begin(), first, last);
			return;
		}
		
		void
		assign(size_type n, const value_type& val)
		{
			clear();
			if (this->capacity() < n)
				_reallocate(n);
			this->_size = n;
			_setFinish();
			for (pointer i = this->_start; i != this->_end_of_storage; i++)
				*i = val;
			return;
		}

		void
		push_back(const value_type& val)
		{
			value_type save = val;
			if (this->_size == this->capacity())
				_reallocateWithValues(this->capacity() * 2);
			++this->_size;
			_setFinish();
			*(this->_finish) = save;
			return;
		}

		void
		pop_back(void)
		{
			 if (this->_size != 0)
			{
				this->_allocator.destroy(this->_finish);
				--this->_size;
				_setFinish();
			}
			return;
		}

		iterator
		insert(iterator position, const value_type& val)
		{
			value_type save = val;
			int distance = _calculateDistanceToPosition(this->begin(), position);
			if (this->_size + 1 > capacity())
				_reallocateWithValues(this->capacity() * 2);
			++this->_size;
			_setFinish();
			position = this->begin() + distance;
			_shiftValuesToEnd(position);
			*position = save;
			return position;
		}
		
		void
		insert(iterator position, size_type n, const value_type& val)
		{
			value_type save = val;
			for (size_type i = 0; i < n; i++)
				position = insert(position, save);
			return;
		}

		template <class InputIterator>
		void
		insert (iterator position, InputIterator first, InputIterator last,
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			while (first != last)
			{
				position = insert(position, *first);
				++position;
				++first;
			}
			return;
		}

		iterator
		erase(iterator position)
		{
			this->_allocator.destroy(position.operator->());
			_shiftValuesToStart(position, 1);
			--this->_size;
			_setFinish();
			return position;
		}

		iterator
		erase(iterator first, iterator last)
		{
			size_type distance = _calculateDistanceToPosition(first, last);
			_shiftValuesToStart(first, distance);
			this->_size -= distance;
			_setFinish();
			return first;
		}

		void
		swap(vector& x)
		{
			ft::vector<value_type> temp;
			
			_copyAttributes(x, temp);
			_copyAttributes(*this, x);
			_copyAttributes(temp, *this);
			temp._start = temp._finish = temp._end_of_storage = NULL;
			temp._size = 0;
			return;
		}
		
		void
		clear(void) 
		{
			_destroyAllValues(); 
			this->_size = 0;
			_setFinish();
			return; 
		}
	
	private:

		size_type
		_check_init_len(size_type n)
		{
			if (n > max_size())
				throw std::range_error("cannot create ft::vector larger than max_size()");
			return n;
		}

		void
		_copyAttributes(vector const & src, vector & dest)
		{
			dest._start = src._start;
			dest._finish = src._finish;
			dest._size = src._size;
			dest._end_of_storage = src._end_of_storage;
			return;
		}

		void
		_construct(const value_type& value, pointer finish)
		{
			++finish;
			for (pointer i = this->_start; i != finish; i++)
				_allocator.construct(i, value);
		}

		void
		_construct(iterator it, pointer finish)
		{
			++finish;
			for (pointer i = this->_start; i != finish; i++, it++)
				_allocator.construct(i, *it);
			return;
		}

		void
		_reallocate(size_type new_capacity)
		{
			pointer new_start = this->_allocator.allocate(_check_init_len(new_capacity));
			for (pointer i = new_start; i != new_start + new_capacity; i++)
				_allocator.construct(i, value_type());
			_destroyAllValues();
			this->_allocator.deallocate(this->_start, this->capacity());
			this->_start = new_start;
			this->_end_of_storage = this->_start + new_capacity;
			return;
		}

		void
		_reallocateWithValues(size_type new_capacity)
		{
			if (new_capacity == 0)
				++new_capacity;
			pointer new_start = this->_allocator.allocate(_check_init_len(new_capacity));
			for (pointer i = new_start; i != new_start + new_capacity; i++)
				_allocator.construct(i, value_type());
			if (this->_size > 0)
				_copyValues(&new_start);
			_destroyAllValues();
			this->_allocator.deallocate(this->_start, this->capacity());
			this->_start = new_start;
			this->_end_of_storage = this->_start + new_capacity;
			_setFinish();
			return;
		}
		
		void
		_copyValues(pointer * dest)
		{
			pointer res = *dest;
			for (pointer p = this->_start; p != this->_finish; p++, res++)
				*res = *p;
			*res = *(this->_finish);
		}
		
		void
		_destroyAllValues(void)
		{
			for (pointer i = this->_start; i != this->_end_of_storage; i++)
				_allocator.destroy(i);
			return;
		}
		
		void
		_setFinish(void)
		{
			this->_finish = this->_start;
			if (this->_size > 0)
				this->_finish = this->_start + this->_size - 1;
			return;
		}

		int
		_calculateDistanceToPosition(iterator start, iterator position)
		{
			int i;
			for (i = 0; position != start; position--)
				i++;
			return i;
		}
		
		void
		_shiftValuesToEnd(iterator position)
		{
			iterator current = end();
			iterator next = --current;
		
			for (--next; current != position; next--, current--)
				*current = *next;
			return;
		}

		void
		_shiftValuesToStart(iterator position, size_type distance)
		{
			iterator next = position;
			next += distance;
			for (; next != end(); next++, position++)
				*position = *next;
			return;
		}
	};

	/* ******************* Non-member functions ******************* */	

	template <class T, class Alloc>
	bool
	operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename ft::vector<T, Alloc>::iterator it1 = lhs.begin();
			typename ft::vector<T, Alloc>::iterator it2 = rhs.begin();
			while (it1 != lhs.end())
			{
				if (*it1 != *it2)
					return false;
				++it1;
				++it2;
			}
			return true;
		}
		return false;
	}

	template <class T, class Alloc>
	bool
	operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); }

	template <class T, class Alloc>
	bool
	operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T, Alloc>::iterator it1 = lhs.begin();
		typename ft::vector<T, Alloc>::iterator it2 = rhs.begin();
	
		while (it1 != lhs.end() && it2 != rhs.end())
		{
			if (*it1 > *it2)
				return false;
			else if (*it1 < *it2)
				return true;
			++it1;
			++it2;
		}
		if (rhs.size() < lhs.size() || rhs.size() == lhs.size())
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool
	operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(rhs < lhs); }

	template <class T, class Alloc>
	bool
	operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return rhs < lhs; }

	template <class T, class Alloc>
	bool
	operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); }

	template <class T, class Alloc>
	void
	swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
		return;
	}
}

#endif
