/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/14 18:00:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string Bureaucrat::_defaultName("Gurvan");
unsigned int Bureaucrat::_defaultGrade(150);

// Constructor -----------------------------------------------------------------

Bureaucrat::Bureaucrat() : _name(_defaultName), _grade(_defaultGrade)
{
	std::cout << "Bureaucrat default constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade)
{
	this->_name = name;
	setGrade(grade);
	std::cout << "Bureaucrat parameter constructor called.\n";
}

// Destructor ------------------------------------------------------------------

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called.\n";
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


// Overload --------------------------------------------------------------------

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return lhs;
}

// Functions -------------------------------------------------------------------

void	Bureaucrat::setGrade(int newGrade)
{
	if (newGrade >= 1 && newGrade <= 150)
		this->_grade = newGrade;
	else if (newGrade < 1)
		throw (GradeTooHighException());
	else if (newGrade > 150)
		throw (GradeTooLowException());
}
