/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:03:00 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/11 13:32:23 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include "Bureaucrat.hpp"

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const unsigned int	signGrade;
		const unsigned int	execGrade;
	public:
		/*
		 * Orthodox Canonical Form
		*/
		Form(void);
		Form(std::string defname, unsigned int def_sign, unsigned int def_exec);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form(void);
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
				std::string msg);
		void	beSigned(const Bureaucrat &bureaucrat);
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
std::ostream &operator<<(std::ostream &os, const Form &obj);
#endif
