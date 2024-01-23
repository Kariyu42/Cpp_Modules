/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:05:31 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/23 23:31:24 by kquetat-         ###   ########.fr       */
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

static bool copyAndReplace(std::ifstream &file, const std::string &str1, const std::string &str2, \
							std::string &fileName) {
	std::string	tmp;
	std::string	rl = ".replace";
	std::ofstream outputFile(fileName.append(rl).c_str());

	if (!outputFile.is_open()) {
		std::cerr << "Error: can't create file." << std::endl;
		return false;
	}
	while (std::getline(file, tmp)) {
		replaceOccurrences(tmp, str1, str2);
		outputFile << tmp << std::endl;
		if (!outputFile) {
			std::cerr << "Error: can't write to file." << std::endl;
			return false;
		}
	}
	outputFile.close();
	if (outputFile.is_open()) {
		std::cerr << "Error: file not closed." << std::endl;
		return false;
	}
	return true;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Provide 3 arguments: <filename> <string> <other string>" << std::endl;
		return 1;
	}

	std::string fileName = av[1];
	if (fileName.empty()) {
		std::cerr << "Error: filename arg can't be empty." << std::endl;
		return 1;
	}
	std::string str1 = av[2];
	if (str1.empty()) {
		std::cerr << "Error: string arg can't be empty." << std::endl;
		return 1;
	}
	std::string str2 = av[3];

	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Error: can't open file." << std::endl;
		return 1;
	}

	if (!copyAndReplace(file, str1, str2, fileName)) {
		file.close();
		if (file.is_open()) {
			std::cerr << "Error: file not closed." << std::endl;
			return 1;
		}
		return 1;
	}

	file.close();
	if (file.is_open()) {
		std::cerr << "Error: file not closed." << std::endl;
		return 1;
	}
	return 0;
}
