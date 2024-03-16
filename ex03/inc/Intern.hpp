/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:36:51 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/16 17:43:49 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CPP
# define INTERN_CPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include "AForm.hpp"

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

class Intern
{
	public:
		/*
		 * Orthodox Canonical Form
		*/
		Intern(void);
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern(void);
		/*
		 * Membert Funtions
		*/
		AForm *makeForm(std::string name, std::string target);
};
#endif
