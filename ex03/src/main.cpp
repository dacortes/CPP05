/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/16 17:43:48 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void testInitIntern(void)
{
	Intern foo;

	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: Init: Intern" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	AForm *fuu = foo.makeForm(NAME_SCF, "patata");
	if (fuu)
	{
		std::cout << *fuu << std::endl;
		delete fuu;
	}
	AForm *fii = foo.makeForm(NAME_RRF, "patata");
	if (fii)
	{
		std::cout << *fii << std::endl;
		delete fii;
	}
	AForm *fee = foo.makeForm(NAME_PPF, "patata");
	if (fee)
	{
		std::cout << *fee << std::endl;
		delete fee;
	}
}

void testInitErrorIntern(void)
{
	Intern foo;

	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: Error: Init: Intern" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	AForm *fuu = foo.makeForm("eralonso", "queso");
	if (fuu)
	{
		std::cout << *fuu << std::endl;
		delete fuu;
	}
}


int	main(void)
{
	//liene 20
	testInitIntern();
	//line 35
	testInitErrorIntern();
	return (EXIT_SUCCESS);
}
