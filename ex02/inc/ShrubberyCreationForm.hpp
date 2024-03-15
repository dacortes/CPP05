/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:27:03 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/15 16:32:41 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include "AForm.hpp"
# include <fstream>

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

# define NAME_SCF "ShrubberyCreationForm: "
# define SING_SCF 145
# define EXEC_SCF 137

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
		/*
		 * Orthodox Canonical Form: Default constructor
		*/
		ShrubberyCreationForm(void);
	public:
		/*
		 * Orthodox Canonical Form
		*/
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm(std::string deftarget);
		~ShrubberyCreationForm(void);
		/*
		 * Get Methods
		*/
		std::string getTarget(void) const;
		void executeForm(void) const;
};
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);
#endif
