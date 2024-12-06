/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:56:17 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 13:15:38 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 1)
{
	this->_target = "default";
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45)
{
	this->_target = target;
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
	this->_target = src._target;
	this->setSigned(src.isSigned());
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & copy)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	this->_target = copy._target;
	this->setSigned(copy.isSigned());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
	{
		std::cout << "Bureaucrat, " + executor.getName() + " can't execute this form" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (!this->isSigned())
	{
		std::cout << "This PresidentialPardonForm is not sigend, so it can be executed" << std::endl;
		return;
	}
	std::cout << this->_target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &i)
{
	os << i.getName() + " form with grade to sign " << i.getGradeToSign() << " and grade to execute " << i.getGradeToExecute() << " and target " << i.getTarget();
	return os;
}