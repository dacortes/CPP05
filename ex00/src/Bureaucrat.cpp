/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:05:02 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/08 11:20:20 by dacortes         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(std::string defname, int grade): name(defname)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException(std::string(ERROR)
				+ std::string(INIT_CONSTRUCTOR) + std::string("Low"));
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(INIT_CONSTRUCTOR) + std::string("High"));
	else if (grade >= 1 && grade <= 150)
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName())
{
	if (obj.grade > 150)
		throw Bureaucrat::GradeTooLowException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("Low"));
	if (obj.grade < 1)
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("High"));
	else if (obj.grade >= 1 && obj.grade <= 150)
		this->grade = obj.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (obj.grade > 150)
		throw Bureaucrat::GradeTooLowException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("Low"));
	if (obj.grade < 1)
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("High"));
	else if (obj.grade >= 1 && obj.grade <= 150)
		this->grade = obj.getGrade();
	return (*this);
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
	if (increment > 150)
	{
        throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID)
				+ std::string("parameter larger than max"));
	}
	else if (increment < 1)
	{
        throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID) + std::string("negative number"));
	}
	else
	{
		this->grade -= increment;
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("High"));
	}
	return (increment);
}

int Bureaucrat::DecrementGrade(int decrement)
{
	if (decrement < 1)
    {
        throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID) + std::string("negative number"));
    }
    else
    {
        this->grade += decrement;
		if (this->grade > 150)
        {
        	throw Bureaucrat::GradeTooLowException(std::string(ERROR)
            	+ std::string(DECREMENT) + std::string("Low"));
        }
    }
    return (this->grade);
}

/*
 * Exception Classes
*/
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg)
    : std::range_error(msg)
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg)
    : std::range_error(msg)
{}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << O << "Name: " << E << obj.getName() << "\n"
		<< O << "Grade: " << E << obj.getGrade();
	return (os);
}
