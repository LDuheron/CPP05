/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:48:17 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 15:16:26 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		static bool					_defaultIsSigned;
		static std::string	const 	_defaultName;
		static unsigned int const	_defaultRequiredGradeToBeExecuted;
		static unsigned int const	_defaultRequiredGradeToBeSigned;

		std::string	const 			_target;
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);

	public :
		
		PresidentialPardonForm(std::string const target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);

		std::string		getTarget(void) const;
		
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream & operator<<(std::ostream & lhs, PresidentialPardonForm const & rhs);

#endif
