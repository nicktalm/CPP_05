/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:29:49 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 13:16:30 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
	this->_target = src._target;
	this->setSigned(src.isSigned());
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & copy)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	this->_target = copy._target;
	this->setSigned(copy.isSigned());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
	{
		std::cout << "Bureaucrat, " + executor.getName() + " can't execute this form" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (!this->isSigned())
	{
		std::cout << "This RobotomyRequestForm is not sigend, so it can be executed" << std::endl;
		return;
	}
	if (rand() % 2)
		std::cout << this->_target + " has been robotomized successfully" << std::endl;
	else
		std::cout << "the " + this->_target + " robotomization failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &i)
{
	os << i.getName() + " form with grade to sign " << i.getGradeToSign() << " and grade to execute " << i.getGradeToExecute() << " and target " << i.getTarget();
	return os;
}