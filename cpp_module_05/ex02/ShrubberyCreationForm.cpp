/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:02:56 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:33:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::string		filename = _target + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file.is_open()) {
		throw std::runtime_error("File could not be opened");
	}
	//! check if form is signed
	if (getSigned() == false) {
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	file << "             _{\\ _{\\{\\/}/}/}__" << std::endl;
	file << "            {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file << "           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	file << "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	file << "       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file << "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file << "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file << "     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file << "    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file << "     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file << "      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file << "     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file << "      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file << "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	file << "           {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file << "            {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
	file << "             {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file << "             (_)  \\.-'.-/" << std::endl;
	file << "         __...--- |'-.-'| --...__" << std::endl;
	file << "  _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
	file << "-\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
	file << ".  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	file << "         ' ..     |'-_.-|" << std::endl;
	file << " .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	file << "             .'   |'- .-|   '." << std::endl;
	file << " ..-'   ' .  '.   `-._.-´   .'  '  - ." << std::endl;
	file << "  .-' '        '-._______.-'     '  ." << std::endl;
	file << "       .      ~," << std::endl;
	file << "   .       .   |\\   .    ' '-." << std::endl;
	file << "   ___________/  \\____________" << std::endl;
	file << "  /  Why is it, when you want \\" << std::endl;
	file << " |  something, it is so damn   |" << std::endl;
	file << " |    much work to get it?     |" << std::endl;
	file << "  \\___________________________/" << std::endl;
	file.close();
	std::cout	<< GREEN << "Shrubbery has been created in " \
				<< CYAN << filename << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), \
													_target("Unknown") {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), \
																		_target(target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), \
																				_target(copy._target) {
	return ;
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
	if (this == &copy) {
		return *this;
	}
	AForm::operator=(copy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	return ;
}
