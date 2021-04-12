/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:54:47 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/12 17:16:30 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
  	template <class T, class Iterator>
  	struct reverse_iterator 
	{
	private:
		typedef T						value_type;
		typedef T*						pointer;
		typedef T& 						reference;
		typedef Iterator				iterator_type;
		
	protected:
		iterator_type base_iterator;
	
	public:
	
	// *************** Constructors ***************

		reverse_iterator() { iterator_type base_iterator; return; }

		explicit reverse_iterator(iterator_type it) { iterator_type base_iterator(it); return; }

		reverse_iterator (const reverse_iterator<value_type, iterator_type>& toCopy)
		{
			iterator_type base_iterator(toCopy.base_iterator);
			return ;
		}

		reverse_iterator & operator=(const reverse_iterator<value_type, iterator_type>& toCopy)
		{
			this->base_iterator = toCopy.base_iterator;
			return ;
		}
	
	// *************** Destructor ***************
		~reverse_iterator(void) { return ; }
	
	// *************** Member functions ***************
		iterator_type base() const { return this->base_iterator; }

		reference operator*(void) const { return *this->base_iterator; }

		pointer operator->(void) const { return &this->base_iterator; }
		
		reverse_iterator & operator++(void)
		{
			this->base_iterator--;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp(*this);
			this->base_iterator--;
			return temp;
		}
		
		reverse_iterator & operator--(void)
		{
			this->base_iterator++;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			this->base_iterator++;
			return temp;
		}

		bool operator==(reverse_iterator const & other) const { return this->base_iterator==other.base_iterator; }
		
		bool operator!=(reverse_iterator const & other) const { return this->base_iterator!=other.base_iterator; }
		
	// *************** Bidirectional functions ***************
		
		bool operator>(reverse_iterator const & other) { return this->base_iterator < other.base_iterator; }

		bool operator<(reverse_iterator const & other) { return this->base_iterator > other.base_iterator; }

		bool operator>=(reverse_iterator const & other) { return this->base_iterator <= other.base_iterator; }

		bool operator<=(reverse_iterator const & other) { return this->base_iterator >= other.base_iterator; }

		reverse_iterator & operator+(int value) { this->base_iterator - value; return *this; }
		
		reverse_iterator & operator-(int value) { this->base_iterator + value; return *this; }
		
		reverse_iterator & operator-(reverse_iterator const & other) { this->base_iterator + other.base_iterator; return *this; }
		
		reverse_iterator & operator+=(int value) 
		{
			this->base_iterator -= value; 
			return *this; 
		}
		
		reverse_iterator & operator-=(int value) 
		{
			this->base_iterator += value; 
			return *this; 
		}
		
		reference & operator[](int index) { return this->base_iterator[index]; }
  };

 	template <class T, class Iterator>
  	struct const_reverse_iterator : public reverse_iterator<T, Iterator>
	{
	private:
		typedef T						value_type;
		typedef const T*				const_pointer;
		typedef const T& 				const_reference;
		typedef Iterator				iterator_type;
	
	public:
	
	// *************** Constructors ***************

		const_reverse_iterator() { iterator_type base_iterator; return; }

		explicit const_reverse_iterator(iterator_type it) { iterator_type base_iterator(it); return; }

		const_reverse_iterator (const_reverse_iterator<value_type, iterator_type> const& toCopy)
		{
			this->base_iterator = toCopy.base();
			return ;
		}

		const_reverse_iterator (reverse_iterator<value_type, iterator_type> const& toCopy)
		{
			this->base_iterator = toCopy.base();
			return ;
		}
	
		const_reverse_iterator & operator=(const_reverse_iterator<value_type, iterator_type> const & toCopy)
		{
			this->base_iterator = toCopy.base();
			return this;
		}
	
		const_reverse_iterator & operator=(reverse_iterator<value_type, iterator_type> const & toCopy)
		{
			this->base_iterator = toCopy.base();
			return this;
		}
	// *************** Destructor ***************
		~const_reverse_iterator(void) { return ; }
	
	// *************** Member functions ***************

		const_reference operator*(void) const { return *this->base_iterator; }

		const_pointer operator->(void) const { return &this->base_iterator; }
		
		const_reference & operator[](int index) const { return this->base_iterator[index]; }

  };
  
}

#endif
