/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/20 17:02:01 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

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


int	main(void)
{
	// error_init_constructor();
	loop_error_grade_low();
	// loop_error_grade_high();
	// loop_test_grade_high();
	// loop_test_grade_low();
	// error_grade_low();
	// error_grade_high();
    // Bureaucrat *foo;
    // try
    // {
    //     foo = new Bureaucrat("dacortes", 150);
    //     foo->IncrementGrade(0);
    //     // foo->DecrementGrade(0);
    //     std::cout << *foo << std::endl;
    // }
    // catch (std::range_error &error)
    // {
    //     std::cerr << error.what() << std::endl;
    // }
    // std::cout << *foo << std::endl;
	return (EXIT_SUCCESS);
}
