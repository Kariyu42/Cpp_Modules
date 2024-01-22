/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:05:31 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/22 17:37:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void replaceOccurrences(std::string &line, const std::string &str1, const std::string &str2) {
	size_t pos = 0;

	while ((pos = line.find(str1, pos)) != std::string::npos) {
		line = line.substr(0, pos) + str2 + line.substr(pos + str1.length());
		pos += str2.length();
	}
}

static void copyAndReplace(std::ifstream &file, const std::string &str1, const std::string &str2, \
							std::string &fileName) {
	std::string	tmp;
	std::string	rl = ".replace";
	std::ofstream outputFile(fileName.append(rl));

	while (std::getline(file, tmp)) {
		replaceOccurrences(tmp, str1, str2);
		outputFile << tmp << std::endl;
	}
	outputFile.close();
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Provide 3 arguments: <filename> <string> <other string>" << std::endl;
		return 1;
	}

	std::string fileName = av[1];
	std::string str1 = av[2];
	std::string str2 = av[3];

	if (fileName.empty()) {
		std::cerr << "Error: filename arg can't be empty." << std::endl;
		return 1;
	}

	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cout	<< "Non-existent file: "
					<< "create a file first using the touch cmd and enter characters..." << std::endl;
		return 1;
	}

	copyAndReplace(file, str1, str2, fileName);
	file.close();
	return 0;
}
