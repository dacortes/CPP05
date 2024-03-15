/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/15 16:01:36 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void	testShrubberyCreationForm(void)
{
	ShrubberyCreationForm	*foo;
	
	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: ShrubberyCreationForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso", 150);
		foo = new ShrubberyCreationForm("patata", "queso");
		foo->beSigned(fuu);
		foo->executeForm();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	std::cout << C << "Test: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat fuu("eralonso", 145);
		foo = new ShrubberyCreationForm("dacortes", "frangark");
		foo->beSigned(fuu);
		std::cout << *foo << std::endl;
		foo->executeForm();
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
	RobotomyRequestForm *foo;

	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: RobotomyRequestForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso", 73);
		foo = new RobotomyRequestForm("queso", "patata");
		foo->beSigned(fuu);
		foo->executeForm();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl; 
		delete foo;
	}
	std::cout << C << "Test: Grade: Bureaucrat" << E << std::endl;
		try
	{
		Bureaucrat fuu("eralonso", SING_RRF);
		foo = new RobotomyRequestForm("dacortes", "frangark");
		foo->beSigned(fuu);
		std::cout << *foo << std::endl;
		foo->executeForm();
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
	PresidentialPardonForm *foo;

	std::cout << C << "---------------------------------" << E << std::endl;
	std::cout << C << "Test: PresidentialPardonForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	std::cout << C << "---------------------------------" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso", 26);
		foo = new PresidentialPardonForm("queso", "patata");
		foo->beSigned(fuu);
		foo->executeForm();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		delete foo;
	}
	std::cout << C << "Test: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat fuu("eralonso", SING_PPF);
		foo = new PresidentialPardonForm("dacortes", "frangark");
		foo->beSigned(fuu);
		std::cout << *foo << std::endl;
		foo->executeForm();
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
	//line 16
	testShrubberyCreationForm();
	//line 52
	testRobotomyRequestForm();
	//line 86
	testPresidentialPardonForm();
	return (EXIT_SUCCESS);
}
