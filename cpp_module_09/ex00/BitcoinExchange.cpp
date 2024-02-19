/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:25:25 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/19 11:56:57 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) : _data() {
	// std::cout << UNDERLINE YELLOW "BitcoinExchange created" << RESET << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _data(copy._data) {
	// std::cout << UNDERLINE CYAN "BitcoinExchange copied" << RESET << std::endl;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this != &copy)
		this->_data = copy._data;
	// std::cout << UNDERLINE LIGHT_GREEN "BitcoinExchange assigned" << RESET << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange( void ) {
	// std::cout << UNDERLINE MAGENTA "BitcoinExchange destroyed" << RESET << std::endl;
	return ;
}

double	BitcoinExchange::_strToDouble(std::string const &str) {
	double	result;
	std::istringstream	iss(str);
	iss >> result;
	if (iss.fail() || !iss.eof())
		throw DataReadException();
	return result;
}

int	BitcoinExchange::_strToInt(std::string const &str) {
	int	result;
	std::istringstream	iss(str);
	iss >> result;
	return result;
}

const char	*BitcoinExchange::DataReadException::what() const throw() {
	return "DataReadException: Error reading data";
}

const char	*BitcoinExchange::CloseFileException::what() const throw() {
	return "CloseFileException: Error closing file";
}

void	BitcoinExchange::initData(std::string const &filename) {
	//* 1st step: open file *//
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
		throw DataReadException();

	//* 2nd step: read file *//
	std::string	line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw DataReadException();

	//* 3rd step: parse file *//
	while (std::getline(file, line)) {
		size_t	sep = line.find(','); //* find separator *//
		if (sep == std::string::npos) //! if no separator found //
			throw DataReadException();
		std::string	date = line.substr(0, sep); //* get date *//
		std::string	exchange_rate = line.substr(sep + 1); //* get exchange rate *//
		if (date.empty() || exchange_rate.empty()) //* check if date and exchange rate are not empty *//
			throw DataReadException();
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') //* check date format *//
			throw DataReadException();
		for (size_t i = 0; i < exchange_rate.length(); i++) { //* check exchange rate format *//
			if (!std::isdigit(exchange_rate[i]) && exchange_rate[i] != '.')
				throw DataReadException();
		}
		_data.insert(std::pair<std::string, double>(date, _strToDouble(exchange_rate))); //* insert date and exchange rate in map *//
	}
	file.close();
	if (file.is_open())
		throw CloseFileException();

	return ;
}

bool	BitcoinExchange::validDate(std::string const &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int	year = _strToInt(date.substr(0, 4));
	int	month = _strToInt(date.substr(5, 2));
	int	day = _strToInt(date.substr(8, 2));
	int	daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 2000 || year > 2024 || month < 1 \
			|| month > 12 || day < 1 || day > 31)
		return false;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonths[1] = 29;
	if (day > daysInMonths[month - 1])
		return false;

	return true;
}

double	BitcoinExchange::_getRateResult(std::string const &date) {
	std::map<std::string, double>::iterator	it = _data.lower_bound(date);

	if (it == _data.begin() && date < it->first) {
		return it->second;
	}
	if (it != _data.begin() && (it == _data.end() || date < it->first))
		it--;
	return it->second;
}

void	BitcoinExchange::showExchange(std::string const &filename) {

	//* 1st step: open file *//
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
		throw DataReadException();

	//* 2nd step: read file *//
	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
		throw DataReadException();
	
	while (std::getline(file, line)) {
		size_t	sep = line.find('|');
		if (sep == std::string::npos) {
			std::cout	<< RED UNDERLINE "Error:" << RESET \
						<< RED " bad input => " << line << RESET << std::endl;
			continue ;
		}
		std::string	date = line.substr(0, sep - 1);
		if (!validDate(date)) {
			std::cout	<< RED UNDERLINE "Error:" << RESET \
						<< RED " bad input => " << date << RESET << std::endl;
			continue ;
		}
		std::string	value = line.substr(sep + 1);
		try {
			double val = _strToDouble(value);
			(void)val;
		} catch (std::exception &e) {
			std::cout	<< RED UNDERLINE "Error:" << RESET \
						<< RED " bad input => " << line << RESET << std::endl;
			continue ;
		}
		double	val = _strToDouble(value);
		if (val < 0) {
			std::cout	<< RED UNDERLINE "Error:" << RESET \
						<< MAGENTA " not a positive number." \
						<< RESET << std::endl;
			continue ;
		}
		if (val > 1000) {
			std::cout	<< RED UNDERLINE "Error:" << RESET \
						<< MAGENTA " too large a number." \
						<< RESET << std::endl;
			continue ;
		}
		double	result = _getRateResult(date);
		std::cout	<< CYAN << date << " =>" << value << " = " \
					<< RESET << GREEN << result * val << RESET << std::endl;
	}
	file.close();
	if (file.is_open())
		throw CloseFileException();
	return ;
}
