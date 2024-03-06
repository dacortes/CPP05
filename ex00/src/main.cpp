/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/06 15:25:18 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	foo;

	std::cout << foo << std::endl;
	std::cout << O << "Increment: " << E << foo.IncrementGrade(1) << std::endl;
	std::cout << O << "getGrade: " << E << foo.getGrade() << std::endl;
	return (EXIT_SUCCESS);
}
