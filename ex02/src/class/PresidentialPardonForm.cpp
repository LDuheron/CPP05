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
unsigned int const	PresidentialPardonForm::_defaultRequiredGradeToBeExecuted(5);
unsigned int const	PresidentialPardonForm::_defaultRequiredGradeToBeSigned(25);

// Constructor -----------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm() : AForm(PresidentialPardonForm::_defaultName, PresidentialPardonForm::_defaultRequiredGradeToBeExecuted, PresidentialPardonForm::_defaultRequiredGradeToBeSigned), _target("defaultTarget")
{
	// std::cout << "Presidential pardon form default constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm(PresidentialPardonForm::_defaultName, PresidentialPardonForm::_defaultRequiredGradeToBeExecuted, PresidentialPardonForm::_defaultRequiredGradeToBeSigned), _target(target)
{
	// std::cout << "Presidential pardon form target constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _target(src._target)
{
	// std::cout << "Presidential pardon form copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Presidential pardon form destructor called.\n";
}

// Accessors -------------------------------------------------------------------

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, PresidentialPardonForm const & rhs)
{
	lhs << rhs.getName() << " requires grade " << rhs.getRequiredGradeToBeExecuted() << " to be executed, "
	<< rhs.getRequiredGradeToBeSigned() << " to be signed" << " and is ";
	if (rhs.getIsSigned() == NOT_SIGNED)
		lhs << "not ";
	lhs << "signed. Target is " << rhs.getTarget() << ".\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	PresidentialPardonForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_isSigned == NOT_SIGNED && bureaucrat.getGrade() <= this->_requiredGradeToBeSigned)
	{
		this->_isSigned = SIGNED;
		std::cout << bureaucrat.getName() << " signed " << this->_name << ".\n";
	}
	else if (this->_isSigned == SIGNED)
	{
		std::cout << this->_name << " has already been signed.\n";
		throw (AlreadySignedException());
	}
	else
		throw(GradeTooLowException());
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->_requiredGradeToBeExecuted)
	{
		std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox.\n";
	}
	else
		throw(GradeTooLowException());
}
