/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:48:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/17 14:54:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "Contact.class.hpp"

# define MAX_CONTACT 8

class PhoneBook
{
	public:
		void	addContact();
		void	searchContact() const;
		void	printContact() const;
	private:
		Contact	_contacts[MAX_CONTACT];
};

#endif
