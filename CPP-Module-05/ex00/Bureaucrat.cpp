/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:14:06 by thchau            #+#    #+#             */
/*   Updated: 2026/06/05 15:24:15 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):
_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
: _name(source._name), _grade(source._grade) {}
		
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}
		
Bureaucrat::~Bureaucrat(){}
		
std::string Bureaucrat::getName() const
{
	return (this->_name);
}
		
unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooLowException();
	--(this->_grade);
}
		
void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooHighException();
	++(this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception:Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return (out);
}