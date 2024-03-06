/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:50:09 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/06 09:14:12 by dacortes         ###   ########.fr       */
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
		 * Orthodox Canonical Form
		*/
		Bureaucrat(void);
		~Bureaucrat(void);
		/*
		 * Set
		*/

		/*
		 * Get Methods
		*/
		std::string getName(void) const;
		unsigned short int getGrade(void) const;
		/*
		 * Membert Funtions
		*/
		IncrementGrade();
		DecrementGrade();
};

#endif
