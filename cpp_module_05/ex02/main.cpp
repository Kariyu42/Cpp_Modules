/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/10 13:26:59 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

void	testMain(Bureaucrat &p1, AForm &form) {
	std::cout	<< UNDERLINE << CYAN << "Bureaucrat: " << RED << p1.getName() << CYAN << \
				" with grade " << RED << p1.getGrade() << CYAN << \
				" tries to sign and execute form: " << RED << form.getName() \
				<< CYAN << " with grade " << RED << form.getGradeToSign() \
				<< CYAN << " and " << RED << form.getGradeToExecute() << RESET << std::endl;
	try {
		p1.signForm(form);
	}
	catch (std::exception &e) {
		std::cerr	<< RED << "In main: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr	<< RED << "In main: " \
					<< "Unknown exception" << RESET << std::endl;
	}
	try {
		p1.executeForm(form);
	}
	catch (std::exception &e) {
		std::cerr	<< RED << "In main: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr	<< RED << "In main: " \
					<< "Unknown exception" << RESET << std::endl;
	}
	return ;
}

int	main( void ) {
	Bureaucrat	jack("Jack", 1);
	Bureaucrat	jill("Jill", 150);
	Bureaucrat	john("John", 75);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robot("robot");
	PresidentialPardonForm	pardonForm("pardonForm");

	testMain(jack, shrub); //* This should work since Jack's grade is high enough
	testMain(jill, robot); //! This should fail since Jill's grade is too low
	testMain(john, pardonForm); //! This should fail since John's grade is too low
	testMain(jack, pardonForm); //* This should work since Jack's grade is high enough
	testMain(jack, robot); //* This should work since Jack's grade is high enough
	testMain(jack, pardonForm); //* This should work since Jack's grade is high enough
	return 0;
}
