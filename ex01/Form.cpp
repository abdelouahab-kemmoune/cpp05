/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int grade_sign, const int grade_exec) : _name(name),
                                                                                _signed(false),
                                                                                _grade_sign(grade_sign),
                                                                                _grade_exec(grade_exec) {
    if (grade_exec < 1 || grade_sign < 1)
        throw Form::GradeTooHighException();
    if (grade_exec > 150 || grade_sign > 150)
        throw Form::GradeTooLowException();                
}

Form::Form(const Form &other) : _name(other._name),
                                _signed(false),
                                _grade_sign(other._grade_sign),
                                _grade_exec(other._grade_exec) {
    if (other._grade_exec < 1 || other._grade_sign < 1)
        throw Form::GradeTooHighException();
    if (other._grade_exec > 150 || other._grade_sign > 150)
        throw Form::GradeTooLowException(); 
    *this = other;
}

Form  &Form::operator=(const Form &other) {
    if (this != &other)
    {
        if (other._grade_exec < 1 || other._grade_sign < 1)
            throw Form::GradeTooHighException();
        if (other._grade_exec > 150 || other._grade_sign > 150)
            throw Form::GradeTooLowException();
    }
    return (*this);
}
 
const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const std::string &Form::getName() const {
    return _name;
}

bool  Form::getSign() const {
    return _signed;
}

int Form::getGrade_sign() const {
    return _grade_sign;
}

int Form::getGrade_exec() const {
    return _grade_exec;
}

void Form::beSigned(const Bureaucrat &slave) {
    if (slave.getGrade() > _grade_sign)
        throw Form::GradeTooLowException();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& b) {
    // std::cout << b << endl;
    // out << b.getName() << ", Form grade " << b.getGrade() << ".";
    // return out;
    out << "Form " << b.getName() << " | signed: ";
	if (b.getSign() == true)
		out << "yes";
	else
		out << "no";
	out << " | grade to sign: " << b.getGrade_sign();
	out << " | grade to execute: " << b.getGrade_exec();

	return (out);
}

Form::~Form() {
}
