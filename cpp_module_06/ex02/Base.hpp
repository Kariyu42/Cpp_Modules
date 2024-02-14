/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:08:27 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/14 18:29:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

enum e_type
{
	A_TYPE,
	B_TYPE,
	C_TYPE
};

class Base
{
	public:
		virtual ~Base();
};

#endif
