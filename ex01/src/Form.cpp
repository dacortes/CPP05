/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/08 11:37:42 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

/*
 * Orthodox Canonical Form
*/

Form::Form(void): name("default")
{
	std::cout << F << "Form: " << E << "Default constrcutor called"
		<< std::endl;
	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
}

Form::Form(std::string defname, unsigned int def_sign, unsigned int def_exec): \
		name(defname), isSigned(false), signGrade(def_sign), execGrade(def_exec)
{
	
}

Form::Form(const Form &obj): name(obj.getName())
{
	this->isSigned = obj.getIsSigned(void);
	this->signGrade = obj.getSignGrade(void);
	this->execGrade = obj.getExcecGrade(void);
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

}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::range_error(msg)
{}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::range_error(msg)
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
