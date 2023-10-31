/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:10:29 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/31 15:39:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	upper_case_format(int ac, char **av)
{
	for (int i = 0; i < ac; i++) {
		
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		upper_case_format(ac, av);
}