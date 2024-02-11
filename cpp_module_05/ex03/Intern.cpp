/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:14:44 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:32:27 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm		*Intern::createPresidentialPardonForm(std::string const target) {
	AForm	*form = new (std::nothrow) PresidentialPardonForm(target);
	if (!form) {
		std::cerr << RED << "Error: new failed" << std::endl;
		return NULL;
	}
	std::cout	<< GREEN << "Intern creates " << form->getName() \
				<< " for " << MAGENTA << target << RESET << std::endl;
	return form;
}

AForm		*Intern::createShrubberyCreationForm(std::string const target) {
	AForm	*form = new (std::nothrow) ShrubberyCreationForm(target);
	if (!form) {
		std::cerr << RED << "Error: new failed" << std::endl;
		return NULL;
	}
	std::cout	<< GREEN << "Intern creates " << form->getName() \
				<< " for " << MAGENTA << target << RESET << std::endl;
	return form;
}

AForm		*Intern::createRobotomyRequestForm(std::string const target) {
	AForm	*form = new (std::nothrow) RobotomyRequestForm(target);
	if (!form) {
		std::cerr << RED << "Error: new failed" << std::endl;
		return NULL;
	}
	std::cout	<< GREEN << "Intern creates " << form->getName() \
				<< " for " << MAGENTA << target << RESET << std::endl;
	return form;
}

AForm		*Intern::makeForm(std::string const form, std::string const target) {
	typedef AForm	*(Intern::*FormPtr)(std::string const target);
	FormPtr		formPtr[NBR_OF_FORMS] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	std::string		formNames[NBR_OF_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < NBR_OF_FORMS; i++) {
		if (form == formNames[i]) {
			return (this->*formPtr[i])(target);
		}
	}

	std::cerr	<< RED << "Error: form not found" \
				<< RESET << std::endl;
	return NULL;
}

Intern::Intern() {return ;}

Intern::Intern(Intern const &copy) {
	*this = copy;
	return ;
}

Intern		&Intern::operator=(Intern const &copy) {
	if (this == &copy) {
		return *this;
	}
	*this = copy;
	return *this;
}

Intern::~Intern() {return ;}
