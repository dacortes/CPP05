/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/07 17:16:26 by dacortes         ###   ########.fr       */
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

void	error_grade_low(void)
{
	Bureaucrat foo("dacortes", 1);

    std::cout << C << "Test: Error: decrement" << E << std::endl;
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

int	main(void)
{
	error_init_constructor();
	error_grade_low();
	return (EXIT_SUCCESS);
}
