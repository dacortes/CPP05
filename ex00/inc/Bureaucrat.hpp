/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:50:09 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/07 12:06:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include <string>
# include <cstdlib>
# include <iostream>

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define E "\033[m"                 //end
# define R "\033[1m\033[1;31m"      //red
# define G "\033[1m\033[1;32m"      //green
# define Y "\033[1m\033[1;33m"      //yellow
# define B "\033[1;34m"             //blue
# define T "\033[1m\033[1;35m"      //Turquesa
# define C "\033[1;36m"             //Cyan
# define O "\033[1m\033[38;5;208m"  //orange
# define F "\033[1m\033[38;5;128m"  //purple

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

class  Bureaucrat
{
	private:
		const std::string	name;
		unsigned short int	grade;
	public:
		/*
		 * Exception Classes
		*/
	//	class	GradeTooHighException;
	//	class	GradeTooLowException;
		    class GradeTooLowException: public std::range_error {
    public:
        GradeTooLowException(const std::string &message);
    };

    class GradeTooHighException: public std::range_error {
    public:
        GradeTooHighException(const std::string &message);
    };
		/*
		 * Orthodox Canonical Form
		*/
		Bureaucrat(void);
		Bureaucrat(std::string defname, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat(void);
		/*
		 * Get Methods
		*/
		const std::string getName(void) const;
		unsigned short int getGrade(void) const;
		/*
		 * Membert Funtions
		*/
		int	IncrementGrade(int increment);
		int	DecrementGrade(int decrement);
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
#endif
