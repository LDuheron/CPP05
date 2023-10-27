/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/26 11:54:36 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <stdlib.h> 

void	create_a_president_form(std::string target)
{
	Bureaucrat 				William;
	Bureaucrat 				Hugo("Hugo", 1);
	PresidentialPardonForm	form(target);

	std ::cout << form;
	std::cout << "\n";

	try
	{
		form.execute(William);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << William.getName() << " couldn't execute " << form.getName() << " because " << e.what();
	}
	try
	{
		form.beSigned(William);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << William.getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
	William.signForm(form);
	William.executeForm(form);

	std::cout << "\n";
	Hugo.signForm(form);
	Hugo.executeForm(form);
	Hugo.signForm(form);
}

void	create_a_shrubbery_form(std::string target)
{
	Bureaucrat 				Gurvan;
	Bureaucrat 				Meryem("Meryem", 1);
	ShrubberyCreationForm	form(target);

	std ::cout << form;
	std::cout << "\n";

	try
	{
		form.execute(Gurvan);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << Gurvan.getName() << " couldn't execute " << form.getName() << " because " << e.what();
	}
	try
	{
		form.beSigned(Gurvan);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << Gurvan.getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
	Gurvan.signForm(form);
	Gurvan.executeForm(form);

	std::cout << "\n";
	Meryem.signForm(form);
	Meryem.executeForm(form);
	Meryem.signForm(form);
}

void	create_a_robotomy_form(std::string target)
{
	Bureaucrat 				Axel;
	Bureaucrat 				Karim("Karim", 1);
	RobotomyRequestForm		form(target);

	std ::cout << form;
	std::cout << "\n";

	try
	{
		form.execute(Axel);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << Axel.getName() << " couldn't execute " << form.getName() << " because " << e.what();
	}
	try
	{
		form.beSigned(Axel);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat " << Axel.getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
	Axel.signForm(form);
	Axel.executeForm(form);

	std::cout << "\n";
	Karim.signForm(form);
	Karim.executeForm(form);
	Karim.signForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
	Karim.executeForm(form);
}
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: usage is ./Form <target>.\n";
		return (ERROR);
	}
	try
	{
		create_a_shrubbery_form(argv[1]);
		create_a_robotomy_form(argv[1]);
		create_a_president_form(argv[1]);
	}	
	catch (std::exception)
	{
		return (ERROR);
	}
	return (SUCCESS);
}
