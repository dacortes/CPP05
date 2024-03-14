/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/14 12:26:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void	testShrubberyCreationForm(void)
{
	ShrubberyCreationForm	*foo;
	
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

int	main(void)
{
	//line 16
	testShrubberyCreationForm();
	return (EXIT_SUCCESS);
}
