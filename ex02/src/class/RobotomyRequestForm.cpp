/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:21:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/26 11:46:37 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool				RobotomyRequestForm::_defaultIsSigned(NOT_SIGNED);
std::string	const 	RobotomyRequestForm::_defaultName("Robotomy request form");
unsigned int const	RobotomyRequestForm::_defaultRequiredGradeToBeExecuted(45);
unsigned int const	RobotomyRequestForm::_defaultRequiredGradeToBeSigned(72);

// Constructor -----------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm(RobotomyRequestForm::_defaultName, RobotomyRequestForm::_defaultRequiredGradeToBeExecuted, RobotomyRequestForm::_defaultRequiredGradeToBeSigned), _target("defaultTarget")
{
	// std::cout << "Robotomy request form default constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm(RobotomyRequestForm::_defaultName, RobotomyRequestForm::_defaultRequiredGradeToBeExecuted, RobotomyRequestForm::_defaultRequiredGradeToBeSigned), _target(target)
{
	// std::cout << "Robotomy request form target constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
	// std::cout << "Robotomy request form copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Robotomy request form destructor called.\n";
}

// Accessors -------------------------------------------------------------------

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, RobotomyRequestForm const & rhs)
{
	lhs << rhs.getName() << " requires grade " << rhs.getRequiredGradeToBeExecuted() << " to be executed, "
	<< rhs.getRequiredGradeToBeSigned() << " to be signed" << " and is ";
	if (rhs.getIsSigned() == NOT_SIGNED)
		lhs << "not ";
	lhs << "signed. Target is " << rhs.getTarget() << ".\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	RobotomyRequestForm::beSigned(Bureaucrat const &bureaucrat)
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

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->_requiredGradeToBeExecuted)
	{
		if ((rand() % 2) == 0)
			std::cout << this->_target << " has been robotomized succesfully.\n";
		else
			std::cout << "Robotomy on " << this->_target << " failed\n";
	}
	else
		throw(GradeTooLowException());
}
