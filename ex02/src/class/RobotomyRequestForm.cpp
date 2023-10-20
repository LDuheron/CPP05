/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:21:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 17:59:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool				RobotomyRequestForm::_defaultIsSigned(NOT_SIGNED);
std::string	const 	RobotomyRequestForm::_defaultName("Robotomy request form");
unsigned int const	RobotomyRequestForm::_defaultRequiredGradeToBeExecuted(45);
unsigned int const	RobotomyRequestForm::_defaultRequiredGradeToBeSigned(72);

// Constructor -----------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm(RobotomyRequestForm::_defaultName, RobotomyRequestForm::_defaultRequiredGradeToBeExecuted, RobotomyRequestForm::_defaultRequiredGradeToBeSigned)
{
	std::cout << "Robotomy request form default constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
	std::cout << "Robotomy request form copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Robotomy request form destructor called.\n";
}

// Accessors -------------------------------------------------------------------

// Overload --------------------------------------------------------------------

// Functions -------------------------------------------------------------------
