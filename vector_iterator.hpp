/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:20:59 by pvivian           #+#    #+#             */
/*   Updated: 2021/02/09 19:52:55 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
	template <typename T>
	struct vector_normal_iterator
	{
	protected:
		T* iter;
	
	public:
		typedef	vector_normal_iterator	iterator;
		typedef T						value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t			difference_type;
		typedef T&						reference;
		typedef T*						pointer;
		
		iterator(void) : iter(NULL) { return; }
		iterator(iterator const & other) { *this = other; return; }
		~iterator(void) { return; }
		
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
	struct vector_reverse_iterator : public vector_normal_iterator<T>
	{
	public:
		typedef	vector_reverse_iterator				reverse_iterator;
		typedef vector_normal_iterator				iterator;
		typedef vector_normal_iterator::value_type	value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef vector_normal_iterator::reference	reference;
		typedef vector_normal_iterator::pointer		pointer;
		
		reverse_iterator(void) : iterator() { return; }
		reverse_iterator(reverse_iterator const & other) : iterator(other) { return; }
		~reverse_iterator(void) : ~iterator(){ return; }
		
	// 	iterator base(void) { return iterator temp(this->iter); }
	// 	reverse_iterator & operator=(reverse_iterator const & other) { this->iter = other.iter; return *this; }
	// 	bool operator==(reverse_iterator const & other) { return this->iter == other.iter; }
	// 	bool operator!=(reverse_iterator const & other) { return this->iter != other.iter; }
	// 	pointer operator->(void) const {return this->iter; }
	// 	reference operator*(void) const {return *iter; }
	// 	reverse_iterator & operator++(void) 
	// 	{
	// 		this->iter--; 
	// 		return *this; 
	// 	}
		
	// 	reverse_iterator & operator++(int value) 
	// 	{
	// 		reverse_iterator temp(*this);
	// 		this->iter--;
	// 		return temp;
	// 	}
	// 	reverse_iterator & operator--(void) 
	// 	{
	// 		this->iter++; 
	// 		return *this; 
	// 	}
		
	// 	reverse_iterator & operator--(int value) 
	// 	{
	// 		reverse_iterator temp(*this);
	// 		this->iter++;
	// 		return temp;
	// 	}
	// 	bool operator>(reverse_iterator const & other) { return this->iter > other.iter; }
	// 	bool operator<(reverse_iterator const & other) { return this->iter < other.iter; }
	// 	bool operator>=(reverse_iterator const & other) { return this->iter >= other.iter; }
	// 	bool operator<=(reverse_iterator const & other) { return this->iter <= other.iter; }
	// 	reverse_iterator operator+(int value) {	return reverse_iterator temp(this->iter + value); }
	// 	reverse_iterator operator-(int value) {	return reverse_iterator temp(this->iter - value); }
	// 	reverse_iterator operator-(reverse_iterator const & other) { return reverse_iterator temp(this->iter - other.iter); }
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
	// 	reverse_iterator & operator[](int index) { return this->iter[index]; }
		
	};
}

#endif
