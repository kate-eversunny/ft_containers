/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:28:19 by pvivian           #+#    #+#             */
/*   Updated: 2021/03/15 15:58:46 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "list.hpp"

namespace ft
{
	template<class T, class Container = ft::list<T> > 
	class stack
	{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef std::size_t		size_type;
	
	private:
		container_type _container;
		
	public:
	
	/* ******************* Constructor ******************* */
		explicit stack (const container_type& ctnr = container_type()) : _container(ctnr)
		{
			return;
		}

	/* ******************* Capacity ******************* */
		size_type
		size(void) const 
		{
			return this->_container.size(); 
		}

		bool
		empty(void) const 
		{
			return this->_container.empty();
		}

	/* ******************* Element access ******************* */

    	value_type&
		top(void)
		{
			return this->_container.back();
		}
		
		const value_type&
		top(void) const 
		{
			return this->_container.back();
		}

	/* ******************* Modifiers ******************* */	

		void
		push(const value_type& val)
		{
			this->_container.push_back(val);
			return;
		}

		void
		pop(void)
		{
			this->_container.pop_back();
			return;
		}
		
	/* ******************* Friend functions declarations ******************* */	
		template <class T1, class Container1>
		friend bool
		operator== (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

		template <class T1, class Container1>
		friend bool
		operator<  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

	};

	/* ******************* Non-member functions ******************* */	

	template <class T, class Container>
	bool
	operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container == rhs._container;
	}

	template <class T, class Container>
	bool
	operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool
	operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container < rhs._container;
	}

	template <class T, class Container>
	bool
	operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool
	operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Container>
	bool
	operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
