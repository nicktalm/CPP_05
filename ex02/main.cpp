/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:59:23 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/10 15:19:33 by ntalmon          ###   ########.fr       */
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
		// Bureaucrat Bureaucrat3(Bureaucrat1);

		ShrubberyCreationForm Form3("42");
		RobotomyRequestForm Form4("Heilbronn");
		PresidentialPardonForm Form5("CEO");

		Bureaucrat1.signForm(Form3);
		Form3.execute(Bureaucrat1);
		
		Bureaucrat1.signForm(Form4);
		Form4.execute(Bureaucrat1);
		
		Form5.execute(Bureaucrat1);

		std::cout << Form3 << std::endl;
		std::cout << Form4 << std::endl;
		std::cout << Form5 << std::endl;

		// std::cout << Bureaucrat1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
