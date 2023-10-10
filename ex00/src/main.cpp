/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/10 19:45:40 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Gurvan;

	std ::cout << Gurvan;
	Gurvan.setGrade(27);
	std ::cout << Gurvan;
	Gurvan.setGrade(-2);
	std ::cout << Gurvan;
	Gurvan.setGrade(158);
	std ::cout << Gurvan;
	return (0);
}