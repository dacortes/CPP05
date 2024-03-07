/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/07 12:11:39 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	try
	{
	Bureaucrat	foo("dacortes", 151);
	}
	catch (const std::range_error &e)
	{
		std::cout  << e.what() << std::endl; 
	}

	//std::cout << foo << std::endl;
	//std::cout << O << "Increment: " << E << foo.IncrementGrade(1) << std::endl;
	//std::cout << O << "getGrade: " << E << foo.getGrade() << std::endl;
	return (EXIT_SUCCESS);
}
