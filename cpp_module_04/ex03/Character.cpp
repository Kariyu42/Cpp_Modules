/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:55:31 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/06 14:34:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

std::string const	&Character::getName( void ) const {
	return this->_name;
}

/*
* Function updates how many materias are on the ground.
* It is called when a materia is unequipped.
* groundMateria is not a fixed size table, so it is necessary to
* reallocate it with the new size and delete the old one.
*/
AMateria	**Character::updateGroundMateria( int idx ) {
	AMateria	**newGroundMateria = NULL;
	size_t		i = 0;

	if (!this->_groundMateria) {
		newGroundMateria = new (std::nothrow) AMateria*[1];
		if (!newGroundMateria) {
			std::cerr	<< RED \
						<< "Error: Memory allocation failed." \
						<< RESET << std::endl;
			exit(1);
		}
		newGroundMateria[0] = this->_materias[idx];
		this->_countGroundMateria = 1;
		return newGroundMateria;
	}

	newGroundMateria = new (std::nothrow) AMateria*[this->_countGroundMateria + 1];
	if (!newGroundMateria) {
		std::cerr	<< RED \
					<< "Error: Memory allocation failed." \
					<< RESET << std::endl;
		exit(1);
	}

	for (i = 0; i < this->_countGroundMateria; i++) {
		newGroundMateria[i] = this->_groundMateria[i];
	}
	newGroundMateria[i] = this->_materias[idx];
	this->_countGroundMateria++;

	delete [] this->_groundMateria;
	return newGroundMateria;
}

void	Character::showGroundMateria( void ) {
	std::cout	<< YELLOW \
				<< " === Ground materias === " \
				<< RESET << std::endl;
	for (size_t i = 0; i < this->_countGroundMateria; i++) {
		std::cout	<< CYAN \
					<< "Materia " << i << ": " \
					<< this->_groundMateria[i]->getType() \
					<< RESET << std::endl;
	}
	std::cout << YELLOW << "==========================" << std::endl;
	return ;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_MATERIAS || !this->_materias[idx]) {
		std::cout	<< RED << "Error: Can't unequip materia at this index." \
					<< RESET << std::endl;
		return ;
	}
	this->_groundMateria = this->updateGroundMateria(idx);
	std::cout	<< BLUE << "Materia [" << RED << idx << BLUE << "] " \
				<< RED << this->_materias[idx]->getType() << BLUE \
				<< " has been unequipped." << RESET << std::endl;
	this->_materias[idx] = NULL;
	showGroundMateria();
	return ;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= MAX_MATERIAS || !this->_materias[idx]) {
		std::cout	<< RED << "Error: Can't use materia at this index." \
					<< RESET << std::endl;
		return ;
	}
	this->_materias[idx]->use(target);
	return ;
}

void	Character::equip(AMateria *m) {
	size_t	i;
	for (i = 0; i < MAX_MATERIAS; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			std::cout	<< BLUE << "Materia " << RED << m->getType() \
						<< BLUE << " has been equipped." << RESET << std::endl;
			break ;
		}
	}
	if (i == MAX_MATERIAS) {
		std::cout	<< RED << "Error: Can't equip more than 4 materias." \
					<< RESET << std::endl;
		delete m;
	}
	return ;
}

Character::Character() : _name("no name"), _groundMateria(NULL), _countGroundMateria(0) {
	for (size_t i = 0; i < MAX_MATERIAS; i++) {
		this->_materias[i] = NULL;
	}
	return ;
}

Character::Character(std::string const &name) : _name(name), _groundMateria(NULL), _countGroundMateria(0) {
	for (size_t i = 0; i < MAX_MATERIAS; i++) {
		this->_materias[i] = NULL;
	}
	return ;
}

Character::Character(Character const &copy) {
	this->_name = copy._name;
	for (size_t i = 0; i < MAX_MATERIAS; i++) {
		if (this->_materias[i]) {
			delete this->_materias[i];
		}
		if (copy._materias[i]) {
			this->_materias[i] = copy._materias[i]->clone();
		}
		else {
			this->_materias[i] = NULL;
		}
	}
	if (this->_groundMateria) {
		for (size_t i = 0; i < _countGroundMateria; i++) {
			if (this->_groundMateria[i]) {
				delete this->_groundMateria[i];
				this->_groundMateria[i] = NULL;
			}
		}
		delete [] this->_groundMateria;
	}
	this->_groundMateria = copy._groundMateria;
	this->_countGroundMateria = copy._countGroundMateria;
	return ;
}

Character	&Character::operator=(Character const &other) {
	this->_name = other._name;
	for (size_t i = 0; i < MAX_MATERIAS; i++) {
		if (this->_materias[i]) {
			delete this->_materias[i];
		}
		if (other._materias[i]) {
			this->_materias[i] = other._materias[i]->clone();
		}
		else {
			this->_materias[i] = NULL;
		}
	}
	if (this->_groundMateria) {
		for (size_t i = 0; i < _countGroundMateria; i++) {
			if (this->_groundMateria[i]) {
				delete this->_groundMateria[i];
				this->_groundMateria[i] = NULL;
			}
		}
		delete [] this->_groundMateria;
	}
	this->_groundMateria = other._groundMateria;
	this->_countGroundMateria = other._countGroundMateria;
	return (*this);
}

Character::~Character() {
	// std::cout << RED << "Character " << this->_name << " is dead." << RESET << std::endl;
	for (size_t i = 0; i < MAX_MATERIAS; i++) {
		if (this->_materias[i]) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	for (size_t i = 0; i < _countGroundMateria; i++) {
		if (this->_groundMateria[i]) {
			delete this->_groundMateria[i];
			this->_groundMateria[i] = NULL;
		}
	}
	if (this->_groundMateria) {
		delete [] this->_groundMateria;
		this->_groundMateria = NULL;
	}
	return ;
}
