/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:48:17 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/20 18:14:34 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
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
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();

};

#endif
