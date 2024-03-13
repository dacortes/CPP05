/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:33 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/13 08:55:12 by dacortes         ###   ########.fr       */
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
