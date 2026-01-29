/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    //
    try
    {
        srand(time(NULL));
        Bureaucrat slave("Ismail", 200);
        ShrubberyCreationForm   tree("Home");
        RobotomyRequestForm     robot("kouzina");
        PresidentialPardonForm  pardon("space");
        slave.signForm(tree);

        slave.executeForm(tree);
        slave.executeForm(robot);
        slave.executeForm(pardon);

    }
    catch ( std::exception &e )
    {
        std::cerr << e.what() << "\n";
    }

}
