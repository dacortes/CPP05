/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/20 19:02:43 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"


/*
 * Orthodox Canonical Form
*/

Form::Form(void): name("default"), isSigned(false), signGrade(MIN_GRADE),
				  execGrade(MIN_GRADE)
{
	std::cout << F << "Form: " << E << "Default constrcutor called"
		<< std::endl;
}

Form::Form(std::string defname, unsigned int def_sign, unsigned int def_exec): \
		name(defname), isSigned(false), signGrade(def_sign), execGrade(def_exec)
{
	if (checker(def_sign, MIN_GRADE, MAX_GRADE,
			std::string(std::string(INIT_CONSTRUCTOR)
			+ std::string("Sign grade: "))))
			return ;
	if (checker(def_exec, MIN_GRADE, MAX_GRADE,
			std::string(std::string(INIT_CONSTRUCTOR)
			+ std::string("Exec grade: "))))
			return ;
}

Form::Form(const Form &obj): name(obj.getName()),
	signGrade(obj.getSignGrade()), execGrade(obj.getExecGrade())
{
	if (checker(obj.getSignGrade(), MIN_GRADE, MAX_GRADE,
			std::string(std::string(COPY_CONSTRUCTOR)
			+ std::string("Sign grade"))))
			return ;
	if (checker(obj.getExecGrade(), MIN_GRADE, MAX_GRADE,
			std::string(std::string(COPY_CONSTRUCTOR)
			+ std::string("Exec grade"))))
			return ;
	this->isSigned = obj.getIsSigned();
}

Form &Form::operator=(const Form &obj)
{
	this->isSigned = obj.getIsSigned();
	return (*this);
}

Form::~Form(void)
{
	std::cout << F << "Form " << E << "Destructor called"
		<< std::endl;
}

/*
 * Get Methods
*/

std::string Form::getName(void) const
{
	return (this->name);
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}

unsigned int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

unsigned int Form::getExecGrade(void) const
{
	return (this->execGrade);
}

/*
 * Membet Funtions
*/

bool Form::checker(unsigned int verify, unsigned int min, unsigned int max,
		std::string msg)
{
	if (verify > min)
	{
		throw Form::GradeTooLowException(std::string(ERROR)
				+ msg + std::string("Low"));
		return (EXIT_FAILURE);
	}
	if (verify < max)
	{
		throw Form::GradeTooHighException(std::string(ERROR)
				+ msg + std::string("High"));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	checker(bureaucrat.getGrade(), this->getSignGrade(), MAX_GRADE,
	std::string(bureaucrat.getName() + "couldn’t sign" +  this->getName()
	+ "because invalid sing grade: "));
	if (this->isSigned)
	{
		throw Form::IsSignedException(std::string( this->getName()
		+ ": it's already signed"));
		return ;
	}
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
		<< F << "status signed: " << E <<
		(obj.getIsSigned() ? "true" : "false") << "\n"
		<< F << "sign grade: " << E << obj.getSignGrade() << "\n"
		<< F << "exec grade: " << E << obj.getExecGrade();
	return (os);
}
