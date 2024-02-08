/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:30 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/08 15:06:28 by kquetat-         ###   ########.fr       */
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
		return ;
	}
	this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade( void ) {
	if (this->_grade == LOWEST_GRADE) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade++;
	return ;
}

void	Bureaucrat::checkGrade(int grade) {
	if (grade < LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

const char	*Bureaucrat::GradeTooHighException::what() const {
	return "Grade is too high !";
}

const char	*Bureaucrat::GradeTooLowException::what() const {
	return "Grade is too low !";
}

Bureaucrat::Bureaucrat() : _name("X"), _grade(LOWEST_GRADE) {
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &other) {
	os << other;
	return ;
}
