/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/16 11:36:12 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdlib.h> 

void	create_a_bureaucrat(std::string name, int grade)
{
	Bureaucrat bureaucrat(name, grade);

	std ::cout << bureaucrat;

	// bureaucrat.setGrade(27);
	// std ::cout << bureaucrat;
	// bureaucrat.setGrade(-2);
	// std ::cout << bureaucrat;
	// bureaucrat.setGrade(158);
	// std ::cout << bureaucrat;
	// bureaucrat.setGrade(1);
	// std ::cout << bureaucrat;
	// bureaucrat.setGrade(150);
	// std ::cout << bureaucrat;

	// bureaucrat.increment_grade(-1);
	// std ::cout << bureaucrat;
	// bureaucrat.increment_grade(1);
	// std ::cout << bureaucrat;
	// bureaucrat.increment_grade(155);
	// std ::cout << bureaucrat;

	bureaucrat.decrement_grade(-1);
	std ::cout << bureaucrat;
	bureaucrat.decrement_grade(1);
	std ::cout << bureaucrat;
	bureaucrat.decrement_grade(155);
	std ::cout << bureaucrat;

}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Error: usage is ./bureaucrat <name> <grade>.\n";
		return (ERROR);
	}

	try
	{
		create_a_bureaucrat(argv[1], atoi(argv[2]));
	}
	catch (std::exception)
	{
		std::cerr << "Error: grade should be in array [1;150].\n";
		return (ERROR);
	}
	return (SUCCESS);
}
