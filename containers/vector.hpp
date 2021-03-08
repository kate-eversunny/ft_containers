/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:28:19 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/08 18:45:49 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <limits.h>
# include <exception>
# include <memory>
# include "vector_iterator.hpp"

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T>> 
	class vector
	{
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef typename allocator_type::reference				reference_type;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef vector_iterator<T>								iterator;
		typedef vector_iterator<const T>						const_iterator;
		// typedef reverse_iterator;
		// typedef const_reverse_iterator;
	
	private:
		pointer				_start;
		pointer				_finish;
		pointer				_end_of_storage;
		allocator_type		_allocator;

		size_type _check_init_len(size_type n)
		{
			if (n > __PTRDIFF_MAX__ / sizeof(T))
				throw std::range_error("cannot create ft::vector larger than max_size");
			return n;
		}
	
	public:
	
	// ******************** Constructors ********************
		explicit vector( const allocator_type& alloc = allocator_type()) : _start(0), _finish(0), _end_of_storage(0), _allocator(alloc) { return; }
		
		explicit vector( size_type n, const T& value = value_type(), const allocator_type& alloc = allocator_type() ) : _allocator(alloc)
		{
			_start = _allocator.allocate(_check_init_len(n));
			_finish = _start;
			_end_of_storage = _start + n + 1;
			
			for (size_type i = _start; i < _end_of_storage; i++)
				_allocator.construct(i, value);
			_finish = _start + n;
			return;
		}
		
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _allocator(alloc)
		// {
			
		// }
		
		vector (vector const & x)
		{
			*this = x;
			return;
		}

	// ******************** Destructor ********************
		~vector(void) {}
	// ******************** Operator= overload ********************
		vector & operator=(vector const & x)
		{
			size_type size = x.size();
			_allocator = x._allocator;
			if (this->capacity() < size)
			{
				_allocator.deallocate(this->_start, this->capacity());
				this->_start = _allocator.allocate(_check_init_len(size);
				this->_finish = this->_start;
				this->_end_of_storage = this->_start + size + 1;
			}
			ft::vector<T>::iterator x_beg;
			pointer i = this->_start;
			for (x_beg = x.begin(); x_beg != x.end(); x_beg++)
			{
				_allocator.construct(i, *x_beg);
				++i;
			}
			_finish = _start + size;
			
		}

	// ******************** Capacity ********************
		
	};
}

#endif
