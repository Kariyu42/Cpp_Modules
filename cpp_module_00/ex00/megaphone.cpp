/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:10:29 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 15:47:23 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	upper_case_format(int ac, char **av)
{
	std::string	str;

	for (int i = 1; i < ac; i++) {
		str = av[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(str[j]);
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		upper_case_format(ac, av);
	std::cout << std::endl;
	return (0);
}
