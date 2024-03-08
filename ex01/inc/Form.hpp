/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:03:00 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/08 10:34:47 by dacortes         ###   ########.fr       */
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
		void	beSigned(const Bureaucrat &bureucrat);
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
};
std::ostream &operator<<(std::ostream &os, const Form &obj);
#endif
