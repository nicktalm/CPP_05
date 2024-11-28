/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:42 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/27 15:27:44 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(100), _gradeToExecute(100)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.isSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(const Form &copy)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	_signed = copy.isSigned();
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high for the form";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low for the form";
}

std::ostream & operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.isSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return out;
}
