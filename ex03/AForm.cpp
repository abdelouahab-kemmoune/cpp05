/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:44 by akemmoun          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:46 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int grade_sign, const int grade_exec) : _name(name),
                                                                                _signed(false),
                                                                                _grade_sign(grade_sign),
                                                                                _grade_exec(grade_exec) {
    if (grade_exec < 1 || grade_sign < 1)
        throw AForm::GradeTooHighException();
    if (grade_exec > 150 || grade_sign > 150)
        throw AForm::GradeTooLowException();                
}

AForm::AForm(const AForm &other) : _name(other._name),
                                _signed(false),
                                _grade_sign(other._grade_sign),
                                _grade_exec(other._grade_exec) {
    if (other._grade_exec < 1 || other._grade_sign < 1)
        throw AForm::GradeTooHighException();
    if (other._grade_exec > 150 || other._grade_sign > 150)
        throw AForm::GradeTooLowException(); 
    *this = other;
}

AForm  &AForm::operator=(const AForm &other) {
    if (this != &other)
    {
        if (other._grade_exec < 1 || other._grade_sign < 1)
            throw AForm::GradeTooHighException();
        if (other._grade_exec > 150 || other._grade_sign > 150)
            throw AForm::GradeTooLowException();
    }
    return (*this);
}
 
const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const std::string &AForm::getName() const {
    return _name;
}

bool  AForm::getSign() const {
    return _signed;
}

int AForm::getGrade_sign() const {
    return _grade_sign;
}

int AForm::getGrade_exec() const {
    return _grade_exec;
}

void AForm::beSigned(const Bureaucrat &slave) {
    if (slave.getGrade() > _grade_sign)
        throw AForm::GradeTooLowException();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& b) {
    // std::cout << b << endl;
    // out << b.getName() << ", AForm grade " << b.getGrade() << ".";
    // return out;
    out << "AForm " << b.getName() << " | signed: ";
	if (b.getSign() == true)
		out << "yes";
	else
		out << "no";
	out << " | grade to sign: " << b.getGrade_sign();
	out << " | grade to execute: " << b.getGrade_exec();

	return (out);
}

AForm::~AForm() {
}
