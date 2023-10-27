/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:55:14 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:19:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern &	operator=(Intern const & rhs);

		AForm	*makeForm(std::string const form_name, std::string const target) const;
		AForm	*makePresidentialPardon(std::string const target) const;
		AForm	*makeRobotomyRequest(std::string const target) const;
		AForm	*makeShrubberyCreation(std::string const target) const;

		class UnavailableFormException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form unavailable.\n");
				}
		};

};

#endif
