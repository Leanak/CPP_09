/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:54:32 by lenakach          #+#    #+#             */
/*   Updated: 2026/02/23 17:54:23 by lenakach         ###   ########.fr       */
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
	void printprint(void);
	void pushToStack(std::string line);
	rpnStack(void);
	~rpnStack(void);
};