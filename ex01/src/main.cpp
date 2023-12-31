/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:03:42 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdlib.h> 

void	create_a_form(std::string name, int requiredGradeToBeExecuted, int requiredGradeToBeSigned)
{
	Bureaucrat Gurvan;
	Form	chess_form;

	std ::cout << chess_form;
	chess_form.beSigned(Gurvan);
	std::cout << "\n\n\n";
	Gurvan.signForm(chess_form);

	Form	random_form(name, requiredGradeToBeExecuted, requiredGradeToBeSigned);

	std ::cout << random_form;
	random_form.beSigned(Gurvan);

}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: usage is ./bureaucrat <name> <required grade to be executed> <required grade to be signed>.\n";
		return (ERROR);
	}

	try
	{
		create_a_form(argv[1], atoi(argv[2]), atoi(argv[3]));
	}
	catch (std::exception)
	{
		return (ERROR);
	}

	return (SUCCESS);
}
