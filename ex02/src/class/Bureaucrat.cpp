/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 18:40:24 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string Bureaucrat::_defaultName("Gurvan");
unsigned int Bureaucrat::_defaultGrade(150);

// Constructor -----------------------------------------------------------------

Bureaucrat::Bureaucrat() : _name(_defaultName), _grade(_defaultGrade)
{
	std::cout << "Bureaucrat " << this->_name << " default constructor called.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat " << this->_name << " copy constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) 
{
	std::cout << "Bureaucrat " << this->_name << " parameter constructor called.\n";
	if (this->_grade < 1)
		throw (GradeTooHighException());
	else if (this->_grade > 150)
		throw (GradeTooLowException());
}

// Destructor ------------------------------------------------------------------

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructor called.\n";
}

// Accessors -------------------------------------------------------------------

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int const &	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int newGrade)
{
	if (newGrade < 1 || newGrade > 150)
		std::cerr << "Error: grade should be in array [1;150].\n";
	else
		this->_grade = newGrade;
}

// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	Bureaucrat::increment_grade(int newGrade)
{
	if (newGrade < 0 || newGrade > INT_MAX)
	{
		std::cerr << "Error : Try again using a value in array [0;INT_MAX].\n";
		return ;
	}
	if ((int)this->_grade - newGrade < 1)
		throw (GradeTooHighException());
	this->_grade -= newGrade;
}

void	Bureaucrat::decrement_grade(int newGrade)
{
	if (newGrade < 0 || newGrade > INT_MAX)
	{
		std::cerr << "Error : Try again using a value in array [0;INT_MAX].\n";
		return ;
	}
	if ((int)this->_grade + newGrade > 150)
		throw (GradeTooLowException());
	this->_grade += newGrade;
}

void	Bureaucrat::signForm(AForm form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << this->_name << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.beExecuted(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << this->_name << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

