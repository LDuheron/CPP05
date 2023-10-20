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

class AForm;

class PresidentialPardonForm : public AForm
{
	private :
		static bool					_defaultIsSigned;
		static std::string	const 	_defaultName;
		static unsigned int const	_defaultRequiredGradeToBeExecuted;
		static unsigned int const	_defaultRequiredGradeToBeSigned;

		bool						_isSigned;
		std::string	const 			_name;
		unsigned int const			_requiredGradeToBeExecuted;
		unsigned int const			_requiredGradeToBeSigned;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();

};

#endif
