
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
	this->grade = MIN_GRADE;
}

Bureaucrat::Bureaucrat(std::string defname, int grade): name(defname)
{
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(std::string(ERROR)
				+ std::string(INIT_CONSTRUCTOR) + std::string("Low"));
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(INIT_CONSTRUCTOR) + std::string("High"));
	else if (grade >= MAX_GRADE && grade <= MIN_GRADE)
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName())
{
	if (obj.grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("Low"));
	if (obj.grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("High"));
	else if (obj.grade >= MAX_GRADE && obj.grade <= MIN_GRADE)
		this->grade = obj.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (obj.grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("Low"));
	if (obj.grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(COPY_CONSTRUCTOR) + std::string("High"));
	else if (obj.grade >= MAX_GRADE && obj.grade <= MIN_GRADE)
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
	if (increment < MAX_GRADE)
	{
        throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID)
				+ (!increment ? "number zero" : "negative number"));
		return (-1);
	}
	else if (increment > MIN_GRADE)
	{
        throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID)
				+ std::string("parameter larger than max"));
		return (-1);
	}
	else if (this->grade <= increment)
	{
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
				+ std::string(INVALID) + std::string("High"));
		return (-1);
	}
	this->grade -= increment;
	return (increment);
}

int Bureaucrat::DecrementGrade(int decrement)
{
	if (decrement < MAX_GRADE)
    {
        throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID)
				+ (!decrement ? "number zero" : "negative number"));
		return (-1);
    }
	else if (decrement > MIN_GRADE)
	{
		throw Bureaucrat::GradeTooHighException(std::string(ERROR)
                + std::string(INVALID)
				+ std::string("parameter larger than max"));
		return (-1);
	}
    else if ((this->grade + decrement) > MIN_GRADE)
    {
       	throw Bureaucrat::GradeTooLowException(std::string(ERROR)
            	+ std::string(DECREMENT) + std::string("Low"));
		return (-1);
    }
	this->grade += decrement;
    return (this->grade);
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << SUCCESS << this->name << " signed " << form.getName() 
			<< std::endl;
	}
	catch (std::logic_error &error)
	{
		std::cout << ERROR << this->name <<  " couldn't sign " << form.getName()
		<< " because " << error.what() << std::endl;
		return ;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << SUCCESS << this->name << " execute " << form.getName()
			<< std::endl;
	}
	catch (std::logic_error &error)
	{
		std::cout << ERROR << this->name << " couldn't execute "
			<< form.getName() << " because " << error.what() << std::endl;
	}
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
