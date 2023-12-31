/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:24 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:01:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

#define NOT_SIGNED 0
#define SIGNED 1

class Bureaucrat;

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
		Form(Form const & src);
		Form(std::string name, unsigned int const requiredGradeToBeExecuted, unsigned int const requiredGradeToBeSigned);
		~Form();

		Form &	operator=(Form const & rhs);	

		bool const & 				getIsSigned(void) const;
		std::string const & 		getName(void) const;
		unsigned int const & 		getRequiredGradeToBeExecuted(void) const;
		unsigned int const & 		getRequiredGradeToBeSigned(void) const;

		void						beSigned(Bureaucrat bureaucrat);

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

std::ostream & operator<<(std::ostream & lhs, Form const & rhs);

#endif