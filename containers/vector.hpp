/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:28:19 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/10 20:39:12 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
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
			_end_of_storage = _start + n;
			_finish = _start;
			if (n)
				_finish = _start + n - 1;
			_size = 0;

			for (pointer i = _start; i != _end_of_storage; i++, ++_size)
				_allocator.construct(i, value);
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
			this->_finish = this->_start;
			if (this->_size)
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
			this->_finish = this->_start;
			if (this->_size)
				this->_finish = this->_start + this->_size - 1;
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

		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_size)
			{
				while (this->_size != n)
					pop_back();
			}
			else if (n > this->_size)
			{
				while (this->_size != n)
					push_back(val);
			}
			return;
		}

		size_type capacity() const { return size_type (this->_end_of_storage - this->_start); }

		bool empty() const { return _size == 0; }

		void reserve (size_type n)
		{
			if (this->capacity() < n)
			{
				pointer new_start = this->_allocator.allocate(_check_init_len(n));
				iterator it1;
				iterator it2(new_start);
				for (it1 = this->begin(); it1 != this->end(); it1++, it2++)
					*it2 = *it1;
				this->_allocator.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_finish = this->_start + this->_size;
				this->_end_of_storage = this->_start + n;
			}
			return;
		}

	/* ******************* Element access ******************* */
	
		reference operator[] (size_type n)
		{
			iterator it = begin();
			return it[n];
		}

		const_reference operator[] (size_type n) const
		{
			const_iterator it = begin();
			return it[n];
		}

		reference at (size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::at: index n >= this->size()" );
			return this->operator[](n);
		}
		
		const_reference at (size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::at: index n >= this->size()" );
			return this->operator[](n);
		}

		reference front() { return *this->_start; }

		const_reference front() const { return *this->_start; }

    	reference back() { return *this->_finish; }
		
		const_reference back() const { return *this->_finish; }

	/* ******************* Modifiers ******************* */	

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);
		
		void assign (size_type n, const value_type& val);

		void push_back (const value_type& val)
		{
			if (this->_size == this->capacity())
			{
				size_type new_capacity = this->capacity() * 2;
				pointer new_start = this->_allocator.allocate(_check_init_len(new_capacity));
				iterator it1;
				iterator it2(new_start);
				for (it1 = this->begin(); it1 != this->end(); it1++, it2++)
					*it2 = *it1;
				*it2 = val;
				this->_allocator.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_finish = this->_start + this->_size;
				this->_size++;
				this->_end_of_storage = this->_start + new_capacity;
			}
			else if (this->_size == 0)
			{
				*(this->_finish) = val;
				this->_size++;
			}
			else
			{
				++(this->_finish);
				*(this->_finish) = val;
				this->_size++;
			}
		}

		void pop_back()
		{
			if (this->_size != 0)
			{
				pointer new_finish = this->_finish;
				if (this->_finish != this->_start)
					--new_finish;
				this->_allocator.destroy(this->_finish);
				--this->_size;
				this->_finish = new_finish;
			}
			return;
		}

		iterator insert (iterator position, const value_type& val);
		
		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position)
		{
			if (position == --(this->end()))
			{
				pop_back();
				return end();
			}
			size_type capacity = this->capacity();
			pointer new_start = this->_allocator.allocate(_check_init_len(capacity));
			iterator it1;
			iterator it2(new_start);
			for (it1 = this->begin(); it1 != position; it1++, it2++)
				*it2 = *it1;
			it1 = position;
			position = it2;
			for (++it1; it1 != this->end(); it1++, it2++)
				*it2 = *it1;
			this->_allocator.deallocate(this->_start, capacity);
			this->_size--;
			this->_start = new_start;
			this->_finish = this->_start;
			if (this->_size > 0)
				this->_finish = this->_start + this->_size - 1;
			this->_end_of_storage = this->_start + capacity;
			return position;
		}

		iterator erase (iterator first, iterator last)
		{
			if (last == this->end())
			{
				iterator it = first;
				while (it != last && this->_size > 0)
				{
					this->_allocator.destroy(it.operator->());
					it++;
					this->_size--;
				}
				this->_finish = this->_start;
				if (this->_size > 0)
					this->_finish = this->_start + this->_size - 1;
				return this->end();
			}
			else
			{
				size_type capacity = this->capacity();
				pointer new_start = this->_allocator.allocate(_check_init_len(capacity));
				iterator it1;
				iterator it2(new_start);
				this->_size = 0;
				for (it1 = this->begin(); it1 != first; it1++, it2++, ++(this->_size))
					*it2 = *it1;
				first = it2;
				for (it1 = last; it1 != this->end(); it1++, it2++, ++(this->_size))
					*it2 = *it1;
				this->_allocator.deallocate(this->_start, capacity);
				this->_start = new_start;
				this->_finish = this->_start;
				if (this->_size)
					this->_finish = this->_start + this->_size - 1;
				this->_end_of_storage = this->_start + capacity;
				return first;
			}
		}

		void swap (vector& x)
		{
			ft::vector<value_type> temp(x);
			x = *this;
			*this = temp;
			return;
		}
		
		void clear() { erase(begin(), end()); return; }
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
