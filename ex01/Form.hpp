/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:53 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/27 15:21:49 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		bool _signed;
		int _gradeToSign;
		int _gradeToExecute;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &copy);
		Form & operator=(const Form &copy);
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream &out, const Form &form);