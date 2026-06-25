/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:09:00 by thchau            #+#    #+#             */
/*   Updated: 2026/06/25 19:53:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template<typename T>
class Array
{
	private:
		T *_elements;
		unsigned int _size;
	public:
		Array() : _elements(NULL), _size(0) {}
		Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
		Array(const Array &source) : _elements(NULL), _size(source._size)
		{
			if (_size > 0)
			{
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = source._elements[i];
			}
		};
		Array &operator=(const Array &other)
		{
			if (this == &other)
				return *this;
			delete []_elements;
			_size = other._size;
			if (_size > 0)
				_elements = new T[_size];
			else
				_elements = NULL;
			if (_elements)
			{
				for (unsigned int i = 0; i < _size; i++)
            		_elements[i] = other._elements[i];
			}
			return *this;
		};
		~Array()
		{
			delete [] _elements;
		};

		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Array index out of bounds";
				}	
		};
		
		T &operator[](unsigned int idx)
		{
			if (idx >= _size)
				throw OutOfBoundException();
			return _elements[idx];
		}
		const T& operator[](unsigned int idx) const
		{
			if (idx >= _size)
				throw OutOfBoundException();
			return _elements[idx];
		}
		unsigned int size() const
		{
			return _size;
		}
};
#endif