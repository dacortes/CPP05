/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/11 17:42:33 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

void	error_init_constructor(void)
{
	Bureaucrat *foo;

	std::cout << C << "Test: Error: Init constructor" << E << std::endl;
	try
	{
		foo = new Bureaucrat("dacortes", 151);
	}
	catch (const std::range_error &error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		foo = new Bureaucrat("dacortes", -1);
	}
	catch (const std::range_error &error)
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << C << "Test: Init constructor" << E << std::endl;
	foo = new Bureaucrat("dacortes", 150);
	std::cout << *foo << std::endl;
	delete foo;
}

void	loop_error_grade_low(void)
{
	Bureaucrat foo("dacortes", 1);

    std::cout << C << "Test loop: Error: decrement" << E << std::endl;
    int dec = 1;
    try
    {
        while (true)
        {
            dec = foo.DecrementGrade(1);
            std::cout << B << "Decrement: " << E << dec << std::endl;
            std::cout << foo << std::endl;
        }
    }
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void	error_grade_low(void)
{
	Bureaucrat foo("dacortes", 1);

    std::cout << C << "Test: Error: decrement" << E << std::endl;
	try
	{
    	std::cout << B << "Test: Error: number negative" << E << std::endl;
		foo.DecrementGrade(-1);
		std::cout << foo << std::endl;
	}
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
	try
	{
		std::cout << B << "Test: Error: parameter larger than default"
			<< E << std::endl;
		foo.DecrementGrade(200);
		std::cout << foo << std::endl;
	}
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void	loop_error_grade_high(void)
{
	Bureaucrat foo("dacortes", 150);

    std::cout << C << "Test loop: Error: increment" << E << std::endl;
    int dec = 1;
    try
    {
        while (true)
        {
            dec = foo.IncrementGrade(1);
            std::cout << B << "Decrement: " << E << dec << std::endl;
            std::cout << foo << std::endl;
        }
    }
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void	error_grade_high(void)
{
	Bureaucrat foo("dacortes", 1);

    std::cout << C << "Test: Error: increment" << E << std::endl;
	try
	{
    	std::cout << B << "Test: Error: number negative" << E << std::endl;
		foo.IncrementGrade(-1);
		std::cout << foo << std::endl;
	}
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
	try
	{
		std::cout << B << "Test: Error: parameter larger than default"
			<< std::endl;
		foo.IncrementGrade(200);
		std::cout << foo << std::endl;
	}
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void	loop_test_grade_high(void)
{
	Bureaucrat foo("dacortes", 150);

    std::cout << C << "Test loop: increment" << E << std::endl;
    try
    {
        while (foo.getGrade() != 1)
        {
            foo.IncrementGrade(1);
            std::cout << foo << std::endl;
        }
    }
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void	loop_test_grade_low(void)
{

	Bureaucrat foo("dacortes", 1);

    std::cout << C << "Test loop: decrement" << E << std::endl;
    try
    {
        while (foo.getGrade() != 150)
        {
            foo.DecrementGrade(1);
            std::cout << foo << std::endl;
        }
    }
    catch (const std::range_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void	form_error_init_constructor(void)
{
	AForm	*foo;	
	std::cout << C << "Test AForm: Error: Init constructor" << E << std::endl;
	try
	{
		foo = new AForm("patata", 151, 0);
	}
	catch (std::range_error &error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		foo = new AForm("patata", -1, -1);
	}
	catch (std::range_error &error)
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << C << "Test AForm: Init constructor" << E << std::endl;
	foo = new AForm("patata", 100, 100);
	std::cout << *foo << std::endl;
	delete foo;
}

void error_sign_form(void)
{
	AForm *foo;
	Bureaucrat *fuu;
	Bureaucrat *fiu;

	try
	{
		foo = new AForm("patata", 100, 100);
		fuu = new Bureaucrat("dacortes", 1);
		fiu = new Bureaucrat("eralonso", 1);
		foo->beSigned(*fuu);
		foo->beSigned(*fiu);
	}
	catch (std::logic_error &error)
	{
		std::cout << error.what() << std::endl;
		delete foo;
		delete fuu;
		delete fiu;
	}
}

int	main(void)
{
	/*
	 * Test Bureaucrat
	*/
	//line: 15
	//error_init_constructor();
	//line: 42
	//loop_error_grade_low();
	//line:63
	//loop_error_grade_high();
	//line: 91
	//loop_test_grade_high();
	//line: 112
	//loop_test_grade_low();
	//line: 140
	//error_grade_low();
	//line: 159
	//error_grade_high();
	/*
	 * Test AForm
	*/
	//line: 179
	form_error_init_constructor();
	//line: 205
	error_sign_form();
	return (EXIT_SUCCESS);
}
