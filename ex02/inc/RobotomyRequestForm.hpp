/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:02:16 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/13 08:50:25 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

#include "AForm.hpp"

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		/*
		 * Orthodox Canonical AForm
		*/
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm(void)
		/*
		 * Get Methods
		*/
		std::string getTarget(void) const;
};
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
#endif
