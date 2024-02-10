/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:26:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/10 17:00:35 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main( void ) {
	{
		std::cout	<< UNDERLINE << CYAN << "Main test:" << RESET << std::endl;
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	{
		std::cout	<< UNDERLINE << CYAN << "Own tests:" << RESET << std::endl;
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("unknown form", "Bender");
	}
	return 0;
}
