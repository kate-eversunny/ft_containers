/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:57:48 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/21 17:46:28 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

# include <new>
# include <limits>
# include <exception>

namespace ft
{
	template<class T>
	class allocator
	{
	public:
		typedef T							value_type;
		typedef value_type*					pointer;
		typedef value_type&					reference;
		typedef const value_type*			const_pointer;
		typedef const value_type&			const_reference;
		typedef typename std::size_t		size_type;
		typedef typename std::ptrdiff_t		difference_type;
		
		template <class Type> struct rebind
		{
  			typedef allocator<Type> other;
		};
	
		allocator() throw() {}
		
		// allocator(const allocator& alloc) throw() { *this = alloc; }
		
		// template <class U>
  		// allocator (const allocator<U>& alloc) throw() { *this = alloc; }

		~allocator(void) throw() {}
		
		pointer address ( reference x ) const
		{
			return &x;
		}
		
		pointer allocate (size_type n)
		{
			pointer mem = (pointer)::operator new(n * sizeof(value_type));
			return mem;
		}
		
		void deallocate (pointer p, size_type n)
		{
			if (n > 0)
				::operator delete (p);
		}

		size_type max_size(void) const throw()
		{
			return std::numeric_limits<difference_type>::max() / sizeof(value_type);
		}

		void construct ( pointer p, const_reference val )
		{
			new ((void*)p) value_type(val);
		}

		void destroy (pointer p)
		{
			p->~value_type();
		}
	};
}

#endif