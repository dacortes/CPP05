/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:05:02 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/07 12:07:02 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/*
 * Exception Classes
*/

//class Bureaucrat::GradeTooHighException: public std::range_error
//{
//	public:
//		/*
//		 * Membert Funtions
//		*/
//		std::string _msg;
//		~GradeTooHighException(void);
//		GradeTooHighException (const std::string &messege): std::range_error()
//		{
//			_msg = messege;
//		
//		};
//		const char *what () const throw (){
//			return ((_msg.c_str()));
//		}
//		//GradeTooHighException (const char *messege);
//
//};
//
//class Bureaucrat::GradeTooLowException: public std::range_error
//{
//	public:
//		/*
//		 * Membert Funtions
//		*/
//		GradeTooLowException (const std::string &messege);
//		GradeTooLowException (const char *messege);
//};
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message)
    : std::range_error(message) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message)
    : std::range_error(message) {}
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
	//if (grade < 1)
	//	throw Bureaucrat::GradeTooLowException("holi");
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException("queso");
	else if (grade >= 1 && grade <= 150)
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName())
{
	this->grade = obj.getGrade();
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
