/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:36:19 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 18:31:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

bool				ShrubberyCreationForm::_defaultIsSigned(NOT_SIGNED);
std::string	const 	ShrubberyCreationForm::_defaultName("Shrubbery creation form");
unsigned int const	ShrubberyCreationForm::_defaultRequiredGradeToBeExecuted(137);
unsigned int const	ShrubberyCreationForm::_defaultRequiredGradeToBeSigned(145);

// Constructor -----------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(ShrubberyCreationForm::_defaultName, ShrubberyCreationForm::_defaultRequiredGradeToBeExecuted, ShrubberyCreationForm::_defaultRequiredGradeToBeSigned), _isSigned(_defaultIsSigned)
{
	std::cout << "Shrubbery creation form default constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
	std::cout << "Shrubbery creation form copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery creation form destructor called.\n";
}

// Accessors -------------------------------------------------------------------

// Overload --------------------------------------------------------------------

// Functions -------------------------------------------------------------------
