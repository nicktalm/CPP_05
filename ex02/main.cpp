/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:59:23 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/29 17:17:38 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat Bureaucrat1("Nick", 1);
		// Bureaucrat Bureaucrat2("Luca", 120);
		// Bureaucrat Bureaucrat3(Bureaucrat1);

		// AForm Form1("important", 20, 10);
		// AForm Form2("not important", 140, 130);

		ShrubberyCreationForm Form3("42");
		RobotomyRequestForm Form4("Heilbronn");
		PresidentialPardonForm Form5("CEO");

		Bureaucrat1.signForm(Form3);
		Form3.execute(Bureaucrat1);
		
		Bureaucrat1.signForm(Form4);
		Form4.execute(Bureaucrat1);
		
		Form5.execute(Bureaucrat1);

		// std::cout << Bureaucrat1 << std::endl;
		// std::cout << Bureaucrat2 << std::endl;
		// std::cout << Bureaucrat3 << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
