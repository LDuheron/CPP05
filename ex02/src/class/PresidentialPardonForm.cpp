/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:21:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 17:57:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

bool				PresidentialPardonForm::_defaultIsSigned(NOT_SIGNED);
std::string	const 	PresidentialPardonForm::_defaultName("Presidential pardon form");
unsigned int const	PresidentialPardonForm::_defaultRequiredGradeToBeExecuted(45);
unsigned int const	PresidentialPardonForm::_defaultRequiredGradeToBeSigned(72);

// Constructor -----------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm() : AForm(PresidentialPardonForm::_defaultName, PresidentialPardonForm::_defaultRequiredGradeToBeExecuted, PresidentialPardonForm::_defaultRequiredGradeToBeSigned)
{
	std::cout << "Presidential pardon form default constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
	std::cout << "Presidential pardon form copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential pardon form destructor called.\n";
}

// Accessors -------------------------------------------------------------------

// Overload --------------------------------------------------------------------

// Functions -------------------------------------------------------------------
