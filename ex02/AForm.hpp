/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>

// #include "Bureaucrat.hpp"
class   Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _grade_sign;
    const int _grade_exec;
public:
    AForm(const std::string name, const int grade_sign, const int grade_exec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    virtual ~AForm();
    
    void beSigned(const Bureaucrat &slave);

    const std::string &getName() const;
    bool  getSign() const;
    int getGrade_sign() const;
    int getGrade_exec() const;
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };

    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& b);

# endif