/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:19:07 by thchau            #+#    #+#             */
/*   Updated: 2026/06/06 20:38:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
{
	_target = "Unknown target";
}
		
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}
		
RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm &source) : AForm(source)
{
	_target = source._target;
}
		
RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
		
void RobotomyRequestForm::executeAction() const
{
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() %2 == 0)
		std::cout << _target << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}
