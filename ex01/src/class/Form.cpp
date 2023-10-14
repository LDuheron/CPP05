/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:57:33 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/14 15:48:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

bool				Form::_defaultIsSigned(NOT_SIGNED);
std::string	const 	Form::_defaultName("Form about chess");
unsigned int const	Form::_defaultRequiredGradeToExecute(150);
unsigned int const	Form::_defaultRequiredGradeToSign(150);

// Constructor -----------------------------------------------------------------
Form::Form() : _isSigned(_defaultIsSigned), _name(_defaultName), _requiredGradeToExecute(_defaultRequiredGradeToExecute), _requiredGradeToSign(_defaultRequiredGradeToExecute)
{
	std::cout << "Form default constructor called.\n";
}

Form::Form(std::string name, unsigned int gradeToExecute, unsigned int gradeToSign)
{
	this->_name = name;
	this->_isSigned = NOT_SIGNED;
	try
	{
		if (gradeToExecute >= 1 && gradeToExecute <= 150)
			this->_requiredGradeToExecute = gradeToExecute;
		else 
			throw (gradeToExecute);
	if (gradeToSign >= 1 && gradeToSign <= 150)
			this->_requiredGradeToExecute = gradeToSign;
		else 
			throw (gradeToSign);
	}
	std::cout << "Form constructor with param called.\n";
}
// Destructor ------------------------------------------------------------------
Form::~Form()
{
	std::cout << "Form destructor called.\n";
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

unsigned int const & Form::getRequiredGradeToExecute(void) const
{
	return (this->_requiredGradeToExecute);
}

unsigned int const & Form::getRequiredGradeToSign(void) const
{
	return (this->_requiredGradeToSign);
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, Form const & rhs)
{
	lhs << rhs.getName() << ", requires grade " << rhs.getRequiredGradeToSign() << " to be signed, "
	<< rhs.getRequiredGradeToExecute() << " and is ";
	if (rhs.getIsSigned() == NOT_SIGNED)
		lhs << "not ";
	lhs << "signed.\n";
	return lhs;
}

// Functions -------------------------------------------------------------------
// void	Form::GradeTooLowException()
// {
// 	std::cerr << "Grade too low, lower is 150.\n";
// }

// void	Form::GradeTooHighException()
// {
// 	std::cerr << "Grade too high, higher is 1.\n";
	
// }

// void	Form::setGradeToSign(int newGrade)
// {
// 	try
// 	{
// 		if (newGrade >= 1 && newGrade <= 150)
// 			this->_requiredGradeToSign = newGrade;
// 		else 
// 		{
// 			throw (newGrade);
// 		}
// 	}
// 	catch (int newGrade)
// 	{	
// 		std::cerr << newGrade << " : ";
// 		if (newGrade < 1)
// 			Form::GradeTooHighException();
// 		else if (newGrade > 150)
// 			Form::GradeTooLowException();
// 	}
// }

void	Form::setGradeToExecute(int newGrade)
{
	try
	{
		if (newGrade >= 1 && newGrade <= 150)
			this->_requiredGradeToExecute = newGrade;
		else 
		{
			throw (newGrade);
		}
	}
	catch (int newGrade)
	{	
		std::cerr << newGrade << " : ";
		if (newGrade < 1)
			Form::GradeTooHighException();
		else if (newGrade > 150)
			Form::GradeTooLowException();
	}
}

