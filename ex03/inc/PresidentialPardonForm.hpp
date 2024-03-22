/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:33 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/22 12:31:59 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

#include "AForm.hpp"

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

# define NAME_PPF "PresidentialPardonForm: "
# define SING_PPF 25
# define EXEC_PPF 5

class PresidentialPardonForm:  public AForm
{
	private:
		std::string target;
		/*
		 * Orthodox Canonical AForm: Default constructor
		*/
		PresidentialPardonForm(void);
	public:
		/*
		 * Orthodox Canonical AForm
		*/
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		PresidentialPardonForm(std::string deftarget);
		~PresidentialPardonForm(void);
		/*
		 * Get Methods
		*/
		std::string getTarget(void) const;
		void executeMagic(void) const;
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj);
#endif
