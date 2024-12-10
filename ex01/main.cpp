/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:59:23 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/10 15:17:13 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Bureaucrat1("Nick", 1);
		Bureaucrat Bureaucrat2("Luca", 120);

		Form Form1("important", 20, 10);
		Form Form2("not important", 140, 130);

		std::cout << Bureaucrat1 << std::endl;
		std::cout << Bureaucrat2 << std::endl;

		Bureaucrat1.signForm(Form1);
		Bureaucrat2.signForm(Form1);
		Bureaucrat2.signForm(Form2);
		
		std::cout << Form1 << std::endl;
		std::cout << Form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
