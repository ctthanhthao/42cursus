/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:55:33 by thchau            #+#    #+#             */
/*   Updated: 2026/06/10 11:22:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Form Default"), _isSigned(false), _gradeToSign(150),
_gradeToExecute(150){}

AForm::AForm(std::string name, int gts, int gte)
: _name(name), _isSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
	if (gts < 1 || gte < 1)
        throw GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &source)
: _name(source._name), _isSigned(source._isSigned),
 _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}
		
AForm::~AForm() {}
		
const std::string &AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}
		
int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
		
void AForm::beSigned(const Bureaucrat &bc)
{
	if (bc.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
		
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();

    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();

    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade too high to sign.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade too low to be sign.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form Exception: Form hasn't been signed yet.");
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
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