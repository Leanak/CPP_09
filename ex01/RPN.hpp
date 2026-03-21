/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:54:32 by lenakach          #+#    #+#             */
/*   Updated: 2026/03/21 19:48:09 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <stack>

void	printStack(std::stack<int> copy);

class rpnStack
{
  private:
	std::stack<int> pile;

  public:
	int getSize(void) const;
	void printprint(void);
	void doOperation(char op);
	void pushToStack(std::string line);
	rpnStack &operator=(const rpnStack & other);
	rpnStack(const rpnStack &other);
	rpnStack(void);
	~rpnStack(void);
};