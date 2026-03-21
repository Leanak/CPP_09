/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:26 by lenakach          #+#    #+#             */
/*   Updated: 2026/03/21 19:48:27 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int rpnStack::getSize(void) const
{
	return (this->pile.size());
}

void rpnStack::doOperation(char op)
{
	if (pile.size() < 2)
		throw std::runtime_error("Error");

	int b = pile.top(); 
	pile.pop();
	int a = pile.top();
	pile.pop();

	int result;

	switch (op)
	{
		case '+':
			result = a + b;
			break ;
		case '-':
			result = a - b;
			break ;
		case '*':
			result = a * b;
			break ;
		case '/':
		{
			if (b == 0)
				throw std::runtime_error("Division by 0");
			result = a / b;
			break ;
		}
		default :
			throw std::runtime_error("Unknown operator");
	}
	pile.push(result);
}

void rpnStack::printprint(void)
{
	printStack(this->pile);
}

void rpnStack::pushToStack(std::string line)
{
	int	valeur = line[0] - '0';
	this->pile.push(valeur);
}

rpnStack &rpnStack::operator=(const rpnStack & other)
{
	if (this != &other)
	{
		this->pile = other.pile;
	}
	return (*this);
}

rpnStack::rpnStack(const rpnStack & other)
{
	this->pile = other.pile;
}

rpnStack::~rpnStack(void)
{
}

rpnStack::rpnStack(void)
{
}