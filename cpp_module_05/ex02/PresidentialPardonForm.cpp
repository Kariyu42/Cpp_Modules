/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:39:41 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:33:36 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getSigned() == false) {
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout	<< _target << ":" << BLUE << " has been pardoned by Zafod Beeblebrox" \
				<< RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), \
													_target("Unknown") {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), \
																			_target(target) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), \
																					_target(copy._target) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	return ;
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
	if (this == &copy) {
		return *this;
	}
	AForm::operator=(copy);
	return *this;
}
