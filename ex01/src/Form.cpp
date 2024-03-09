/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/09 10:29:50 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::checker(unsigned int verify, unsigned int min, unsigned int max,
		std::string msg)
{
	if (verify > min)
		throw Form::GradeTooLowException(std::string(ERROR)
				+ msg + std::string("Low"));
	if (verify < max)
		throw Form::GradeTooHighException(std::string(ERROR)
				+ msg + std::string("High"));
}

/*
 * Orthodox Canonical Form
*/

Form::Form(void): name("default"), isSigned(false), signGrade(MIN_GRADE)
				  execGrade(MIN_GRADE)
{
	std::cout << F << "Form: " << E << "Default constrcutor called"
		<< std::endl;
}

Form::Form(std::string defname, unsigned int def_sign, unsigned int def_exec): \
		name(defname), isSigned(false), signGrade(def_sign), execGrade(def_exec)
{
	checker(def_sign, MIN_GRADE, MAX_GRADE, std::string(INIT_CONSTRUCTOR
				+ "Sign grade: "));
	checker(def_exec, MIN_GRADE, MAX_GRADE, std::string(INIT_CONSTRUCTOR
				+ "Exec grade: "));
}

Form::Form(const Form &obj): name(obj.getName()),
	signGrade(obj.getSignGrade()), execGrade(obj.getExcecGrade())
{
	checker(obj.getSignGrade(), MIN_GRADE, MAX_GRADE,
			std::string(COPY_CONSTRUCTOR + "Sign grade"));
	checker(obj.getExcecGrade(), MIN_GRADE, MAX_GRADE,
			std::string(COPY_CONSTRUCTOR + "Exec grade"));
	this->isSigned = obj.getIsSigned();
}

Form &Form::operator=(const Form &obj)
{
	this->isSigned = obj.getIsSigned(void);
	return (*this);
}

Form::~Form(void)
{
	std::cout << F << "Form " << E << "Destructor called"
		<< std::endl;
}

/*
 * Membet Funtions
*/
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	checker(bureaucrat.getGrade(), this->getSignGrade(), MAX_GRADE,
	std::string(bureaucrat.getName() + "couldn’t sign" +  this->getName()
	+ "because invalid sing gradei: "));
	if (this->isSigned)
		throw Form::IsSignedException(std::string( this->getName()
		+ ": it's already signed"));
	this->isSigned = true;
}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::range_error(msg)
{}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::range_error(msg)
{}

Form::IsSignedException::IsSignedException(const std::string &msg)
	: std::logic_error(msg)
{}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << F << "Name: " << E << obj.getName() << "\n"
		<< F << "status signed: " << E << (obj.getIsSigned() ? "true" : false)
		<< "\n"
		<< F << "sign grade: " << E << obj.getSigGrade() << "\n"
		<< F << "exec grade: " << E << obj.getExecGrade() << std::endl;
		<< F << ""
	return (os);
}
