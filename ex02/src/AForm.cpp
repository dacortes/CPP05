/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/15 18:34:48 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"


/*
 * Orthodox Canonical AForm
*/

AForm::AForm(void): name("default"), isSigned(false), signGrade(MIN_GRADE),
				  execGrade(MIN_GRADE)
{
	std::cout << F << "AForm: " << E << "Default constrcutor called"
		<< std::endl;
}

AForm::AForm(std::string defname, unsigned int def_sign, unsigned int def_exec): \
		name(defname), isSigned(false), signGrade(def_sign), execGrade(def_exec)
{
	checker(def_sign, MIN_GRADE, MAX_GRADE,
			std::string(std::string(INIT_CONSTRUCTOR)
			+ std::string("Sign grade: ")));
	checker(def_exec, MIN_GRADE, MAX_GRADE,
			std::string(std::string(INIT_CONSTRUCTOR)
			+ std::string("Exec grade: ")));
}

AForm::AForm(const AForm &obj): name(obj.getName()),
	signGrade(obj.getSignGrade()), execGrade(obj.getExecGrade())
{
	checker(obj.getSignGrade(), MIN_GRADE, MAX_GRADE,
			std::string(std::string(COPY_CONSTRUCTOR)
			+ std::string("Sign grade")));
	checker(obj.getExecGrade(), MIN_GRADE, MAX_GRADE,
			std::string(std::string(COPY_CONSTRUCTOR)
			+ std::string("Exec grade")));
	this->isSigned = obj.getIsSigned();
}

AForm &AForm::operator=(const AForm &obj)
{
	this->isSigned = obj.getIsSigned();
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << F << "AForm " << E << "Destructor called"
		<< std::endl;
}

/*
 * Get Methods
*/

std::string AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

unsigned int AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

unsigned int AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

/*
 * Membet Funtions
*/

void AForm::checker(unsigned int verify, unsigned int min, unsigned int max,
		std::string msg)
{
	if (verify > min)
		throw AForm::GradeTooLowException(std::string(ERROR)
				+ msg + std::string("Low"));
	if (verify < max)
		throw AForm::GradeTooHighException(std::string(ERROR)
				+ msg + std::string("High"));
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	checker(bureaucrat.getGrade(), this->getSignGrade(), MAX_GRADE,
	std::string(bureaucrat.getName() + "couldn’t sign" +  this->getName()
	+ "because invalid sing grade: "));
	if (this->isSigned)
		throw AForm::IsSignedException(std::string( this->getName()
		+ ": it's already signed"));
	this->isSigned = true;
}
void	AForm::execute(Bureaucrat const & executor) const
{
	check(executor.getGrade, this->execGrade, MAX_GRADE,
	std::string(executor.getName() + "couldn’t execute" +  this->getName()
	+ "because invalid sing grade: "));

}

AForm::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::range_error(msg)
{}

AForm::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::range_error(msg)
{}

AForm::IsSignedException::IsSignedException(const std::string &msg)
	: std::logic_error(msg)
{}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << F << "Name: " << E << obj.getName() << "\n"
		<< F << "status signed: " << E <<
		(obj.getIsSigned() ? "true" : "false") << "\n"
		<< F << "sign grade: " << E << obj.getSignGrade() << "\n"
		<< F << "exec grade: " << E << obj.getExecGrade();
	return (os);
}
