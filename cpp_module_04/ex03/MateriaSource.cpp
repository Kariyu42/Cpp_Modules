/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:29:36 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 13:29:06 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			break ;
		}
	}
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (this->_materias[i] && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return 0;
}

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		this->_materias[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
	*this = copy;
	return ;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		this->_materias[i] = other._materias[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (this->_materias[i]) {
			delete this->_materias[i];
		}
		this->_materias[i] = NULL;
	}
	return ;
}
