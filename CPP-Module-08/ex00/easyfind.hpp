/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:55:30 by thchau            #+#    #+#             */
/*   Updated: 2026/06/26 11:27:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(
		container.begin(), container.end(), value
	);
	if (it == container.end())
		throw std::runtime_error("Value not found");

	return (it);
}

#endif