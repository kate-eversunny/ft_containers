/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:20:59 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/08 19:09:14 by pvivian          ###   ########.fr       */
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
		typedef	vector_iterator			iterator;
		typedef T						value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t			difference_type;
		typedef T&						reference;
		typedef T*						pointer;
		
		// *************** Constructors ***************
		iterator(void) : iter(NULL) { return; }
		iterator(iterator const & other) { *this = other; return; }
		
		// *************** Destructor ***************
		~iterator(void) { return; }
		
		// *************** Member functions ***************
		iterator & operator=(iterator const & other) { this->iter = other.iter; return *this; }
		bool operator==(iterator const & other) { return this->iter == other.iter; }
		bool operator!=(iterator const & other) { return this->iter != other.iter; }
		pointer operator->(void) const {return iter; }
		reference operator*(void) const {return *iter; }
		iterator & operator++(void) 
		{
			this->iter++; 
			return *this; 
		}
		
		iterator & operator++(int value) 
		{
			iterator temp(*this);
			this->iter++;
			return temp;
		}
		iterator & operator--(void) 
		{
			this->iter--; 
			return *this; 
		}
		
		iterator & operator--(int value) 
		{
			iterator temp(*this);
			this->iter--;
			return temp;
		}
		bool operator>(iterator const & other) { return this->iter > other.iter; }
		bool operator<(iterator const & other) { return this->iter < other.iter; }
		bool operator>=(iterator const & other) { return this->iter >= other.iter; }
		bool operator<=(iterator const & other) { return this->iter <= other.iter; }
		iterator operator+(int value) {	return iterator temp(this->iter + value); }
		iterator operator-(int value) {	return iterator temp(this->iter - value); }
		iterator operator-(iterator const & other) { return iterator temp(this->iter - other.iter); }
		iterator & operator+=(int value) 
		{
			this->iter += value; 
			return *this; 
		}
		iterator & operator-=(int value) 
		{
			this->iter -= value; 
			return *this; 
		}
		iterator & operator[](int index) { return this->iter[index]; }
		
	};
	
	template <typename T>
	struct vector_reverse_iterator
	{
	private:
		typedef	vector_reverse_iterator						reverse_iterator;
		typedef typename ft::vector_iterator<T>				iterator_type;
		typedef typename iterator_type::value_type			value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef typename iterator_type::reference			reference;
		typedef typename iterator_type::pointer				pointer;
	
		iterator_type base_iterator;
	
	public:
	
	// *************** Constructors ***************
		reverse_iterator(void) { iterator_type base_iterator; return; }
		reverse_iterator(reverse_iterator const & other) { iterator_type base_iterator(other.base_iterator); return; }
	
	// *************** Destructor ***************
		~reverse_iterator(void) : ~iterator(){ return; }
	
	// *************** Member functions ***************
		iterator_type base(void) { return this->base_iterator; }
		
		reverse_iterator & operator=(reverse_iterator const & other) { this->base_iterator = other.base_iterator; return *this; }
		
		bool operator==(reverse_iterator const & other) { return this->base_iterator == other.base_iterator ; }
		
		bool operator!=(reverse_iterator const & other) { return this->base_iterator != other.base_iterator; }
		
		pointer operator->(void) const {return *this->base_iterator; }
		
		reference operator*(void) const {return &this->base_iterator; }
		
		reverse_iterator & operator++(void) 
		{
			this->base_iterator--; 
			return *this; 
		}
		
		reverse_iterator & operator++(int value) 
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
		
		reverse_iterator & operator--(int value) 
		{
			reverse_iterator temp(*this);
			this->base_iterator++;
			return temp;
		}

		bool operator>(reverse_iterator const & other) { return this->base_iterator < other.base_iterator; }

		bool operator<(reverse_iterator const & other) { return this->base_iterator > other.base_iterator; }

		bool operator>=(reverse_iterator const & other) { return this->base_iterator <= other.base_iterator; }

		bool operator<=(reverse_iterator const & other) { return this->base_iterator >= other.base_iterator; }

		reverse_iterator operator+(int value) { this->base_iterator - value; return this; }
		reverse_iterator operator-(int value) {	this->base_iterator + value; return this; }
		// reverse_iterator operator-(reverse_iterator const & other) { return reverse_iterator temp(this->iter - other.iter); }
	// 	reverse_iterator & operator+=(int value) 
	// 	{
	// 		this->iter += value; 
	// 		return *this; 
	// 	}
	// 	reverse_iterator & operator-=(int value) 
	// 	{
	// 		this->iter -= value; 
	// 		return *this; 
	// 	}
		reverse_iterator & operator[](int index) { return this->base_iterator[index]; }
	};
}

#endif
