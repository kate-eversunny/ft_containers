/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:20:59 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/09 17:41:40 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
	template <typename T>
	struct vector_iterator
	{
	protected:
		T* iter;
	
	public:
		typedef T						value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t			difference_type;
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
		
		vector_iterator & operator+(int value) { this->iter + value; return *this; }
		
		vector_iterator & operator-(int value) { this->iter - value; return *this; }
		
		vector_iterator & operator-(vector_iterator const & other) { this->iter - other.iter; return *this; }
		
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
		vector_iterator & operator[](int index) { return this->iter[index]; }
		
	};
	
	template <typename T>
	struct vector_reverse_iterator
	{
	private:
		typedef typename ft::vector_iterator<T>				iterator_type;
		typedef typename iterator_type::value_type			value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef typename iterator_type::reference			reference;
		typedef typename iterator_type::pointer				pointer;
	
		iterator_type base_iterator;
	
	public:
	
	// *************** Constructors ***************
		vector_reverse_iterator(void) { iterator_type base_iterator; return; }
		vector_reverse_iterator(pointer ptr) { iterator_type base_iterator(ptr); return; }
		vector_reverse_iterator(vector_reverse_iterator const & other) { iterator_type base_iterator(other.base_iterator); return; }
	
	// *************** Destructor ***************
		~vector_reverse_iterator(void) { return; }
	
	// *************** Member functions ***************
		iterator_type base(void) { return this->base_iterator; }
		
		vector_reverse_iterator & operator=(vector_reverse_iterator const & other) { this->base_iterator = other.base_iterator; return *this; }
		
		bool operator==(vector_reverse_iterator const & other) { return this->base_iterator == other.base_iterator ; }
		
		bool operator!=(vector_reverse_iterator const & other) { return this->base_iterator != other.base_iterator; }
		
		pointer operator->(void) const {return *this->base_iterator; }
		
		reference operator*(void) const { return *(this->base_iterator);  }
		
		vector_reverse_iterator & operator++(void) 
		{
			this->base_iterator--; 
			return *this; 
		}
		
		vector_reverse_iterator operator++(int) 
		{
			vector_reverse_iterator temp(*this);
			this->base_iterator--;
			return temp;
		}
		
		vector_reverse_iterator & operator--(void) 
		{
			this->base_iterator++; 
			return *this; 
		}
		
		vector_reverse_iterator operator--(int) 
		{
			vector_reverse_iterator temp(*this);
			this->base_iterator++;
			return temp;
		}

		bool operator>(vector_reverse_iterator const & other) { return this->base_iterator < other.base_iterator; }

		bool operator<(vector_reverse_iterator const & other) { return this->base_iterator > other.base_iterator; }

		bool operator>=(vector_reverse_iterator const & other) { return this->base_iterator <= other.base_iterator; }

		bool operator<=(vector_reverse_iterator const & other) { return this->base_iterator >= other.base_iterator; }

		vector_reverse_iterator & operator+(int value) { this->base_iterator - value; return *this; }
		
		vector_reverse_iterator & operator-(int value) { this->base_iterator + value; return *this; }
		
		vector_reverse_iterator & operator-(vector_reverse_iterator const & other) { this->base_iterator + other.base_iterator; return *this; }
		
		vector_reverse_iterator & operator+=(int value) 
		{
			this->base_iterator -= value; 
			return *this; 
		}
		
		vector_reverse_iterator & operator-=(int value) 
		{
			this->base_iterator += value; 
			return *this; 
		}
		
		vector_reverse_iterator & operator[](int index) { return this->base_iterator[index]; }
	};
}

#endif
