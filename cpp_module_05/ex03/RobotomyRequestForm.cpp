/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:13:52 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:32:57 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (getSigned() == false) {
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << "* Drilling noises *" << std::endl;
	srand((unsigned) time(NULL));
	int		rand = std::rand() % 2;
	if (rand == 0) {
		std::cout	<< GREEN << _target << " has been robotomized successfully" \
					<< RESET << std::endl;
	}
	else {
		std::cout	<< RED << _target << " robotomization failed" \
					<< RESET << std::endl;
	}
	return ;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), \
												_target("Unknown") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), \
																	_target(target) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), \
																			_target(copy._target) {
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	return ;
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	if (this == &copy) {
		return *this;
	}
	AForm::operator=(copy);
	return *this;
}
