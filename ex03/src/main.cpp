/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/22 18:19:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

#include <fcntl.h>
#include <unistd.h>

#define C_DEFAULT	"\033[0m"
#define C_RED		"\033[1;91m"
#define C_GREEN		"\033[1;92m"
#define C_YELLOW	"\033[1;93m"
#define C_BLUE		"\033[1;94m"
#define C_PINK		"\033[1;95m"
#define C_CYAN		"\033[1;96m"
#define C_WHITE		"\033[1;97m"
#define C_PURPLE	"\033[1;38;2;150;25;250m"

# define PPF_SIGN_GRADE 25
# define PPF_EXEC_GRADE 5

# define RRF_SIGN_GRADE 72
# define RRF_EXEC_GRADE 45

# define SCF_SIGN_GRADE 145
# define SCF_EXEC_GRADE 137

# define MIN_GRADE 150
# define MAX_GRADE 1
# define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)

// Utils
void	doInternMakeFormTest( unsigned int& testNumber, std::string testName, std::string formName, std::string target )
{
	Intern	intern;

	std::cout << C_BLUE << "Test " << testNumber++ << ": " << C_PINK << "" << testName \
				<< " in makeForm method: intern.makeForm( " << formName << ", " << target \
				<< " )" << C_WHITE << std::endl;
	AForm	*form = intern.makeForm( formName, target );
	std::cout << C_CYAN << "[ RES ] " << C_WHITE << " form stats -> " << form \
				<< ( form != NULL ? " && Target: " + static_cast< ShrubberyCreationForm * >( form )->getTarget() : "" ) << std::endl;
	std::cout << C_BLUE << "End of test\n" << C_WHITE << std::endl;
	if ( form )
		delete form;
}

//Tests
void	testsInternMakeForm( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	// Invalid forms
	doInternMakeFormTest( testNumber, "Invalid form", "shrubery cation", "SCInvalidFTarget" );

	doInternMakeFormTest( testNumber, "Invalid form", "robotomy request ", "RRInvalidFTarget" );

	doInternMakeFormTest( testNumber, "Invalid form", "Presidential pardon", "PPInvalidFTarget" );

	// Valid forms
	doInternMakeFormTest( testNumber, "Valid ShrubberyCreationForm", "shrubbery creation", "SCFTarget" );

	doInternMakeFormTest( testNumber, "Valid RobotomyRequestForm", "robotomy request", "RRFTarget" );

	doInternMakeFormTest( testNumber, "Valid PresidentialPardonForm", "presidential pardon", "PPFTarget" );

}

bool	executionQuestion( std::string testsName )
{
	std::string	answer;

	std::cout << C_YELLOW << "Do you want to execute the \"" << testsName << "\" tests [ y / n ]: " << C_WHITE;
	std::getline( std::cin, answer );
	if ( answer.compare( "Y" ) == 0 || answer.compare( "y" ) == 0 )
	{
		std::cout << std::endl;
		return ( true );
	}
	return ( false );
}

int	main( void )
{
	if ( executionQuestion( "Intern makeForm() method" ) == true )
		testsInternMakeForm();
	std::cout << std::endl;

	return ( 0 );
}

// void testInitIntern(void)
// {
// 	Intern foo;

// 	std::cout << C << "---------------------------------" << E << std::endl;
// 	std::cout << C << "Test: Init: Intern" << E << std::endl;
// 	std::cout << C << "---------------------------------" << E << std::endl;
// 	AForm *fuu = foo.makeForm(NAME_SCF, "patata");
// 	if (fuu)
// 	{
// 		std::cout << *fuu << std::endl;
// 		delete fuu;
// 	}
// 	AForm *fii = foo.makeForm(NAME_RRF, "patata");
// 	if (fii)
// 	{
// 		std::cout << *fii << std::endl;
// 		delete fii;
// 	}
// 	AForm *fee = foo.makeForm(NAME_PPF, "patata");
// 	if (fee)
// 	{
// 		std::cout << *fee << std::endl;
// 		delete fee;
// 	}
// }

// void testInitErrorIntern(void)
// {
// 	Intern foo;

// 	std::cout << C << "---------------------------------" << E << std::endl;
// 	std::cout << C << "Test: Error: Init: Intern" << E << std::endl;
// 	std::cout << C << "---------------------------------" << E << std::endl;
// 	AForm *fuu = foo.makeForm("eralonso", "queso");
// 	if (fuu)
// 	{
// 		std::cout << *fuu << std::endl;
// 		delete fuu;
// 	}
// }


// int	main(void)
// {
// 	//liene 20
// 	testInitIntern();
// 	//line 35
// 	testInitErrorIntern();
// 	return (EXIT_SUCCESS);
// }
