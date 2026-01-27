/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"
class   Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _grade_sign;
    const int _grade_exec;
public:
    Form(const std::string name, const int grade_sign, const int grade_exec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
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
};

std::ostream& operator<<(std::ostream& out, const Form& b);

# endif