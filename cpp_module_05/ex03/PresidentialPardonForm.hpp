/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:39:01 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:32:54 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm		&operator=(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();

		void		execute(Bureaucrat const &executor) const;

	private:
		std::string const	_target;
};

#endif
