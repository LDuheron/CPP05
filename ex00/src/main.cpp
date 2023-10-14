/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/14 17:59:36 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdlib.h> 

void	create_a_bureaucrat(char *name, int grade)
{
	Bureaucrat Gurvan(name, grade);

	std ::cout << Gurvan;
	Gurvan.setGrade(27);
	std ::cout << Gurvan;
	Gurvan.setGrade(-2);
	std ::cout << Gurvan;
	Gurvan.setGrade(158);
	std ::cout << Gurvan;
}

int	main(int argc, char **argv)
{
	std:string   tmp;

	tmp = argv[1];
	if (argc != 2)
	{
		std::cerr << "Error: usage is ./bureaucrat <name> <grade>.\n";
		return (ERROR);
	}
	try
	{
		create_a_bureaucrat(tmp, atoi(argv[2]));
	}
	catch (std::exception)
	{
		std::cerr << "Error: grade should be in array [1;150].\n";
		return (ERROR);
	}
	return (SUCCESS);
}