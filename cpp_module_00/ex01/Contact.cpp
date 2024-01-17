/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:56:20 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/17 09:41:44 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

std::string	Contact::getFirstName() const {
	return _firstname;
}

std::string	Contact::getLastName() const {
	return _lastname;
}

std::string	Contact::getNickName() const {
	return _nickname;
}

std::string	Contact::getPhoneNumber() const {
	return _phonenumber;
}

std::string	Contact::getSecret() const {
	return _darkestsecret;
}

void	Contact::setFirstName(const std::string& str) {
	_firstname = str;
}

void	Contact::setLastName(const std::string& str) {
	_lastname = str;
}

void	Contact::setNickName(const std::string& str) {
	_nickname = str;
}

void	Contact::setPhoneNumber(const std::string& str) {
	_phonenumber = str;
}

void	Contact::setSecret(const std::string& str) {
	_darkestsecret = str;
}
