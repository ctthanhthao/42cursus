/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:55:33 by thchau            #+#    #+#             */
/*   Updated: 2026/06/05 17:53:36 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form Default"), _isSigned(false), _gradeToSign(150),
_gradeToExecute(150){}

Form::Form(std::string name, int gts, int gte)
: _name(name), _isSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
	if (gts < 1 || gte < 1)
        throw GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &source)
: _name(source._name), _isSigned(source._isSigned),
 _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}
		
Form::~Form() {}
		
const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}
		
int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
		
void Form::beSigned(const Bureaucrat &bc)
{
	if (bc.getGrade() > this->_gradeToSign)
	{
	//	std::cout << "Exception is gonna throw out.\n";
		throw GradeTooLowException();	
	}
		
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade too high to be signed or executed.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade too low to be signed or executed.");
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << "[Form] : name = " << obj.getName() << " ";
	if (obj.getIsSigned())
		out << "is signed, ";
	else
		out << "is not signed, ";
	out << "grade to sign = " << obj.getGradeToSign() << ", "
	    << "grade to execute = " << obj.getGradeToExecute() << ".";
	return (out); 
}