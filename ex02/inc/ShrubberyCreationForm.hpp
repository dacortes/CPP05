/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:27:03 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/13 09:15:27 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

#include "AForm.hpp"

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
	public:
		/*
		 * Orthodox Canonical AForm
		*/
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj)
		~ShrubberyCreationForm(void);
		/*
		 * Get Methods
		*/
		std::string getTarget(void) const;
		void executeForm(const Bureaucrat &obj) const;
};
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);
#endif
