/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:29:36 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 13:16:01 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & copy);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &i);