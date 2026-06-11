/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:14:06 by thchau            #+#    #+#             */
/*   Updated: 2026/06/10 11:08:19 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade):
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
		
int Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(AForm &form)
{
	try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed "
				  << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute "
			      << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return (out);
}