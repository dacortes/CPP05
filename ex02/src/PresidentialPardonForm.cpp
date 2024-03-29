/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:33:49 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/22 12:32:13 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/*
 * Orthodox Canonical AForm
*/

PresidentialPardonForm::PresidentialPardonForm(void):\
AForm(NAME_PPF, SING_PPF, EXEC_PPF)
{
	std::cout << C << NAME_PPF << E << "Default constrcutor called"
		<< std::endl;
	this->target = "Unnamed";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):\
AForm(NAME_PPF, SING_PPF, EXEC_PPF)
{
	this->target = obj.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator= \
(const PresidentialPardonForm &obj)
{
	AForm::operator=(obj);
	this->target = obj.target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm\
(std::string deftarget): AForm(NAME_PPF, SING_PPF, EXEC_PPF)
{
	this->target = deftarget;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << C << NAME_PPF << E << "Destructor called"
		<< std::endl;
}

/*
 * Get Methods
*/
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::executeMagic(void) const
{
	std::cout << C << this->target << E 
		<< " has been pardoned by Zaphod Beeblebrox."  << std::endl;	
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{
	os << C << "Name: " << E << obj.getName() << "\n"
		<< C << "Target: " << E << obj.getTarget() << "\n"
		<< C << "status signed: " << E <<
		(obj.getIsSigned() ? "true" : "false") << "\n"
		<< C << "sign grade: " << E << obj.getSignGrade() << "\n"
		<< C << "exec grade: " << E << obj.getExecGrade();
	return (os);
}
