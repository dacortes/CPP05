/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:33:49 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/14 13:01:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/*
 * Orthodox Canonical AForm
*/

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << C << "Presi: " << E << "Default constrcutor called"
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << C << "Presi: " << E << "Destructor called"
		<< std::endl;
}
