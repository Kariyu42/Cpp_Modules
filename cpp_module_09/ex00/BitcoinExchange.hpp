/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:49 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/18 18:05:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <stdio.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define LIGHT_GREEN "\033[1;92m"
# define UNDERLINE "\033[4m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

class BitcoinExchange
{
	public:
		//* Constructors and destructor; Canonical Form *//
		BitcoinExchange( void );
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange	&operator=(BitcoinExchange const &copy);
		~BitcoinExchange( void );

		//* own exceptions
		class DataReadException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class CloseFileException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		//* public methods
		void	initData(std::string const &filename);
		void	showExchange(std::string const &filename);

		bool	validDate(std::string const &date);

	private:
		std::map<std::string, double>	_data;
		double	_strToDouble(std::string const &str);
		int		_strToInt(std::string const &str);
		double	_getRateResult(std::string const &date);
};

#endif
