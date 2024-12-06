/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:48:29 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 13:09:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &i);