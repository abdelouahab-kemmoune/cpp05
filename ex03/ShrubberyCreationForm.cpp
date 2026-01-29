/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137) {
    target_shrubbery = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137) {
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
    {
        target_shrubbery = other.target_shrubbery;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSign() && executor.getGrade() > getGrade_exec())
        throw AForm::GradeTooLowException();
    else
    {
        std::string tmp;
        tmp = target_shrubbery + "_shrubbery";
        std::ofstream MyFile(tmp.c_str());
        int	i = 0;

	    while (i < 5)
	    {
	    	MyFile << "   /\\    \n";
	    	MyFile << "  /**\\   \n";
	    	MyFile << " /****\\  \n";
	    	MyFile << "   ||    \n";

	    	MyFile << std::endl;
	    	i++;
	    }
    }
}
