/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:53 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/11 18:25:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/*
 * Orthodox Canonical AForm
*/
//inicializar los formularios con el constructor de la clase principal :v
ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	std::cout << T << "Shrubberry: " << E << "Default constrcutor called"
		<< std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << T << "Shrubberry: " << E << "Destructor called"
		<< std::endl;
}
