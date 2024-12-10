/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:58:56 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/10 11:40:02 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << " Bureaucrat assignation operator called" << std::endl;
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.isSigned())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because the form is already signed" << std::endl;
		return ;
	}
	if (_grade > form.getGradeToSign())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
		return ;
	}
	form.beSigned(*this);
	std::cout << _name << " signs " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		std::cout << getName() + " want to execute " + form.getName() << std::endl;
		form.execute(*this);
		std::cout << form.getName() + " was successfully executed by " + getName() << std::endl;
	}
	catch(AForm::GradeTooLowException &executor)
	{
		std::cout << getName() + " failed to execute " + form.getName() + " -> " << executor.what() << std::endl;
	}
}