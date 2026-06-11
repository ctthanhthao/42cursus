/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:02:12 by thchau            #+#    #+#             */
/*   Updated: 2026/06/10 10:58:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	protected:
		std::string _target;
	public:
		AForm();
		AForm(std::string name, int gts, int gte);
		AForm(const AForm &source);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		
		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		void beSigned(const Bureaucrat &bc);

		void execute(Bureaucrat const & executor) const;
		
		virtual void executeAction() const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};
std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif