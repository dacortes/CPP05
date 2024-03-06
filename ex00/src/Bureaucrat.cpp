/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:05:02 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/06 09:14:14 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/*
 * Orthodox Canonical Form
*/
Bureaucrat::Bureaucrat(void)
{
	std::cout << O << "Bureaucrat: " << E << "Default constructor called"
		<< std::endl;
	this->name = "default";
	this->grade = 150;
}


~Bureaucrat::Bureaucrat(void)
{
	std::cout << O << "Bureaucrat: " << E << "Destructor called"
		<< std::endl;
}
