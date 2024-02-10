/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:37:50 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/10 16:38:15 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::string const	AForm::getName() const {
	return this->_name;
}

bool	AForm::getSigned() const {
	return this->_signed;
}

int	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int	AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high !";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low !";
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed !";
}



void	AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw AForm::GradeTooLowException();
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

AForm::AForm() : _name("Unknown"), _signed(false), \
				_gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
	return ;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : \
			_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	return ;
}

AForm::AForm(AForm const &copy) : _name(copy.getName()), _signed(copy.getSigned()), \
								_gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()) {
	return ;
}

AForm	&AForm::operator=(AForm const &copy) {
	if (this == &copy)
		return *this;
	return *this;
}

AForm::~AForm() {
	return ;
}

std::ostream	&operator<<(std::ostream &out, AForm const &form) {
	out	<< YELLOW << "Form " << MAGENTA << form.getName() << std::endl \
		<< YELLOW << " status: " << MAGENTA << form.getSigned() << std::endl \
		<< YELLOW << " grade to sign: " << MAGENTA << form.getGradeToSign() << std::endl \
		<< YELLOW << " grade to execute: " << MAGENTA << form.getGradeToExecute() \
		<< RESET << std::endl;
	return out;
}
