/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/14 18:08:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

void	testShrubberyCreationForm(void)
{
	ShrubberyCreationForm	*foo;
	
	std::cout << C << "Test: ShrubberyCreationForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso", 150);
		foo = new ShrubberyCreationForm("patata", "queso");
		foo->beSigned(fuu);
		foo->executeForm();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << '\n';
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
		std::cerr << error.what() << '\n';
		delete foo;
	}
	delete foo;
}

void testRobotomyRequestForm (void)
{
	RobotomyRequestForm *foo;
	std::cout << C << "Test: RobotomyRequestForm" << E << std::endl;
	std::cout << C << "Test: Error: Grade: Bureaucrat" << E << std::endl;
	try
	{
		Bureaucrat	fuu("eralonso", SING_SCF);
		foo = new RobotomyRequestForm("queso", "patata");
		foo->beSigned(fuu);
		foo->executeForm();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << '\n';
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
		std::cerr << error.what() << '\n';
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
	return (EXIT_SUCCESS);
}
