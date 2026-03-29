/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    if (other._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (other._grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
    {
        if (other._grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (other._grade > 150)
            throw Bureaucrat::GradeTooLowException();
        _grade = other._grade;
    }
    return (*this);
}
 
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::increment() {
    _grade--;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement() {
    _grade++;
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    // std::cout << b << endl;
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

Bureaucrat::~Bureaucrat() {
}
