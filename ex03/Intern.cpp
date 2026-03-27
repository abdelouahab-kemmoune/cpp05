/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    return (*this);
}

Intern::~Intern() {
}

AForm* create_ShrubberyCreationForm(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

AForm* create_RobotomyRequestForm(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

AForm* create_PresidentialPardonForm(const std::string &target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string &_form_name, const std::string &_form_target)
{
    std::string	shrubbery_name = "shrubbery creation" ;
	std::string	robotomy_name = "robotomy request";
	std::string	pardon_name = "presidential pardon";

    std::string call[3] = {shrubbery_name, robotomy_name, pardon_name};
    AForm *(*creators[3])(const std::string &) = {
    create_ShrubberyCreationForm, create_RobotomyRequestForm, create_PresidentialPardonForm};

    int i = 0;
    while (i < 3)
    {
        if (_form_name == call[i]) {
            std::cout << "Intern creates " << _form_name << "\n";
            return (creators[i](_form_target));
        }
        i++;
    }
    std::cout << "Intern not created\n";
    return (NULL);
}
