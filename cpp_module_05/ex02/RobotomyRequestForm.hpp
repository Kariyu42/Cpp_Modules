/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:14:01 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:33:44 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm		&operator=(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();

		void		execute(Bureaucrat const &executor) const;

	private:
		std::string const	_target;
};

#endif
