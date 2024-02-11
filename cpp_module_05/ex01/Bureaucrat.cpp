/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:30 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:40:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string const	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade( void ) {
	if (this->_grade == HIGHEST_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade( void ) {
	if (this->_grade == LOWEST_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
	return ;
}

void	Bureaucrat::checkGrade(int grade) {
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout	<< YELLOW << this->_name << RESET << " couldn't sign " \
					<< YELLOW << form.getName() << " because " \
					<< RED << e.what() << std::endl;
	}
	return ;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high !";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low !";
}

Bureaucrat::Bureaucrat() : _name("X"), _grade(LOWEST_GRADE) {
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	this->checkGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	*this = copy;
	return ;
}

Bureaucrat::~Bureaucrat() {
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &copy) {
	this->_grade = copy._grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &inst) {
	os << inst.getName() << ", bureaucrat grade " << inst.getGrade();
	return os;
}
