/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/08 15:48:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void	testMain(int strNbr, char const *name, int grade) {
	char	*str = NULL;
	switch (strNbr)
	{
		case 1:
			str = " ===== Grade too low test ! ===== ";
			break;
		case 2:
			str = " ===== Grade too high test ! ===== ";
			break;
		case 3:
			str = " ===== Normal test ! ===== ";
			break;
		default:
			break;
	}
	
	return ;
}

int	main( void ) {
	{
		std::cout	<< RED << " ===== Grade too low test ! ===== " \
					<< RESET << std::endl;
		try {
			Bureaucrat	test("Jack", -1);
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout	<< YELLOW << "Caught exception: " \
						<< RED << e.what() \
						<< RESET << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout	<< YELLOW << "Caught exception: " \
						<< RED << e.what() \
						<< RESET << std::endl;
		}
		std::cout	<< test.getName()
	}
	{
		
	}
	return 0;
}
