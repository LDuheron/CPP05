/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/10 18:40:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		static std::string		_defaultName;
		static unsigned int		_defaultGrade;
		std::string	const 		_name;
		unsigned int			_grade;

	public:
		Bureaucrat();
		~Bureaucrat();

		std::string const 	&getName(void) const;
		unsigned int const 	&getGrade(void) const;
		void				setGrade(int newGrade);
		void 				GradeTooLowException();
		void 				GradeTooHighException();
};

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs);

#endif
