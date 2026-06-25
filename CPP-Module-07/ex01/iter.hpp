/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:22:11 by thchau            #+#    #+#             */
/*   Updated: 2026/06/25 14:15:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void print(const T& x)
{
    std::cout << x << " ";
}

template<typename T, typename Func>
void iter(T *array, const size_t length, Func func)
{
	if (!array)
    	return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif