/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:33:50 by thchau            #+#    #+#             */
/*   Updated: 2026/06/26 12:55:48 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span &source);
		Span &operator=(const Span &other);
		~Span();
		
		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;
		
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::runtime_error("Too many numbers");

			_numbers.insert(_numbers.end(), begin, end);
		}
};

#endif