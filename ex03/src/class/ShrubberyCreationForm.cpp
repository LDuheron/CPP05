/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:21:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 17:57:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

bool				ShrubberyCreationForm::_defaultIsSigned(NOT_SIGNED);
std::string	const 	ShrubberyCreationForm::_defaultName("Shrubbery creation");
unsigned int const	ShrubberyCreationForm::_defaultRequiredGradeToBeExecuted(137);
unsigned int const	ShrubberyCreationForm::_defaultRequiredGradeToBeSigned(145);

// Constructor -----------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(ShrubberyCreationForm::_defaultName, ShrubberyCreationForm::_defaultRequiredGradeToBeExecuted, ShrubberyCreationForm::_defaultRequiredGradeToBeSigned), _target("defaultTarget")
{
	// std::cout << "Shrubbery creation form default constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm(ShrubberyCreationForm::_defaultName, ShrubberyCreationForm::_defaultRequiredGradeToBeExecuted, ShrubberyCreationForm::_defaultRequiredGradeToBeSigned), _target(target)
{
	// std::cout << "Shrubbery creation form target constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
	// std::cout << "Shrubbery creation form copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "Shrubbery creation form destructor called.\n";
}

// Accessors -------------------------------------------------------------------

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, ShrubberyCreationForm const & rhs)
{
	lhs << rhs.getName() << " requires grade " << rhs.getRequiredGradeToBeExecuted() << " to be executed, "
	<< rhs.getRequiredGradeToBeSigned() << " to be signed" << " and is ";
	if (rhs.getIsSigned() == NOT_SIGNED)
		lhs << "not ";
	lhs << "signed. Target is " << rhs.getTarget() << ".\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
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

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->_requiredGradeToBeExecuted)
	{
		std::string test = this->_target;
		std::ofstream	file(test.append("_shrubbery").c_str());
		if (!file.is_open() || file.fail())
			throw(FileFailedException());
		file << "\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,888888/88o\n\
   ,%&%&&%&&%,@@@/@@@/@@@8888888/88888'\n\
   %&&%&%&/%&&%@@@@/ /@@@8888888888888'\n\
   %&&%/ %&%%&&@@ V /@@' `888 `/8888'\n\
   `&% ` /%&'     |.|       '8|888'\n\
       |o|        | |         | |\n\
       |.|        | |         | | "
	   << std::endl;
		file.close();
	}
	else
		throw(GradeTooLowException());
}
