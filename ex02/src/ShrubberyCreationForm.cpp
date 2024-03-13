/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:53 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/13 19:29:11 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/*
 * Orthodox Canonical AForm
*/
ShrubberyCreationForm::ShrubberyCreationForm(void): \
AForm(NAME_SCF, SING_SCF, EXEC_SCF)
{
	std::cout << T << NAME_SCF << E << "Default constrcutor called"
		<< std::endl;
	this->target = "Unnamed";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): \
AForm(NAME_SCF, SING_SCF, EXEC_SCF)
{
	this->target = obj.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= \
	(const ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
	this->target = obj.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << T << NAME_SCF << E << "Destructor called"
		<< std::endl;
}

/*
 * Get Methods
*/
std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::executeForm(void) const
{
	std::fstream fd;

	fd.open(this->target + "_shrubbery", std::ios_base::out);
	if (!fd.is_open())
	{
		std::cerr << R "Error: " << E << "creating file: "
			<<  this->target + "_shrubbery" << std::endl;
		return ;
	}
	fd << "\
	─────☆─────\n\
	─────▓˛˚────\n\
	────▓˛˚▓˛˚───\n\
	───▓˛˚▓˛ ▓*──\n\
	──▓˛˚▓˛▓˛*▓˛˚─\n\
	─▓˛▓˚▓˛▓*▓˛▓˛˚\n\
	─────██────\n\
	 ███████████" << std::endl;
	fd.close();
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
	os << F << "Name: " << E << obj.getName() << "\n"
		<< F << "Target: " << E << obj.getTarget() << "\n"
		<< F << "status signed: " << E <<
		(obj.getIsSigned() ? "true" : "false") << "\n"
		<< F << "sign grade: " << E << obj.getSignGrade() << "\n"
		<< F << "exec grade: " << E << obj.getExecGrade();
	return (os);
}
