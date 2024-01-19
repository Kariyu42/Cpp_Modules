/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:48:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 14:39:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <cctype>
# include <string>
# include <sstream>
# include <cstdlib>
# include "Contact.class.hpp"

# ifndef MAX_CONTACT
#  define MAX_CONTACT 8
# endif

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
