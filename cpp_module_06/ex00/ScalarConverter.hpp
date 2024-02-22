/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:44:51 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/21 14:23:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cmath>
# include <sstream>
# include <iomanip>
# include <locale>

//* Macro
# define IS_PRINTABLE(c) (c >= 32 && c <= 126)

class ScalarConverter {

	public:
		static void	convert(std::string &literal);

		static void	convertToChar(std::string &literal);
		static void	convertToInt(std::string &literal);
		static void	convertToFloat(std::string &literal);
		static void	convertToDouble(std::string &literal);
	

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter	&operator=(ScalarConverter const &other);
		~ScalarConverter();

		static double	_strToDouble(std::string &literal);
		static int		_strToInt(std::string &literal);
		static float	_strToFloat(std::string &literal);
		static char		_strToChar(std::string &literal);
};

#endif
