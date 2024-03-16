/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/16 10:34:58 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void	testShrubberyCreationForm(void)
{
	AForm *foo;
	
	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: ShrubberyCreationForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso ", 150);
		foo = new ShrubberyCreationForm("queso");
		foo->beSigned(fuu);
		dynamic_cast<ShrubberyCreationForm*>(foo)->executeMagic();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	std::cout << C << "Test: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat fuu("eralonso ", 145);
		foo = new ShrubberyCreationForm("frangark");
		foo->beSigned(fuu);
		std::cout << *dynamic_cast<ShrubberyCreationForm*>(foo) << std::endl;
		dynamic_cast<ShrubberyCreationForm*>(foo)->executeMagic();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	delete foo;
}

void testRobotomyRequestForm (void)
{
	AForm *foo;

	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: RobotomyRequestForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso ", 73);
		foo = new RobotomyRequestForm("patata");
		foo->beSigned(fuu);
		dynamic_cast<RobotomyRequestForm*>(foo)->executeMagic();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl; 
		delete foo;
	}
	std::cout << C << "Test: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat fuu("eralonso ", SING_RRF);
		foo = new RobotomyRequestForm("frangark");
		foo->beSigned(fuu);
		std::cout << *dynamic_cast<RobotomyRequestForm*>(foo) << std::endl;
		dynamic_cast<RobotomyRequestForm*>(foo)->executeMagic();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	delete foo;
}

void	testPresidentialPardonForm(void)
{
	AForm *foo;

	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: PresidentialPardonForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso ", 26);
		foo = new PresidentialPardonForm("patata");
		foo->beSigned(fuu);
		dynamic_cast<PresidentialPardonForm*>(foo)->executeMagic();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	std::cout << C << "Test: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat fuu("eralonso ", SING_PPF);
		foo = new PresidentialPardonForm("frangark");
		foo->beSigned(fuu);
		std::cout << *dynamic_cast<PresidentialPardonForm*>(foo) << std::endl;
		dynamic_cast<PresidentialPardonForm*>(foo)->executeMagic();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	delete foo;
}

int	main(void)
{
	//line 19
	testShrubberyCreationForm();
	//line 56
	testRobotomyRequestForm();
	//line 93 
	testPresidentialPardonForm();
	return (EXIT_SUCCESS);
}
