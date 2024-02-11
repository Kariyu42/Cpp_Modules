/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:12:17 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 17:53:28 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

Serializer::Serializer() {return ;}

Serializer::Serializer(Serializer const &other) {
	*this = other;
	return ;
}

Serializer	&Serializer::operator=(Serializer const &other) {
	(void)other;
	return (*this);
}

Serializer::~Serializer() {return ;}
