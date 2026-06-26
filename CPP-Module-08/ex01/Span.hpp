/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:33:50 by thchau            #+#    #+#             */
/*   Updated: 2026/06/26 12:04:28 by thchau           ###   ########.fr       */
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
};

#endif