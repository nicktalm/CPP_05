/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:59:23 by ntalmon           #+#    #+#             */
/*   Updated: 2024/11/27 12:44:45 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Nick", 140);
		Bureaucrat bureaucrat2("Luca", 9);
		std::cout << bureaucrat << std::endl;
		std::cout << bureaucrat2 << std::endl;
		bureaucrat.decrementGrade();
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
