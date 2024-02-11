/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:12:52 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:32:35 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

# define NBR_OF_FORMS 3

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		Intern		&operator=(Intern const &copy);
		~Intern();

		AForm		*makeForm(std::string const form, std::string const target);

	private:
		AForm		*createPresidentialPardonForm(std::string const target);
		AForm		*createShrubberyCreationForm(std::string const target);
		AForm		*createRobotomyRequestForm(std::string const target);
};

#endif
