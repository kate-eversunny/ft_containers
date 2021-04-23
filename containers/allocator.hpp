/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:57:48 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/23 14:29:08 by pvivian          ###   ########.fr       */
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
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
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

	template<bool, typename T = void>
    struct enable_if
    { };

  	template<typename T>
    struct enable_if<true, T>
    { typedef T type; };
}

#endif