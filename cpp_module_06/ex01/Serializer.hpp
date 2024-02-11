/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:12:08 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 18:00:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# define ORANGE		"\033[38;2;255;165;0m"
# define CYAN		"\033[38;2;0;255;255m"
# define RESET		"\033[0m"

struct Data {
	std::string		str;
	int				i;
	char			c;
};

class Serializer {
	
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &other);
		Serializer	&operator=(Serializer const &other);
		~Serializer();

};

#endif
