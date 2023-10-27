/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:48:17 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:10:49 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
	private :
		static bool					_defaultIsSigned;
		static std::string	const 	_defaultName;
		static unsigned int const	_defaultRequiredGradeToBeExecuted;
		static unsigned int const	_defaultRequiredGradeToBeSigned;

		std::string	const 			_target;
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);

		class FileFailedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (" file creation failed.\n");
				}
		};

	public :

		ShrubberyCreationForm(std::string const target);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);

		std::string		getTarget(void) const;
		
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream & operator<<(std::ostream & lhs, ShrubberyCreationForm const & rhs);

#endif
