/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:34:40 by thchau            #+#    #+#             */
/*   Updated: 2026/06/18 11:15:29 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data
{
	int id;
	std::string name;	
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &source);
		Serializer &operator=(const Serializer &other);
		~Serializer();
		
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

# endif