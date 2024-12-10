/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:59:23 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/10 12:57:17 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Nick", 120);
		Bureaucrat bureaucrat2("Luca", 9);
		Bureaucrat bureaucrat3;
		std::cout << bureaucrat << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		bureaucrat.decrementGrade();
		bureaucrat2.decrementGrade();
		bureaucrat3.incrementGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		bureaucrat.incrementGrade();
		bureaucrat2.decrementGrade();
		bureaucrat3.incrementGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
