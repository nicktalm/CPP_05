/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:42 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/29 11:50:11 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(100), _gradeToExecute(100)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _signed(copy.isSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm & AForm::operator=(const AForm &copy)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	_signed = copy.isSigned();
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high for the form";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low for the form";
}

std::ostream & operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.isSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return out;
}

void AForm::setSigned(bool sign)
{
	_signed = sign;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!isSigned())
	{
		std::cout << "Unsigned Form can't be executed" << std::endl;
		return;
	}
	std::cout << "Nothing happpens, executed empty AForm" << std::endl;
}