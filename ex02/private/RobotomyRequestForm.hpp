/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:48:17 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/26 11:36:12 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private :
		static bool					_defaultIsSigned;
		static std::string	const 	_defaultName;
		static unsigned int const	_defaultRequiredGradeToBeExecuted;
		static unsigned int const	_defaultRequiredGradeToBeSigned;

		std::string	const 			_target;
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);

	public :

		RobotomyRequestForm(std::string const target);
		virtual ~RobotomyRequestForm();

		std::string		getTarget(void) const;
		
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream & operator<<(std::ostream & lhs, RobotomyRequestForm const & rhs);

#endif
