/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:14:42 by thchau            #+#    #+#             */
/*   Updated: 2026/06/26 21:34:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		const_iterator begin() const
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
		const_iterator end() const
		{
			return this->c.end();
		}
};
#endif