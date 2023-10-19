/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:57:33 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/19 14:49:45 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

bool				Form::_defaultIsSigned(NOT_SIGNED);
std::string	const 	Form::_defaultName("Form about chess");
unsigned int const	Form::_defaultRequiredGradeToBeExecuted(150);
unsigned int const	Form::_defaultRequiredGradeToBeSigned(150);

// Constructor -----------------------------------------------------------------
Form::Form() :
	_isSigned(_defaultIsSigned), _name(_defaultName),
	_requiredGradeToBeExecuted(_defaultRequiredGradeToBeExecuted),
	_requiredGradeToBeSigned(_defaultRequiredGradeToBeSigned)
{
	std::cout << "Form " << this->_name << " default constructor called.\n\n";
}

Form::Form(std::string name, unsigned int gradeToExecute, unsigned int gradeToSign) :
	_isSigned(NOT_SIGNED), _name(name),
	_requiredGradeToBeExecuted(gradeToExecute),
	_requiredGradeToBeSigned(gradeToSign)
{
	std::cout << "Form " << this->_name << " constructor with param called.\n\n";
	if (this->_requiredGradeToBeExecuted < 1 || this->_requiredGradeToBeSigned < 1)
		throw (GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (GradeTooLowException());
}

// Destructor ------------------------------------------------------------------
Form::~Form()
{
	std::cout << "Form " << this->_name << " destructor called.\n\n";
}

// Accessors -------------------------------------------------------------------

bool const & Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

std::string const & Form::getName(void) const
{
	return (this->_name);
}

unsigned int const & Form::getRequiredGradeToBeExecuted(void) const
{
	return (this->_requiredGradeToBeExecuted);
}

unsigned int const & Form::getRequiredGradeToBeSigned(void) const
{
	return (this->_requiredGradeToBeSigned);
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, Form const & rhs)
{
	lhs << rhs.getName() << " requires grade " << rhs.getRequiredGradeToBeExecuted() << " to be executed, "
	<< rhs.getRequiredGradeToBeSigned() << " to be signed" << " and is ";
	if (rhs.getIsSigned() == NOT_SIGNED)
		lhs << "not ";
	lhs << "signed.\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned == NOT_SIGNED && bureaucrat.getGrade() <= this->_requiredGradeToBeSigned)
	{
		this->_isSigned = SIGNED;
		std::cout << bureaucrat.getName() << " signed " << this->_name << ".\n";
	}
	else if (this->_isSigned == SIGNED)
		throw (AlreadySignedException());
	else
		throw(GradeTooLowException());
}
