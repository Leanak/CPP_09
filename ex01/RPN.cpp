/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:26 by lenakach          #+#    #+#             */
/*   Updated: 2026/02/23 18:02:36 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void rpnStack::printprint(void)
{
	printStack(this->pile);
}

void rpnStack::pushToStack(std::string line)
{
	int	valeur = line[0] - '0';
	this->pile.push(valeur);
}

rpnStack::~rpnStack(void)
{
}

rpnStack::rpnStack(void)
{
}