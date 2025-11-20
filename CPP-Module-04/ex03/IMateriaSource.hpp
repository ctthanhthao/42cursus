/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:34:13 by thchau            #+#    #+#             */
/*   Updated: 2025/11/20 12:19:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource(){};
	virtual void learnMateria(AMateria *materia) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif