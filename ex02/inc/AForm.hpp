/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:03:00 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/16 10:31:09 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const unsigned int	signGrade;
		const unsigned int	execGrade;
	public:
		/*
		 * Orthodox Canonical AForm
		*/
		AForm(void);
		AForm(std::string defname, unsigned int def_sign, unsigned int def_exec);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm(void);
		/*
		 * Get Methods
		*/
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;
		/*
		 * Membert Funtions
		*/
		void	checker(unsigned int verify, unsigned int min, unsigned int max,
				std::string msg) const;
		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(const Bureaucrat &executor) const;
		virtual void executeMagic(void) const = 0;
		/*
		 * Exception Classes
		*/
		class GradeTooLowException: public std::range_error
		{
			public:
				GradeTooLowException(const std::string &msg);
		};
		class GradeTooHighException: public std::range_error
		{
			public:
				GradeTooHighException(const std::string &msg);
		};
		class IsSignedException: public std::logic_error
		{
			public:
				IsSignedException(const std::string &msg);
		};
};
std::ostream &operator<<(std::ostream &os, const AForm &obj);
#endif
