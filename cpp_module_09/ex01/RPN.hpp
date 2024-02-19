/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:13:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/19 16:56:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <sstream>

//* Color codes *//
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define UNDERLINE	"\033[4m"
# define RESET		"\033[0m"

class RPN
{
	public:
		RPN();
		RPN(RPN const &rpn);
		~RPN();
		RPN	&operator=(RPN const &rpn);

		long	execRPN(std::string str);

		class InvalidNumber : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormatError : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class OperatorError : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ZeroDivision : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::stack<int>	_stack;
		int	_strToInt(std::string str);
		bool	_checkNbr(int n);
};

#endif
