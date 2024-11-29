/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:48:19 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/29 17:19:41 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
	this->_target = src._target;
	this->setSigned(src.isSigned());
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & copy)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	this->_target = copy._target;
	this->setSigned(copy.isSigned());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
	{
		std::cout << "Bureaucrat, " + executor.getName() + " can't execute this form" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (!this->isSigned())
	{
		std::cout << "This ShrubberyCreationForm is not signed, so it can not be executed" << std::endl;
		return;
	}
	std::ofstream outFile(this->_target + "_shrubbery");
	if (outFile.fail() || outFile.is_open() == false)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	outFile << "    oxoxoo    ooxoo\n";
	outFile << "  ooxoxo oo  oxoxooo\n";
	outFile << " oooo xxoxoo ooo ooox\n";
	outFile << " oxo o oxoxo  xoxxoxo\n";
	outFile << "  oxo xooxoooo o ooo\n";
	outFile << "    ooooo|  /o/o\n";
	outFile << "         |    /\n";
	outFile << "         |   /\n";
	outFile << "         |  |\n";
	outFile << "         |  |\n";
	outFile << "         |  |\n";
	outFile << "         |  |\n";
	outFile << "  ______/___|____\n";

	outFile.close();
}