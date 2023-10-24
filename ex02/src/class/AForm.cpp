/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:57:33 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/24 11:39:34 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

bool				AForm::_defaultIsSigned(NOT_SIGNED);
std::string	const 	AForm::_defaultName("Form about chess");
unsigned int const	AForm::_defaultRequiredGradeToBeExecuted(150);
unsigned int const	AForm::_defaultRequiredGradeToBeSigned(150);

// Constructor -----------------------------------------------------------------
AForm::AForm() :
	_isSigned(_defaultIsSigned), _name(_defaultName),
	_requiredGradeToBeExecuted(_defaultRequiredGradeToBeExecuted),
	_requiredGradeToBeSigned(_defaultRequiredGradeToBeSigned)
{
	std::cout << "Form " << this->_name << " default constructor called.\n\n";
}

AForm::AForm(AForm const & src) : _isSigned(src._isSigned), _name(src._name), _requiredGradeToBeExecuted(src._requiredGradeToBeExecuted), _requiredGradeToBeSigned(src._requiredGradeToBeSigned)
{
	std::cout << "Bureaucrat " << this->_name << " copy constructor called.\n";
}

AForm::AForm(std::string name, unsigned int gradeToExecute, unsigned int gradeToSign) :
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
AForm::~AForm()
{
	std::cout << "Form " << this->_name << " destructor called.\n\n";
}

// Accessors -------------------------------------------------------------------

bool const & AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

std::string const & AForm::getName(void) const
{
	return (this->_name);
}

unsigned int const & AForm::getRequiredGradeToBeExecuted(void) const
{
	return (this->_requiredGradeToBeExecuted);
}

unsigned int const & AForm::getRequiredGradeToBeSigned(void) const
{
	return (this->_requiredGradeToBeSigned);
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, AForm const & rhs)
{
	lhs << rhs.getName() << " requires grade " << rhs.getRequiredGradeToBeExecuted() << " to be executed, "
	<< rhs.getRequiredGradeToBeSigned() << " to be signed" << " and is ";
	if (rhs.getIsSigned() == NOT_SIGNED)
		lhs << "not ";
	lhs << "signed.\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	AForm::beSigned(Bureaucrat const &bureaucrat)
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

void	AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() <= this->_requiredGradeToBeExecuted)
	{
		std::cout << bureaucrat.getName() << " executed " << this->_name << ".\n";
	}
	else
		throw(GradeTooLowException());
}
