/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:40:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

void	testMain(Bureaucrat &bureaucrat, Form &form) {
	std::cout	<< BLUE << "Bureaucrat: " << RESET << bureaucrat.getName() \
				<< " - Grade: " << bureaucrat.getGrade() << std::endl;
	std::cout	<< BLUE << "Form: " << RESET << form.getName() \
				<< " - Grade to sign: " << form.getGradeToSign() \
				<< " - Grade to execute: " << form.getGradeToExecute() \
				<< " - Signed: " << form.getSigned() << std::endl;
	bureaucrat.signForm(form);
	std::cout	<< BLUE << "Form: " << RESET << form.getName() \
				<< " - Signed: " << form.getSigned() << std::endl;
	std::cout	<< std::endl;
}

int	main( void ) {
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	staff("Staff", 75);
	Bureaucrat	secretary("Secretary", 150);

	Form		financialReport("Financial report", 1, 1);
	Form		contract("Contract", 75, 75);
	Form		equipmentOrder("Equipment order", 150, 150);
	Form		someForm("Some form", 90, 90);

	std::cout	<< MAGENTA << " === Test: Boss and Financial Report === " \
				<< RESET << std::endl;
	testMain(boss, financialReport); // Should sign the form
	std::cout	<< MAGENTA << " === Test: Staff and Financial Report === " \
				<< RESET << std::endl;
	testMain(staff, financialReport); // Should throw GradeTooLowException
	std::cout	<< MAGENTA << " === Test: Secretary and Contract === " \
				<< RESET << std::endl;
	testMain(secretary, contract); // Should throw GradeTooLowException
	std::cout	<< MAGENTA << " === Test: Secretary and Equipment Order === " \
				<< RESET << std::endl;
	testMain(secretary, equipmentOrder); // Should sign the form
	std::cout	<< MAGENTA << " === Test: Staff and Contract === " \
				<< RESET << std::endl;
	testMain(staff, contract); // Should print already signed
	std::cout	<< MAGENTA << " === Test: Staff and Some Form === " \
				<< RESET << std::endl;
	testMain(staff, someForm); // Should sign the form
	return 0;
}
