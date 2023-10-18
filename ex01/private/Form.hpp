/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:24 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/18 19:16:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

#define NOT_SIGNED 0
#define SIGNED 1

class Form
{
	private:
		static bool					_defaultIsSigned;
		static std::string	const 	_defaultName;
		static unsigned int const	_defaultRequiredGradeToBeExecuted;
		static unsigned int const	_defaultRequiredGradeToBeSigned;

		bool						_isSigned;
		std::string	const 			_name;
		unsigned int const			_requiredGradeToBeExecuted;
		unsigned int const			_requiredGradeToBeSigned;

	public:
		Form();
		Form(std::string name, unsigned int const requiredGradeToBeExecuted, unsigned int const requiredGradeToBeSigned);
		~Form();

		bool const & 				getIsSigned(void) const;
		std::string const & 		getName(void) const;
		unsigned int const & 		getRequiredGradeToBeExecuted(void) const;
		unsigned int const & 		getRequiredGradeToBeSigned(void) const;

		void	beSigned(Bureaucrat bureaucrat);

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

std::ostream & operator<<(std::ostream & lhs, Form const & rhs);

#endif