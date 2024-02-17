/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:22:59 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/17 19:06:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	subjectMain( void ) {

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	return ;
}

void	printContainer(MutantStack<int>::iterator it, MutantStack<int>::iterator ite) {
	std::cout	<< GREEN << "[ " << RESET;
	while (it != ite) {
		std::cout	<< CYAN << *it << " " << RESET;
		it++;
	}
	std::cout	<< GREEN << "]" << RESET << std::endl;

	return ;
}

void	constPutContainer(MutantStack<int>::const_iterator it, MutantStack<int>::const_iterator ite) {
	std::cout	<< GREEN << "[ " << RESET;
	while (it != ite) {
		std::cout	<< CYAN << *it << " " << RESET;
		it++;
	}
	std::cout	<< GREEN << "]" << RESET << std::endl;

	return ;
}

void	revPutContainer(MutantStack<int>::reverse_iterator it, MutantStack<int>::reverse_iterator ite) {
	std::cout	<< GREEN << "[ " << RESET;
	while (it != ite) {
		std::cout	<< CYAN << *it << " " << RESET;
		it++;
	}
	std::cout	<< GREEN << "]" << RESET << std::endl;

	return ;
}

void	constRevPutContainer(MutantStack<int>::const_reverse_iterator it, MutantStack<int>::const_reverse_iterator ite) {
	std::cout	<< GREEN << "[ " << RESET;
	while (it != ite) {
		std::cout	<< CYAN << *it << " " << RESET;
		it++;
	}
	std::cout	<< GREEN << "]" << RESET << std::endl;

	return ;
}

int main()
{
	std::cout	<< BLUE << " === Subject main ===" << RESET << std::endl;
	subjectMain();
	std::cout	<< BLUE << " === My main ===" << RESET << std::endl;
	MutantStack<int> myStack;
	myStack.push(42);
	myStack.push(21);
	myStack.push(84);

	std::cout << YELLOW << " === Testing basic iterator ===" << RESET << std::endl;
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();
	printContainer(it, ite);

	std::cout << YELLOW << " === Testing const_iterator ===" << RESET << std::endl;
	MutantStack<int> myStack2(myStack); //* test copy constructor
	//* testing const_iterator
	MutantStack<int>::const_iterator cit = myStack2.begin();
	MutantStack<int>::const_iterator cite = myStack2.end();
	constPutContainer(cit, cite);

	std::cout << YELLOW << " === Testing reverse_iterator ===" << RESET << std::endl;
	MutantStack<int> myStack3;
	myStack3 = myStack2; //* test operator=
	//* testing reverse_iterator
	MutantStack<int>::reverse_iterator rit = myStack3.rbegin();
	MutantStack<int>::reverse_iterator rite = myStack3.rend();
	revPutContainer(rit, rite);

	std::cout << YELLOW << " === Testing const_reverse_iterator ===" << RESET << std::endl;
	MutantStack<int> myStack4;
	myStack4.push(1);
	myStack4.push(2);
	myStack4.push(3);
	//* testing const_reverse_iterator
	MutantStack<int>::const_reverse_iterator crit = myStack4.rbegin();
	MutantStack<int>::const_reverse_iterator crite = myStack4.rend();
	constRevPutContainer(crit, crite);

	return 0;
}
