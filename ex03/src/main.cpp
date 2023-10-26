/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/26 15:30:31 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void	intern_creation(std::string form_name, std::string target)
{
	Intern	Heidi;
	AForm	*Form;

	try
	{
		Form = Heidi.makeForm("Presidential pardon", "Lisa");
		delete Form;
		Form = Heidi.makeForm("Robotomy request", "Heloise");
		delete Form;
		Form = Heidi.makeForm("Shrubbery creation", "Home");
		delete Form;
		Form = Heidi.makeForm(form_name, target);
		if (Form)
			delete Form;
	}
	catch(const std::exception)
	{
		std::cerr << "Failed. Available forms are : Presidential pardon, Robotomy request and Shrubbery creation.\n";
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Error: usage is ./intern <name of form> <target>.\n";
		return (ERROR);
	}
	try
	{
		intern_creation(argv[1], argv[2]);
	}	
	catch (std::exception)
	{
		return (ERROR);
	}
	return (SUCCESS);
}
