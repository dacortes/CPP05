/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:33 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/14 19:47:33 by codespace        ###   ########.fr       */
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
# define SING_RRF 25
# define EXEC_RRF 5

class PresidentialPardonForm:  public AForm
{
	private:
		std::string target;
	public:
		/*
		 * Orthodox Canonical AForm
		*/
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		~PresidentialPardonForm(void);
		/*
		 * Get Methods
		*/
		std::string getTarget(void) const;
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj);
#endif
