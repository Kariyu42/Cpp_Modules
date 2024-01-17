/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:24:23 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/17 13:05:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

static bool	runPhoneBook(PhoneBook& book, std::string& str)
{
	std::cout << "Enter a command [ADD, SEARCH, EXIT] > ";
	if (!std::getline(std::cin, str))
	{
		std::cerr << "NULL entry, exiting..." << std::endl;
		return (false);
	}
	if (!str.compare("ADD"))
		book.addContact();
	else if (!str.compare("SEARCH"))
		book.searchContact();
	else if (!str.compare("EXIT"))
	{
		std::cout << "Closing program, GoodBye..." << std::endl;
		return (false);
	}
	return (true);
}

int	main(void)
{
	PhoneBook	book;
	std::string	str;

	std::cout << "\tWelcome to your PhoneBook!" << std::endl;
	while (runPhoneBook(book, str));
	return (0);
}
