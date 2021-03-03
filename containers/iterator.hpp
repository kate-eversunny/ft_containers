/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:38:18 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/01 16:49:21 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <memory> //for allocator
# include <cstddef> //for fundamental types

namespace ft
{
	struct input_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct bidirectional_iterator_tag : forward_iterator_tag{};
	struct random_access_iterator_tag : bidirectional_iterator_tag {};
	
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
  	struct iterator 
	{
	private:
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;

		pointer ptr;

	public:
	
	// *************** Constructors ***************

		iterator() { return; }

		iterator(input_iterator_tag, iterator const & toCopy)
		{
			ptr = toCopy.ptr;
			return ;
		}

		iterator & operator= (iterator const & toCopy)
		{
			if (&this != toCopy)
				ptr = toCopy.ptr;
			return *this;
		}
	
	// *************** Destructor ***************
		~iterator(void) { return ; }
	
	// *************** Overloads ***************
		bool operator==(iterator const & other) const { return this->ptr==other.ptr; }
		
		bool operator!=(iterator const & other) const { return this->ptr!=other.ptr; }
		
		const reference operator*(void) const { return *(this->ptr); }

		const pointer operator->(void) const { return this->ptr; }
		
		iterator & operator++(void)
		{
			this->ptr++;
			return *this;
		}

		iterator & operator++(int value)
		{
			iterator temp(*this);
			this->ptr++;
			return temp;
		}

		iterator & operator--(void)
		{
			this->ptr--;
			return *this;
		}

		iterator & operator--(int value)
		{
			iterator temp(*this);
			this->ptr--;
			return temp;
		}
  };
}

#endif
