/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:33:49 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/15 12:39:58 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

/*
 * Orthodox Canonical Form
*/
RobotomyRequestForm::RobotomyRequestForm(void):\
AForm(NAME_RRF, SING_RRF, EXEC_RRF)
{
	std::cout << Y << NAME_RRF << E << "Default constrcutor called"
		<< std::endl;
	this->target = "Unnamed";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):\
AForm(NAME_RRF, SING_RRF, EXEC_RRF)
{
	this->target = obj.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator= \
(const RobotomyRequestForm &obj)
{
	AForm::operator=(obj);
	this->target = obj.target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm\
(std::string defname, std::string deftarget):AForm(defname, SING_RRF, EXEC_RRF)
{
	this->target = deftarget;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << Y << NAME_RRF << E <<  "Destructor called" << std::endl;
}

/*
 * Get Methods
*/
std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::executeForm(void) const
{
	srand(clock());

	double robotomized = rand() / (double)RAND_MAX;
	if (robotomized < 0.5)
		std::cout << G << this->target << ": " << E "successful robotization"
		<< std::endl;  
	else
		std::cout << R << this->target << ": " << E "failed robotization"
		<< std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj)
{
	os << Y << "Name: " << E << obj.getName() << "\n"
		<< Y << "Target: " << E << obj.getTarget() << "\n"
		<< Y << "status signed: " << E <<
		(obj.getIsSigned() ? "true" : "false") << "\n"
		<< Y << "sign grade: " << E << obj.getSignGrade() << "\n"
		<< Y << "exec grade: " << E << obj.getExecGrade();
	return (os);
}

