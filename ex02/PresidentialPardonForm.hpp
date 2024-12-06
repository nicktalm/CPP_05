/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:55:58 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 13:00:29 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const & copy);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		void execute (Bureaucrat const & executor) const;
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &i);