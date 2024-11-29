/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:53 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/29 11:41:16 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string _name;
		bool _signed;
		int _gradeToSign;
		int _gradeToExecute;
	protected:
		std::string _target;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		~AForm();
		AForm(const AForm &copy);
		AForm & operator=(const AForm &copy);
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName() const;
		bool isSigned() const;
		void setSigned(bool sign);
		int getGradeToSign() const;
		int getGradeToExecute() const;
		virtual void execute(Bureaucrat const &executor) const;
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

std::ostream & operator<<(std::ostream &out, const AForm &form);