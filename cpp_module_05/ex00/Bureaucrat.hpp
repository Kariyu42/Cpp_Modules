/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:35 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/06 18:37:34 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat		&operator=(Bureaucrat const &copy);
		~Bureaucrat();

		std::string const	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

		void				GradeTooHighException();
		void				GradeTooLowException();

	private:
		std::string const	_name;
		int					_grade;
};

#endif
