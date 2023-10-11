/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:24 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/11 18:15:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

#define NOT_SIGNED 0
#define SIGNED 1

class Form
{
	private:
		static bool					_defaultIsSigned;
		static std::string	const 	_defaultName;
		static unsigned int const	_defaultRequiredGradeToExecute;
		static unsigned int const	_defaultRequiredGradeToSign;

		bool						_isSigned;
		std::string	const 			_name;
		unsigned int const			_requiredGradeToExecute;
		unsigned int const			_requiredGradeToSign;

	public:
		Form();
		Form(std::string name, unsigned int const requiredGradeToExecute, unsigned int const requiredGradeToSign);
		~Form();

		bool const & 				getIsSigned(void) const;
		std::string const & 		getName(void) const;
		unsigned int const & 		getRequiredGradeToExecute(void) const;
		unsigned int const & 		getRequiredGradeToSign(void) const;

		// void	GradeTooHighException();
		// void	GradeTooLowException();

		// void	setGradeToExecute(int newGrade);
		// void	setGradeToSign(int newGrade);
		
		
};

std::ostream & operator<<(std::ostream & lhs, Form const & rhs);

#endif