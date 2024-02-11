/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:40:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void	testMain(int strNbr, char const *name, int grade) {
	std::string	str = "";
	switch (strNbr)
	{
		case 1:
			str = " ===== Low Grade test ! ===== ";
			break;
		case 2:
			str = " ===== High grade test ! ===== ";
			break;
		case 3:
			str = " ===== Normal test ! ===== ";
			break;
		case 4:
			str = " ===== Invalid grade ! ===== ";
			break;
		default:
			str = " ===== Test not specified ! ===== ";
			break;
	}
	std::cout << BLUE << str << RESET << std::endl;
	std::cout	<< YELLOW << "testing with " << name \
				<< " and grade " << grade \
				<< RESET << std::endl;
	try {
		Bureaucrat	bureaucrat(name, grade);
		std::cout << GREEN << bureaucrat << RESET << std::endl;
		std::cout << MAGENTA << " --- testing incrementation... --- " << RESET << std::endl;
		bureaucrat.incrementGrade();
		std::cout	<< GREEN << "Bureaucrat " << name \
					<< " incremented grade to " << bureaucrat.getGrade() \
					<< RESET << std::endl;
		std::cout << MAGENTA << " --- testing decrementation... --- " << RESET << std::endl;
		bureaucrat.decrementGrade();
		std::cout	<< GREEN << "Bureaucrat " << name \
					<< " decremented grade to " << bureaucrat.getGrade() \
					<< RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return ;
}

int	main( void ) {
	testMain(3, "Dan", 45); // Normal grade
	testMain(1, "Jack", 150); // Lowest grade
	testMain(2, "Sarah", 1); // Highest grade
	testMain(4, "Ben", -50); // Invalid negative grade
	testMain(4, "Billie", 151); // Invalid positive grade
	testMain(4, "Bob", 0); // Invalid zero grade
	return 0;
}
