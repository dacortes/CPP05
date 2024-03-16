/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:02:16 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/16 10:32:45 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

#include "AForm.hpp"
#include <time.h>

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

# define NAME_RRF "RobotomyRequestForm: "
# define SING_RRF 72
# define EXEC_RRF 45

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
		/*
		 * Orthodox Canonical Formi: Default constructor
		*/
		RobotomyRequestForm(void);
	public:
		/*
		 * Orthodox Canonical Form
		*/
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		RobotomyRequestForm(std::string deftarget);
		~RobotomyRequestForm(void);
		/*
		 * Get Methods
		*/
		std::string getTarget(void) const;
		void executeMagic(void) const;
};
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
#endif
