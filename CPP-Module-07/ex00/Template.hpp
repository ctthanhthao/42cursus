/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:48:49 by thchau            #+#    #+#             */
/*   Updated: 2026/06/25 10:18:37 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T &min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
const T &max(T &a, T &b)
{
	if (a > b)
		return a;
	return b;
}

#endif