/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 14:45:53 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <limits.h>
# include "Form.hpp"

class Form;

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
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const & rhs);

		std::string const 		&getName(void) const;
		unsigned int const		&getGrade(void) const;
		void					setGrade(int newGrade);

		void					decrement_grade(int newGrade);
		void					increment_grade(int newGrade);

		void					signForm(Form form);

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("grade too low.\n");
				}
		};
		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("grade too high.\n");
				}
		};
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("form has already been signed.\n");
				}
		};
};

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs);

#endif
