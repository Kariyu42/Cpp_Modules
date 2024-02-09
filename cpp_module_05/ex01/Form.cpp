/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:37:50 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/09 16:25:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string const	Form::getName() const {
	return this->_name;
}

bool	Form::getSigned() const {
	return this->_signed;
}

int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int	Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too high !";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too low !";
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw Form::GradeTooLowException();
	}
	if (this->_signed) {
		std::cout	<< RED << "Form " << this->_name \
					<< " is already signed" << RESET << std::endl;
		return ;
	}
	this->_signed = true;
	std::cout	<< GREEN << bureaucrat.getName() \
				<< " signed " << this->_name \
				<< RESET << std::endl;
	return ;
}

Form::Form() : _name("Unknown"), _signed(false), \
				_gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
	return ;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : \
			_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	return ;
}

Form::Form(Form const &copy) : _name(copy.getName()), _signed(copy.getSigned()), \
								_gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()) {
	return ;
}

Form	&Form::operator=(Form const &copy) {
	if (this == &copy)
		return *this;
	return *this;
}

Form::~Form() {
	return ;
}

std::ostream	&operator<<(std::ostream &out, Form const &form) {
	out	<< YELLOW << "Form " << MAGENTA << form.getName() << std::endl \
		<< YELLOW << " status: " << MAGENTA << form.getSigned() << std::endl \
		<< YELLOW << " grade to sign: " << MAGENTA << form.getGradeToSign() << std::endl \
		<< YELLOW << " grade to execute: " << MAGENTA << form.getGradeToExecute() \
		<< RESET << std::endl;
	return out;
}
