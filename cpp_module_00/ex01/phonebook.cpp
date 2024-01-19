/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:26 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 14:54:39 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"

static bool	isAllAlpha(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isalpha(str[i])) {
			return (false);
		}
	}
	return (true);
}

static bool	isAllDigit(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

static bool	alwaysTrue(const std::string& str) {
	(void)str;
	return (true);
}

static void	inputInfo(const std::string& str, Contact& contact, bool (*isTrue)(const std::string&)) {
	std::string	info;

	while (true) {
		std::cout << "Provide your " << str << ": ";
		std::getline(std::cin, info);
		if (std::cin.eof()) {
			std::cout << "EOF reached. Exiting..." << std::endl;
			exit(1);
		}
		if (!info.empty() && isTrue(info))
		{
			if (str == "firstname")
				contact.setFirstName(info);
			else if (str == "lastname")
				contact.setLastName(info);
			else if (str == "nickname")
				contact.setNickName(info);
			else if (str == "phonenumber")
				contact.setPhoneNumber(info);
			else if (str == "darkest secret")
				contact.setSecret(info);
			break ;
		}
		std::cout << "Invalid input. Try again." << std::endl;
		std::cin.clear();
	}
}

void	PhoneBook::addContact() {
	static int	i = 0;
	Contact		newContact;

	std::cout << "Adding a new Contact..." << std::endl;
	inputInfo("firstname", newContact, isAllAlpha);
	inputInfo("lastname", newContact, isAllAlpha);
	inputInfo("nickname", newContact, alwaysTrue);
	inputInfo("phonenumber", newContact, isAllDigit);
	inputInfo("darkest secret", newContact, alwaysTrue);
	_contacts[i] = newContact;
	i++;
	if (i == MAX_CONTACT)
		i = 0;
}

static std::string	truncateStr(const std::string& str) {
	size_t	len = 10;

	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	return (str);
}

void	PhoneBook::printContact() const {
	std::cout << std::setw(10) << "index" << "|" \
				<< std::setw(10) << "first name" << "|" \
				<< std::setw(10) << "last name" << "|" \
				<< std::setw(10) << "nick name" << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++) {
		if (!_contacts[i].getFirstName().empty()) {
			std::cout << std::setw(10) << i << "|" \
				<< std::setw(10) << truncateStr(_contacts[i].getFirstName()) << "|" \
				<< std::setw(10) << truncateStr(_contacts[i].getLastName()) << "|" \
				<< std::setw(10) << truncateStr(_contacts[i].getNickName()) << std::endl;
		}
	}
}

static int	strToInt(std::string& str) {
	int	nbr;

	if (!isAllDigit(str))
		return (-1);
	std::istringstream(str) >> nbr;
	return (nbr);
}

void	PhoneBook::searchContact() const {
	int			index = 0;
	std::string	nbr;

	if (_contacts[index].getFirstName().empty()) {
		std::cout << "Please ADD contact before searching for one." << std::endl;
		return ;
	}
	std::cout << "Searching contact log..." << std::endl;
	printContact();
	while (true) {
		std::cout << "Provide an index: ";
		std::getline(std::cin, nbr);
		if (std::cin.eof()) {
			std::cout << "EOF reached. Exiting..." << std::endl;
			exit(1);
		}
		index = strToInt(nbr);
		if (index >= 0 && index < MAX_CONTACT && !_contacts[index].getFirstName().empty()) {
			std::cout << "Info from contact number [" << index << "]" << std::endl;
			std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
			std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
			std::cout << "NickName: " << _contacts[index].getNickName() << std::endl;
			std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << _contacts[index].getSecret() << std::endl;
			break ;
		}
		std::cout << "\nInvalid input. Try again." << std::endl;
		std::cin.clear();
	}
}
