/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:51:36 by lenakach          #+#    #+#             */
/*   Updated: 2026/02/23 18:08:17 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	printStack(std::stack<int> copy)
{
	while (!copy.empty())
	{
		std::cout << copy.top() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}

bool	isoperateur(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool	readToken(std::string arg, rpnStack &calcul)
{
	size_t	i;

	i = 0;
	while (isspace(arg[i]) && i < arg.length())
		i++;
	while (i < arg.length())
	{
		std::string res;
		while (isspace(arg[i]) && i < arg.length())
			i++;
		while (!isspace(arg[i]) && i < arg.length())
		{
			res += arg[i];
			i++;
		}
		if (res.length() == 1 && isdigit(res[0]))
			calcul.pushToStack(res);
		else if (res.length() == 1 && isoperateur(res[0]))
			std::cout << "OPERATEUR" << std::endl;
		else
			return false ;
		std::cout << "Mon res: " << res << std::endl;
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	rpnStack calcul;
	if (ac != 2)
	{
		std::cout << "Not enough arguments" << std::endl;
		return (1);
	}
	if (!readToken(av[1], calcul))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	calcul.printprint();
	return (0);
}