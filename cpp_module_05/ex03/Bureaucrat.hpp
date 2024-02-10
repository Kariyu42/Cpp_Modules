/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:35 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/10 13:24:49 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

// Colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat		&operator=(Bureaucrat const &copy);
		~Bureaucrat();

		std::string const	getName() const;
		int					getGrade() const;

		void				incrementGrade( void );
		void				decrementGrade( void );

		void				checkGrade(int grade);
		void				signForm(AForm &form);

		void				executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &inst);

#endif
