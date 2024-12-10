/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:22 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/10 12:35:05 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <string>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const& other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// Funktionsdeklarationen
AForm* createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

typedef AForm* (*FormCreator)(std::string);

AForm *Intern::makeForm(std::string form_name, std::string target) {
	static const std::map<std::string, FormCreator> formCreators = {
		{"presidential pardon", createPresidential},
		{"robotomy request", createRobotomy},
		{"shrubbery creation", createShrubbery}
	};
	std::map<std::string, FormCreator>::const_iterator it = formCreators.find(form_name);
	if (it != formCreators.end()) {
		std::cout << "Intern creates " << form_name << " form" << std::endl;
		return it->second(target);
	}
	std::cout << "Intern can't find a form called: " << form_name << std::endl;
	return nullptr;
}

std::ostream &operator<<(std::ostream &os, const Intern &intern)
{
	(void)intern;
	os << "Intern output operator called" << std::endl;
	return os;
}