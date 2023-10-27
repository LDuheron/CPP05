/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:07 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructor -----------------------------------------------------------------

Intern::Intern()
{
	// std::cout << "Intern default constructor called.\n";
}

Intern::Intern(Intern const & src)
{
	(void) src;
	// std::cout << "Intern copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

Intern::~Intern()
{
	// std::cout << "Intern destructor called.\n";
}

// Overload --------------------------------------------------------------------

Intern &	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

// Functions -------------------------------------------------------------------

AForm	*Intern::makePresidentialPardon(std::string const target) const
{
	return (new PresidentialPardonForm(target));	
}

AForm	*Intern::makeRobotomyRequest(std::string const target) const
{
	return (new RobotomyRequestForm(target));	
}

AForm	*Intern::makeShrubberyCreation(std::string const target) const
{
	return (new ShrubberyCreationForm(target));	
}

AForm	*Intern::makeForm(std::string const form_name, std::string const target) const
{
	AForm*	(Intern::*ptr[])(std::string const) const = {&Intern::makePresidentialPardon, &Intern::makeRobotomyRequest, &Intern::makeShrubberyCreation};
	std::string	form_type[] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};
	int		i = 0;

	while (i < 3)
	{
		if (form_name == form_type[i])
		{
			std::cout << "Intern creates " << form_name << ".\n";
			return ((this->*ptr[i])(target));
		}
		i++;
	}
	throw (UnavailableFormException());
}
