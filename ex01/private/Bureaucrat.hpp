/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/16 11:36:22 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <limits.h>

#define SUCCESS 0
#define ERROR 1

class Bureaucrat
{
	private:
		static std::string		_defaultName;
		static unsigned int		_defaultGrade;
		std::string	const 		_name;
		unsigned int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		std::string const 		&getName(void) const;
		unsigned int const		&getGrade(void) const;
		void					setGrade(int newGrade);

		void					decrement_grade(int newGrade);
		void					increment_grade(int newGrade);
		
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too low, lower is 150.\n");
				}
		};
		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high, higher is 1.\n");
				}
		};
};

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs);

#endif
