/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:56:20 by thchau            #+#    #+#             */
/*   Updated: 2025/10/14 09:55:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	enum Level {DEBUG, INFO, WARNING, ERROR, INVALID};
	static const std::string levelNames[4];
	Level getLevel(const std::string &level);
	
public:
	Harl();
	void complain( std::string level );
};

#endif