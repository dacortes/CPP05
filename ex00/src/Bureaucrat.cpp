/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:05:02 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/06 15:25:34 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/*
 * Orthodox Canonical Form
*/

Bureaucrat::Bureaucrat(void): name("default")
{
	std::cout << O << "Bureaucrat: " << E << "Default constructor called"
		<< std::endl;
	this->grade = 150;
}


Bureaucrat::~Bureaucrat(void)
{
	std::cout << O << "Bureaucrat: " << E << "Destructor called"
		<< std::endl;
}

/*
 * Get Methods
*/

const std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

unsigned short int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

/*
 * Membert Funtions
*/

int	Bureaucrat::IncrementGrade(int increment)
{
	this->grade -= increment;
	return (increment);
}

int Bureaucrat::DecrementGrade(int decrement)
{
	this->grade += decrement;
	return (decrement);
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << O << "Name: " << E << obj.getName() << "\n"
		<< O << "Grade: " << E << obj.getGrade();
	return (os);
}
