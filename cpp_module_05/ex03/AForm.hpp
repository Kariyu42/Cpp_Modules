/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:28:17 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:32:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

//TODO Must add a pure virtual method for the class to be abstract: 
class AForm
{
	public:
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		AForm		&operator=(AForm const &copy);
		virtual ~AForm();

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		virtual void		execute(Bureaucrat const &executor) const = 0;

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &out, AForm const &form);

#endif
