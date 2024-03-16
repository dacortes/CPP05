/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:34:52 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/16 17:28:59 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

/*
 * Orthodox Canonical Form
*/
Intern::Intern(void)
{
	std::cout << B << "Inter: "<< E << "Default constrcutor called"
		<< std::endl; 
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << B << "Inter: " << E << "Destructor called"
		<< std::endl;
}

/*
 * Membert Funtions
*/

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string lv[3];
	AForm		*form[3];
	unsigned int i = 0;
	form[0] = new ShrubberyCreationForm(target); 
	form[1] = new RobotomyRequestForm(target);
	form[2] = new PresidentialPardonForm(target);
	lv[0] = NAME_SCF;
	lv[1] = NAME_RRF;
	lv[2] = NAME_PPF;
	while (i < 3 && name != lv[i])
		i++;
	switch (i)
	{
		case 0:
			delete form[1];
			delete form[2];
			break;
		case 1:
			delete form[0];
			delete form[2];
			break;
		case 2:
			delete form[0];
			delete form[1];
			break;
		default:
			delete form[0];
			delete form[1];
			delete form[2];
			std::cerr << ERROR << "name no valid" << std::endl;
			return (NULL);
	}
	return (dynamic_cast<AForm*>(form[i]));
}
