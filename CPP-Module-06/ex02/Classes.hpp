/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:33:54 by thchau            #+#    #+#             */
/*   Updated: 2026/06/24 19:35:20 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

#endif