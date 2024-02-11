/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:44:51 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:31:54 by kquetat-         ###   ########.fr       */
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
};

#endif
