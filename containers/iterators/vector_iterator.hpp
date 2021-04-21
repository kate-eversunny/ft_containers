/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:20:59 by pvivian           #+#    #+#             */
/*   Updated: 2021/04/21 17:42:27 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
	template <typename T>
	struct vector_iterator
	{
	public:
		T* iter;
	
	public:
		typedef T						value_type;
		typedef T&						reference;
		typedef T*						pointer;
		
		// *************** Constructors ***************
		vector_iterator(void) : iter(NULL) { return; }
		vector_iterator(pointer ptr) : iter(ptr) { return; }
		vector_iterator(vector_iterator const & other) { *this = other; return; }
		
		// *************** Destructor ***************
		~vector_iterator(void) { return; }
		
		// *************** Member functions ***************
		vector_iterator & operator=(vector_iterator const & other) { this->iter = other.iter; return *this; }
		bool operator==(vector_iterator const & other) { return this->iter == other.iter; }
		bool operator!=(vector_iterator const & other) { return this->iter != other.iter; }
		pointer operator->(void) const {return iter; }
		reference operator*(void) const {return *iter; }
		vector_iterator & operator++(void) 
		{
			this->iter++; 
			return *this; 
		}
		
		vector_iterator operator++(int) 
		{
			vector_iterator temp(*this);
			this->iter++;
			return temp;
		}
		vector_iterator & operator--(void) 
		{
			this->iter--; 
			return *this; 
		}
		
		vector_iterator operator--(int) 
		{
			vector_iterator temp(*this);
			this->iter--;
			return temp;
		}
		
		bool operator>(vector_iterator const & other) { return this->iter > other.iter; }
		
		bool operator<(vector_iterator const & other) { return this->iter < other.iter; }
		
		bool operator>=(vector_iterator const & other) { return this->iter >= other.iter; }
		
		bool operator<=(vector_iterator const & other) { return this->iter <= other.iter; }
		
		vector_iterator & operator+(int value) { this->iter = this->iter + value; return *this; }
		
		vector_iterator & operator-(int value) { this->iter = this->iter - value; return *this; }
		
		vector_iterator & operator-(vector_iterator const & other) { this->iter = this->iter - other.iter; return *this; }
		
		vector_iterator & operator+=(int value) 
		{
			this->iter += value; 
			return *this; 
		}
		vector_iterator & operator-=(int value) 
		{
			this->iter -= value; 
			return *this; 
		}
		reference operator[](int index) { return this->iter[index]; }
		
	};

	template <class T>
  	struct const_vector_iterator : public vector_iterator<T>
	{
	private:
		typedef T						value_type;
		typedef value_type*				pointer;
		typedef const value_type*		const_pointer;
		typedef const value_type& 		const_reference;
	
	public:
	// *************** Constructors ***************

		const_vector_iterator() { return; }

		const_vector_iterator(pointer new_iter) { this->iter = new_iter; return; }

		const_vector_iterator(const_vector_iterator const & toCopy) : vector_iterator<T>(toCopy)
		{
			this->iter = toCopy.iter;
			return;
		}

		const_vector_iterator(vector_iterator<T> const & toCopy) : vector_iterator<T>(toCopy)
		{
			this->iter = toCopy.iter;
			return;
		}

		const_vector_iterator & operator= (const_vector_iterator const & toCopy)
		{
			if (this != &toCopy)
				this->iter = toCopy.iter;
			return *this;
		}
	
		const_vector_iterator & operator= (vector_iterator<T> const & toCopy)
		{
			if (this != &toCopy)
				this->iter = toCopy.iter;
			return *this;
		}
	// *************** Destructor ***************
		~const_vector_iterator(void) { return ; }
	
	// *************** Member functions ***************
		const_reference operator*(void) const { return *this->iter; }
		const_pointer operator->(void) const { return this->iter; }
		const_reference operator[](int index) const { return this->iter[index]; }
	};

}

#endif
